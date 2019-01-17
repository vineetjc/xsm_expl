/*Declarations*/

%{
      #include <stdio.h>
      #include <string.h>
      #define YYSTYPE char *
%}

%token DIGIT NEWLINE

%%

/*Rules*/

start : expr NEWLINE  {
                        printf("\nComplete\n");
                        exit(1);
                      }
  ;

expr:  expr '+' expr        {printf("+ ");}
  | expr '-' expr     {printf("- ");}
  | '(' expr ')'
  | DIGIT             {printf("%s ",$1);}
  ;

%%

//Auxiliary functions

void yyerror(char const *s)
{
    printf("yyerror  %s\n",s);
    return ;
}
int main()
{
  yyparse();
  return 1;
}
