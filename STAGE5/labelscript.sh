#!/bin/sh
lex label2.l
gcc lex.yy.c
./a.out
