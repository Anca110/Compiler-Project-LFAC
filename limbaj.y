%code requires {
  #include <string>
  using namespace std;

  // doar declaratie, e suficient pentru pointer in %union
  struct ASTNode;
}


%{
#include <iostream>
#include <vector>
#include <fstream>
#include "SymTable.h"
#include "AST.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

void yyerror(const char* s);

SymTable* globalScope = nullptr;
SymTable* current = nullptr;
std::vector<SymTable*> allTables;
std::vector<std::string> tempParams;
std::vector<std::string> tempArgs;

int errorCount=0;

SymTable* findClassTable(std::string className)
{
  std::string wanted = "class " + className;

  for (int i = 0; i < (int)allTables.size(); i++)
  {
    if (allTables[i]->getName() == wanted)
      return allTables[i];
  }

  return nullptr;
}


Value::Type toValueType(std::string t)
{
  if (t == "int") return Value::INT;
  if (t == "float") return Value::FLOAT;
  if (t == "bool") return Value::BOOL;
  if (t == "string") return Value::STRING;
  return Value::UNDEF;
}

%}

%union {
  bool bval;
  int ival;
  float fval;
  std::string* Str;
  ASTNode* node;
}

%token <Str> TYPE
%token <bval> BOOL
%token CLASS FUNCTION

%token <Str> ID
%token <ival> INTVAL
%token <fval> FLOATVAL
%token <Str> STRVAL

%token PRINT

%token ASSIGN
%token PLUS
%token MINUS
%token MULT
%token DIV
%token MOD

%token IF
%token ELSE
%token WHILE
%token FOR

%token BREAK
%token CONTINUE
%token RETURN

%token EQ
%token NEQ
%token LT
%token GT
%token LE
%token GE

%token AND
%token OR
%token NOT

%token MAIN

%token LPAREN RPAREN LBRACE RBRACE COMMA SEMICOLON DOT

%start progr

%type <Str> expr assign_rhs
%type <node> expr_ast

%left PLUS MINUS
%left MULT DIV MOD
%left OR
%left AND
%right NOT
%nonassoc EQ NEQ LT GT LE GE

%%

progr
  : global_list main_section
  ;

global_list
  :
  | global_list global_def
  ;

global_def 
  : class_def
  | function_def
  | global_var_def
  ;

global_var_def
  : TYPE ID SEMICOLON
    {
      if (globalScope->existsLocal(*$2))
      {
        std::cerr << "Semantic error at line " << yylineno
                  << ": '" << *$2 << "' declared twice in global scope\n";
        errorCount++;
      }
      else
      {
        globalScope->addVariable(*$2, *$1);
      }

      delete $1;
      delete $2;
    }
  | ID ID SEMICOLON
    {

      if (globalScope->existsLocal(*$2))
      {
        std::cerr << "Semantic error at line " << yylineno
                  << ": '" << *$2 << "' declared twice in global scope\n";
        errorCount++;
      }
      else
      {
        globalScope->addVariable(*$2, *$1);
      }
      delete $1;
      delete $2;
    }
  ;

/*DEFINTIII DE CLASE SI FUNCTII*/

class_def
  : CLASS ID
    {

      globalScope->addClass(*$2);

      SymTable* cls = new SymTable(std::string("class ") + *$2, current);

      allTables.push_back(cls);

      current = cls;
    }
    LBRACE class_body RBRACE
    {

      current = current->getParent();

      delete $2;
    }
  ;

class_body
  :
  | class_body class_field
  | class_body function_def
  ;

class_field
  : TYPE ID SEMICOLON
    {
      current->addVariable(*$2, *$1);
      delete $1;
      delete $2;
    }
  ;

function_def
  : FUNCTION ID LPAREN param_list_opt RPAREN
    {
      globalScope->addFunction(*$2, "unknown", tempParams);

      SymTable* fn = new SymTable(std::string("function ") + *$2, current);
      allTables.push_back(fn);

      current = fn;

      for (const auto& p : tempParams)
      {
        size_t pos = p.find(' ');
        std::string t = p.substr(0, pos);
        std::string n = p.substr(pos + 1);
        current->addVariable(n, t);
      }
      tempParams.clear();
    }
    LBRACE stmt_list RBRACE
    {
      current = current->getParent();
      delete $2;
    }
  ;

param_list_opt
  :
  | param_list
  ;

param_list
  : TYPE ID
    {
      tempParams.push_back(*$1 + std::string(" ") + *$2);
      delete $1;
      delete $2;
    }
  | param_list COMMA TYPE ID
    {
      tempParams.push_back(*$3 + std::string(" ") + *$4);
      delete $3;
      delete $4;
    }
  ;

/*MAIN SI LISTA DE INSTRUCTIUNI*/
main_section
  : MAIN LBRACE main_stmt_list RBRACE
  ;
main_stmt_list
  : 
  | main_stmt_list main_stmt
  ;
main_stmt
  : ID ASSIGN expr_ast SEMICOLON
    {
      SymTable::Symbol* s = current->lookup(*$1);

      if (s == nullptr)
      {
        std::cerr << "Semantic error at line " << yylineno
                  << ": variable '" << *$1 << "' used but not declared\n";
        errorCount++;
      }
      else
      {
        Value::Type leftT = toValueType(s->type);

        if ($3->exprType == Value::UNDEF)
        {
          std::cerr << "Semantic error at line " << yylineno
                    << ": operands have different types in expression\n";
          errorCount++;
        }
        else if (leftT != $3->exprType)
        {
          std::cerr << "Semantic error at line " << yylineno
                    << ": assignment type mismatch for '" << *$1
                    << "': left is '" << s->type
                    << "' but right has different type\n";
          errorCount++;
        }
        else
        {
          ASTNode* idNode = ASTNode::makeId(*$1, leftT);
          ASTNode* asg = ASTNode::makeAssign(idNode, $3);
          asg->eval(current);
        }
      }

      delete $1;
    }
  | field_access SEMICOLON
  | field_access ASSIGN assign_rhs SEMICOLON
  | method_call SEMICOLON
  | function_call SEMICOLON
  | print_stmt
  | if_stmt
  | while_stmt
  | for_stmt
  | BREAK SEMICOLON
  | CONTINUE SEMICOLON
  | RETURN return_opt SEMICOLON
  | block
  ;

stmt_list
  :
  | stmt_list stmt
  ;

/*INSTRUCTIUNI(STMT)*/
stmt
  : simple_stmt
  | ID ASSIGN assign_rhs SEMICOLON
  {
    SymTable::Symbol* s = current->lookup(*$1);

    if (s == nullptr)
    {
      std::cerr << "Semantic error at line " << yylineno
                << ": variable '" << *$1 << "' used but not declared\n";
      errorCount++;
    }
    else
    {
      if (s->type != *$3)
      {
        std::cerr << "Semantic error at line " << yylineno
                  << ": assignment type mismatch for '" << *$1
                  << "': left is '" << s->type
                  << "' but right is '" << *$3 << "'\n";
        errorCount++;
      }
    }

    delete $1;
    delete $3;
  }
  | field_access SEMICOLON
  | field_access ASSIGN assign_rhs SEMICOLON 
  | method_call SEMICOLON
  | function_call SEMICOLON
  | print_stmt
  | if_stmt
  | while_stmt
  | for_stmt
  | BREAK SEMICOLON
  | CONTINUE SEMICOLON
  | RETURN return_opt SEMICOLON
  | block
  ;

simple_stmt
  : TYPE ID SEMICOLON
    {
      if (current->existsLocal(*$2))
      {
        
        std::cerr << "Semantic error at line " << yylineno
                  << ": '" << *$2 << "' declared twice in scope '" 
                  << current->getName() << "'\n";

        errorCount++;
      }
      else
      {
        current->addVariable(*$2, *$1);
      }

      delete $1;
      delete $2;
    }
  ;

/*CONTROL FLOW*/
if_stmt
  : IF LPAREN bexpr RPAREN stmt_no_else
  | IF LPAREN bexpr RPAREN stmt_no_else ELSE stmt
  ;

stmt_no_else
  : simple_stmt
  | block
  | IF LPAREN bexpr RPAREN stmt_no_else ELSE stmt_no_else
  ;


while_stmt
  : WHILE LPAREN bexpr RPAREN stmt
  ;

for_stmt
  : FOR LPAREN for_init SEMICOLON bexpr SEMICOLON for_step RPAREN stmt
  ;

for_init
  : ID ASSIGN assign_rhs   { delete $1; }
  ;

for_step
  : ID ASSIGN assign_rhs   { delete $1; }
  ;

/*ACCES CAMPURI SI APELURI*/
field_access
  : ID DOT ID
    {

      SymTable::Symbol* obj = current->lookup(*$1);

      if (obj == nullptr)
      {
        std::cerr << "Semantic error at line " << yylineno
                  << ": object '" << *$1 << "' not declared\n";
        errorCount++;
      }
      else
      {
        SymTable* cls = findClassTable(obj->type);

        if (cls == nullptr)
        {
          std::cerr << "Semantic error at line " << yylineno
                    << ": class '" << obj->type << "' not found for object '" << *$1 << "'\n";
          errorCount++;
        }
        else
        {
          if (cls->lookupLocal(*$3) == nullptr)
          {
            std::cerr << "Semantic error at line " << yylineno
                      << ": field '" << *$3 << "' not found in class '" << obj->type << "'\n";
            errorCount++;
          }
        }
      }

      delete $1;
      delete $3;
    }
  ;

method_call
  : ID DOT ID LPAREN arg_list_opt RPAREN
    {
      SymTable::Symbol* obj = current->lookup(*$1);

      if (obj == nullptr)
      {
        std::cerr << "Semantic error at line " << yylineno
                  << ": object '" << *$1 << "' not declared\n";
        errorCount++;
      }
      else
      {
        SymTable* cls = findClassTable(obj->type);

        if (cls == nullptr)
        {
          std::cerr << "Semantic error at line " << yylineno
                    << ": class '" << obj->type << "' not found for object '" << *$1 << "'\n";
          errorCount++;
        }
        else
        {
          SymTable::Symbol* m = cls->lookupLocal(*$3);

          if (m == nullptr)
          {
            std::cerr << "Semantic error at line " << yylineno
                      << ": method '" << *$3 << "' not found in class '" << obj->type << "'\n";
            errorCount++;
          }
          else
          {
            if (m->kind != SymTable::Kind::Function)
            {
              std::cerr << "Semantic error at line " << yylineno
                        << ": '" << *$3 << "' is not a method in class '" << obj->type << "'\n";
              errorCount++;
            }
          }
        }
      }

      tempArgs.clear();

      delete $1;
      delete $3;
    }
  ;

function_call
  : ID LPAREN arg_list_opt RPAREN
    {
      SymTable::Symbol* fn = globalScope->lookupLocal(*$1);

      if (fn == nullptr || fn->kind != SymTable::Kind::Function)
      {
        std::cerr << "Semantic error at line " << yylineno
                  << ": function '" << *$1 << "' not declared\n";
        errorCount++;
      }
      else
      {
        if ((int)fn->params.size() != (int)tempArgs.size())
        {
          std::cerr << "Semantic error at line " << yylineno
                    << ": function '" << *$1 << "' called with "
                    << tempArgs.size() << " args but expects "
                    << fn->params.size() << "\n";
          errorCount++;
        }
        else
        {
          for (int i = 0; i < (int)fn->params.size(); i++)
          {
            std::string p = fn->params[i];
            size_t pos = p.find(' ');
            std::string expected = p.substr(0, pos);

            if (expected != tempArgs[i] && tempArgs[i] != "undef")
            {
              std::cerr << "Semantic error at line " << yylineno
                        << ": in call of '" << *$1 << "', argument " << (i+1)
                        << " has type '" << tempArgs[i]
                        << "' but expected '" << expected << "'\n";
              errorCount++;
            }
          }
        }
      }

      delete $1;
    }
  ;

/*PRINT SI EXPRESII*/
print_stmt
  : PRINT LPAREN expr_ast RPAREN SEMICOLON
    {
      ASTNode* p = ASTNode::makePrint($3);
      p->eval(current);
    }
  ;

assign_rhs
  : expr
    { $$ = $1; }
  | BOOL
    { $$ = new std::string("bool"); }
  | STRVAL
    { $$ = new std::string("string"); delete $1; }
  ;

expr_ast
  : INTVAL
    { $$ = ASTNode::makeInt($1); }
  | FLOATVAL
    { $$ = ASTNode::makeFloat($1); }
  | BOOL
    { $$ = ASTNode::makeBool($1); }
  | STRVAL
    { $$ = ASTNode::makeString(*$1); delete $1; }
  | ID
    {
      SymTable::Symbol* s = current->lookup(*$1);
      Value::Type vt = Value::UNDEF;

      if (s != nullptr)
        vt = toValueType(s->type);

      $$ = ASTNode::makeId(*$1, vt);
      delete $1;
    }
  | field_access
    {
      $$ = ASTNode::makeOther(Value::UNDEF);
    }
  | function_call
    {
      $$ = ASTNode::makeOther(Value::UNDEF);
    }
  | method_call
    {
      $$ = ASTNode::makeOther(Value::UNDEF);
    }
  | expr_ast PLUS expr_ast
{
  Value::Type t;

  if ($1->exprType == $3->exprType)
    t = $1->exprType;
  else
    t = Value::UNDEF;

  $$ = ASTNode::makeBinary(ASTNode::PLUS_NODE, $1, $3, t);
}
| expr_ast MINUS expr_ast
{
  Value::Type t;

  if ($1->exprType == $3->exprType)
    t = $1->exprType;
  else
    t = Value::UNDEF;

  $$ = ASTNode::makeBinary(ASTNode::MINUS_NODE, $1, $3, t);
}
| expr_ast MULT expr_ast
{
  Value::Type t;

  if ($1->exprType == $3->exprType)
    t = $1->exprType;
  else
    t = Value::UNDEF;

  $$ = ASTNode::makeBinary(ASTNode::MULT_NODE, $1, $3, t);
}
| expr_ast DIV expr_ast
{
  Value::Type t;

  if ($1->exprType == $3->exprType)
    t = $1->exprType;
  else
    t = Value::UNDEF;

  $$ = ASTNode::makeBinary(ASTNode::DIV_NODE, $1, $3, t);
}
  | LPAREN expr_ast RPAREN
    { $$ = $2; }
  ;

expr
  : INTVAL
    { $$ = new std::string("int"); }
  | FLOATVAL
    { $$ = new std::string("float"); }
  | ID
    {
      SymTable::Symbol* s = current->lookup(*$1);
      if (s == nullptr)
      {
        std::cerr << "Semantic error at line " << yylineno
                  << ": variable '" << *$1 << "' used but not declared\n";
        errorCount++;
        $$ = new std::string("undef");
      }
      else
      {
        $$ = new std::string(s->type);
      }

      delete $1;
    }
  | field_access
    {
      $$ = new std::string("undef");
    }
  | expr PLUS expr
  {

    if (*$1 != *$3)
    {
      std::cerr << "Semantic error at line " << yylineno
                << ": operands have different types for '+': '" << *$1
                << "' and '" << *$3 << "'\n";
      errorCount++;
      $$ = new std::string("undef");
    }
    else
    {
      $$ = new std::string(*$1);
    }

    delete $1;
    delete $3;
  }
  | expr MINUS expr
    { delete $1; delete $3; $$ = new std::string("undef"); }
  | expr MULT expr
    { delete $1; delete $3; $$ = new std::string("undef"); }
  | expr DIV expr
    { delete $1; delete $3; $$ = new std::string("undef"); }
  | expr MOD expr
    { delete $1; delete $3; $$ = new std::string("undef"); }
  | LPAREN expr RPAREN
    { $$ = $2; }
  ;

bexpr
  : BOOL
  | LPAREN bexpr RPAREN
  | NOT bexpr
  | bexpr AND bexpr
  | bexpr OR bexpr
  | expr EQ expr
  | expr NEQ expr
  | expr LT expr
  | expr GT expr
  | expr LE expr
  | expr GE expr
  ;

arg_list_opt
  :
    {
      tempArgs.clear();
    }
  | 
    {
      tempArgs.clear();
    }
    arg_list
  ;

arg_list
  : assign_rhs
    {
      tempArgs.push_back(*$1);
      delete $1;
    }
  | arg_list COMMA assign_rhs
    {
      tempArgs.push_back(*$3);
      delete $3;
    }
  ;

/*BLOCURI SI RETURN*/
return_opt
  :
  | assign_rhs
  ;
block
  : LBRACE stmt_list RBRACE
  ;

%%


void yyerror(const char* s) {
  std::cerr << "error: " << s << " at line: " << yylineno << "\n";
}

int main(int argc, char** argv) 
{
  if (argc > 1) yyin = fopen(argv[1], "r");
  globalScope = new SymTable("global", nullptr);
  current = globalScope;
  allTables.push_back(globalScope);

  yyparse();

  std::ofstream fout("tables.txt");

  for (int i = 0; i < (int)allTables.size(); i++)
  {
    allTables[i]->print(fout);
  }

  fout.close();

  std::cout << "Parsed OK (for current .l tokens).\n";
  return 0;
}