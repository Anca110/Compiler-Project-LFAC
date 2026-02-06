#pragma once
#include <string>
#include <iostream>
#include "Value.h"
#include "SymTable.h"


struct ASTNode
{
  enum NodeKind
  {
    INT_NODE,
    FLOAT_NODE,
    BOOL_NODE,
    STRING_NODE,
    ID_NODE,
    OTHER_NODE,

    PLUS_NODE,
    MINUS_NODE,
    MULT_NODE,
    DIV_NODE,

    ASSIGN_NODE,
    PRINT_NODE
  };

  NodeKind kind;

  Value::Type exprType;

  int ival;
  float fval;
  bool bval;
  std::string sval;
  std::string name;  

  ASTNode* left;
  ASTNode* right;

  ASTNode()
  {
    kind = OTHER_NODE;
    exprType = Value::UNDEF;

    ival = 0;
    fval = 0.0f;
    bval = false;
    sval = "";
    name = "";

    left = nullptr;
    right = nullptr;
  }


  static ASTNode* makeInt(int v)
  {
    ASTNode* n = new ASTNode();
    n->kind = INT_NODE;
    n->exprType = Value::INT;
    n->ival = v;
    return n;
  }

  static ASTNode* makeFloat(float v)
  {
    ASTNode* n = new ASTNode();
    n->kind = FLOAT_NODE;
    n->exprType = Value::FLOAT;
    n->fval = v;
    return n;
  }

  static ASTNode* makeBool(bool v)
  {
    ASTNode* n = new ASTNode();
    n->kind = BOOL_NODE;
    n->exprType = Value::BOOL;
    n->bval = v;
    return n;
  }

  static ASTNode* makeString(std::string v)
  {
    ASTNode* n = new ASTNode();
    n->kind = STRING_NODE;
    n->exprType = Value::STRING;
    n->sval = v;
    return n;
  }

  static ASTNode* makeId(std::string idName, Value::Type t)
  {
    ASTNode* n = new ASTNode();
    n->kind = ID_NODE;
    n->exprType = t;  
    n->name = idName;
    return n;
  }

  static ASTNode* makeOther(Value::Type t)
  {
    ASTNode* n = new ASTNode();
    n->kind = OTHER_NODE;
    n->exprType = t;
    return n;
  }

  static ASTNode* makeBinary(NodeKind k, ASTNode* l, ASTNode* r, Value::Type t)
  {
    ASTNode* n = new ASTNode();
    n->kind = k;
    n->left = l;
    n->right = r;
    n->exprType = t;
    return n;
  }

  static ASTNode* makeAssign(ASTNode* idNode, ASTNode* exprNode)
  {
    ASTNode* n = new ASTNode();
    n->kind = ASSIGN_NODE;
    n->left = idNode;
    n->right = exprNode;
    n->exprType = idNode->exprType;
    return n;
  }

  static ASTNode* makePrint(ASTNode* exprNode)
  {
    ASTNode* n = new ASTNode();
    n->kind = PRINT_NODE;
    n->left = exprNode;
    n->right = nullptr;
    n->exprType = exprNode->exprType;
    return n;
  }

  Value eval(SymTable* scope)
  {
    if (kind == INT_NODE) 
      return Value(ival);
    if (kind == FLOAT_NODE) 
      return Value(fval);
    if (kind == BOOL_NODE) 
      return Value(bval);
    if (kind == STRING_NODE) 
      return Value(sval);

    if (kind == OTHER_NODE)
    {
      return Value::defaultFor(exprType);
    }

    if (kind == ID_NODE)
    {
      SymTable::Symbol* sym = scope->lookup(name);
      if (sym == nullptr)
        return Value();

      if (sym->type == "int")
      {
        if (sym->value == "") 
          return Value(0);
        if (sym->value == "undef") 
          return Value(0);
        return Value(std::stoi(sym->value));
      }

      if (sym->type == "float")
      {
        if (sym->value == "") 
          return Value(0.0f);
        if (sym->value == "undef") 
          return Value(0.0f);
        return Value((float)std::stof(sym->value));

      }

      if (sym->type == "bool")
      {
        if (sym->value == "") 
          return Value(false);
        if (sym->value == "true") 
          return Value(true);
        return Value(false);
      }

      if (sym->type == "string")
      {
        if (sym->value == "") 
          return Value(std::string(""));
        return Value(sym->value);
      }

      return Value();
    }

    if (kind == PLUS_NODE || kind == MINUS_NODE || kind == MULT_NODE || kind == DIV_NODE)
    {
      Value L = left->eval(scope);
      Value R = right->eval(scope);

      if (L.type != R.type)
        return Value();


      if (L.type == Value::INT)
      {
        int res = 0;

        if (kind == PLUS_NODE) 
          res = L.i + R.i;
        else if (kind == MINUS_NODE) 
          res = L.i - R.i;
        else if (kind == MULT_NODE) 
          res = L.i * R.i;
        else if (kind == DIV_NODE)
        {
          if (R.i == 0) 
            res = 0;
          else 
            res = L.i / R.i;
        }

        return Value(res);
      }

      
      if (L.type == Value::FLOAT)
      {
        float res = 0.0f;

        if (kind == PLUS_NODE) 
          res = L.f + R.f;
        else if (kind == MINUS_NODE) 
          res = L.f - R.f;
        else if (kind == MULT_NODE) 
          res = L.f * R.f;
        else if (kind == DIV_NODE)
        {
          if (R.f == 0.0f) 
            res = 0.0f;
          else 
            res = L.f / R.f;
        }

        return Value(res);
      }

      return Value();
    }

    if (kind == ASSIGN_NODE)
    {
      Value rhs = right->eval(scope);

      SymTable::Symbol* sym = scope->lookup(left->name);
      if (sym == nullptr) 
        return Value();

      sym->value = rhs.toString();
      return rhs;
    }

    if (kind == PRINT_NODE)
    {
      Value v = left->eval(scope);
      std::cout << v.toString() << "\n";
      return v;
    }

    return Value();
  }
};
