/*Declarations section starts here*/

/*Declarations section 1: Auxiliary Declarations start here*/
%{
	#include<stdio.h>
  int flag = 0;
%}

/*Auxiliary declarations end & Declarations section 2: Regular definitions start here*/

/*Declarations section ends here and Rules below*/
%%

[0-9]*[0|2|4|6|8] 	printf("evennumber");
[0-9]*[1|3|5|7|9] 	printf("oddnumber");

%%

//Auxiliary Functions here

int yywrap()
{
    if(flag==0)
    {
      FILE *newfile_pointer;
      char *file2="input_file_2.l";
      newfile_pointer = fopen("input_file1.l","r");
      yyin = newfile_pointer;
      flag = 1;
      return 0;
    }
    else
      return 1;
}

int main()
{
  yylex();
  return 1;
}
