/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LIMBAJ_TAB_H_INCLUDED
# define YY_YY_LIMBAJ_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "limbaj.y"

  #include <string>
  using namespace std;

  // doar declaratie, e suficient pentru pointer in %union
  struct ASTNode;

#line 57 "limbaj.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TYPE = 258,                    /* TYPE  */
    BOOL = 259,                    /* BOOL  */
    CLASS = 260,                   /* CLASS  */
    FUNCTION = 261,                /* FUNCTION  */
    ID = 262,                      /* ID  */
    INTVAL = 263,                  /* INTVAL  */
    FLOATVAL = 264,                /* FLOATVAL  */
    STRVAL = 265,                  /* STRVAL  */
    PRINT = 266,                   /* PRINT  */
    ASSIGN = 267,                  /* ASSIGN  */
    PLUS = 268,                    /* PLUS  */
    MINUS = 269,                   /* MINUS  */
    MULT = 270,                    /* MULT  */
    DIV = 271,                     /* DIV  */
    MOD = 272,                     /* MOD  */
    IF = 273,                      /* IF  */
    ELSE = 274,                    /* ELSE  */
    WHILE = 275,                   /* WHILE  */
    FOR = 276,                     /* FOR  */
    BREAK = 277,                   /* BREAK  */
    CONTINUE = 278,                /* CONTINUE  */
    RETURN = 279,                  /* RETURN  */
    EQ = 280,                      /* EQ  */
    NEQ = 281,                     /* NEQ  */
    LT = 282,                      /* LT  */
    GT = 283,                      /* GT  */
    LE = 284,                      /* LE  */
    GE = 285,                      /* GE  */
    AND = 286,                     /* AND  */
    OR = 287,                      /* OR  */
    NOT = 288,                     /* NOT  */
    MAIN = 289,                    /* MAIN  */
    LPAREN = 290,                  /* LPAREN  */
    RPAREN = 291,                  /* RPAREN  */
    LBRACE = 292,                  /* LBRACE  */
    RBRACE = 293,                  /* RBRACE  */
    COMMA = 294,                   /* COMMA  */
    SEMICOLON = 295,               /* SEMICOLON  */
    DOT = 296                      /* DOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 57 "limbaj.y"

  bool bval;
  int ival;
  float fval;
  std::string* Str;
  ASTNode* node;

#line 123 "limbaj.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LIMBAJ_TAB_H_INCLUDED  */
