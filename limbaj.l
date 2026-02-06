%{
#include <stdio.h>
#include "limbaj.tab.h"
#include <string>
#include <cstdlib>
%}
%option noyywrap

%%

"infiniti"    {yylval.Str = new std::string("int"); return TYPE;}
"ferrari"     {yylval.Str = new std::string("float"); return TYPE;}
"citroen"     {yylval.Str = new std::string("char"); return TYPE;}
"suzuki"      {yylval.Str = new std::string("string"); return TYPE;}

"signal"      {yylval.Str = new std::string("bool"); return TYPE;}
"green"       {yylval.bval=true; return BOOL; }
"red"         {yylval.bval=false; return BOOL; }


"city"     {return CLASS;}


"junction"                { return IF; }
"detour"                  { return ELSE; }
"round"                   { return WHILE; }
"root"                    {return FOR;}

"turnback"                { return RETURN;}

"moveon"                  {return CONTINUE;}
"stop"                    {return BREAK;}

"sign"                    {return PRINT; }

"engine"                  { return MAIN; }
"mini_engine"  { return FUNCTION; }

"same_car"                { return EQ; }
"diff_car"                { return NEQ; }

"under_limit"             {return LT;}
"over_limit"              {return GT;}
"limit_or_less"           { return LE; }     
"limit_or_more"           { return GE; } 

"all_go"                  { return AND; }
"any_go"                  { return OR; }
"not_go"                  {return NOT;}

"<=>"    { return ASSIGN; }

"<+>"    { return PLUS; }
"<->"    { return MINUS; }
"<*>"    { return MULT; }
"</>"    { return DIV; }
"<%>"    { return MOD; }

"("      { return LPAREN; }
")"      { return RPAREN; }

"[["     { return LBRACE; }
"]]"     { return RBRACE; }

";"      { return SEMICOLON; }
","      { return COMMA; }
"."      { return DOT; }



[0-9]+"."[0-9]+      { yylval.fval = atof(yytext); return FLOATVAL; }
[0-9]+               { yylval.ival = atoi(yytext); return INTVAL; }
\"([^\"\\]|\\.)*\"   { yylval.Str = new std::string(yytext); return STRVAL; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.Str = new std::string(yytext); return ID; }

"/*"([^*]|\*+[^*/])*"\*/"   {  }

[ \t]   ;
\n  { yylineno++; }
.   { return yytext[0]; }

%%