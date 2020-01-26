#!/bin/sh
yacc -d t2.y
lex t2.l
gcc lex.yy.c y.tab.c -o t2.exe
echo "gonna run"
./t2.exe < test.txt
