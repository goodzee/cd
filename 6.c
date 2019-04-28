Yacc:

%{
#include<stdio.h>
int flag=1;
%}
%token id num
%left '(' ')'
%left '+' '-'
%left '/' '*'
%nonassoc UMINUS
%%
stmt: expression { printf("\n valid exprn");}
;
expression : '(' expression ')'

| '(' expression {printf("\n Syntax error: Missing right paranthesis");}
| expression '+' expression {printf("\nplus recog!");$$=$1+$3;printf("\n %d",$
$);}
| expression '+' { printf ("\n Syntax error: Right operand is missing ");}
| expression '-' expression {printf("\nminus recog!");$$=$1-$3;printf("\n %d",$
$);}
| expression '-' { printf ("\n Syntax error: Right operand is missing ");}
| expression '*' expression {printf("\nMul recog!");$$=$1*$3;printf("\n %d",$
$);}
| expression '*' { printf ("\n Syntax error: Right operand is missing ");}
| expression '/' expression {printf("\ndivision recog!");if($3==0)
printf("\ndivision cant be done, as divisor is zero.");

else {$$=$1+$3;printf("\n %d",$$);}}
| expression '/' { printf ("\n Syntax error: Right operand is missing ");}
| expression '%' expression
| expression '%' { printf ("\n Syntax error: Right operand is missing ");}
| id
| num
;
%%
main()
{
printf(" Enter an arithmetic expression\n");
yyparse();
}
yyerror()
{
printf(" Invalid arithmetic Expression\n");
exit(1);
}

Lex:
%{
#include "y.tab.h"
#include<stdio.h>
#include<ctype.h>
extern int yylval;
int val;
%}
%%
[a-zA-Z][a-zA-Z0-9]* {printf("\n enter the value of variable
%s:",yytext);scanf("%d",&val);yylval=val;return id;}
[0-9]+[.]?[0-9]* {yylval=atoi(yytext);return num;}
[ \t] ;
\n {return 0;}
. {return yytext[0];}
%%
int yywrap()
{
return 1;
}
