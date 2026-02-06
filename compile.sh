#!/bin/bash

echo "compiling $1"

bison -d $1.y
flex $1.l
g++ lex.yy.c $1.tab.c -o $1
