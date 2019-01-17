%{
/*** Auxiliary declarations section ***/

#include<stdio.h>
#include<stdlib.h>

/* Custom function to print an operator*/
void print_operator(char op);

%}

 /*** YACC Declarations section ***/
%token DIGIT CHAR
%left '+'
%left '*'
%left '-'
%left '/'
%%

/*** Rules Section ***/
start : expr '\n'		{exit(1);}
      | ifst '\n'   {exit(1);}
      | var '\n'    {printf("Found variable"); exit(1);}
      ;

expr: expr '+' expr     {print_operator('+');}
    | expr '*' expr     {print_operator('*');}
    | expr '-' expr     {print_operator("-");}
    | expr '/' expr     {print_operator("/");}
    | '(' expr ')'
    | DIGIT             {printf("NUM%d ", $1);}
    ;

ifst: 'i''f' expr 'r''e''t''u''r''n' expr 'e''l''s''e' 'r''e''t''u''r''n' expr            {printf("Found one");}
    ;

var: var var {printf("VAR");}
   | 'a'
   ;

%%


/*** Auxiliary functions section ***/

void print_operator(char c){
    switch(c){
        case '+'  : printf("PLUS ");
                    break;
        case '*'  : printf("MUL ");
                    break;
        case '-'  : printf("MINUS ");
                    break;
        case '/'  : printf("DIV ");
                    break;
    }
    return;
}

yyerror(char const *s)
{
    printf("yyerror %s",s);
}

yylex(){
    char c;
    c = getchar();
    if(isdigit(c)){
        yylval=(int) c - 48;
        return DIGIT;
    }
    else if(c == ' '){
        yylex();         /*This is to ignore whitespaces in the input*/
    }
    return c;
}

main()
{
	yyparse();
	return 1;
}
