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

Yacc:

%{
#include<stdio.h>
int flag=1;
%}
%token id num
%%
stmt: expression { printf("\n valid logical exprn : evaluated result is %d",$1);}
;
expression : '(' expression ')' { $$=$2;printf("\n value : %d",$$);}
| '(' expression {printf("\n Syntax error: Missing right paranthesis");exit(0);}
| expression '&''&' expression {printf("\nlogical and recog!");$$=(($1)&&($4));printf("\n %d",$
$);}
| expression '&''&' {printf("Syntax error: Right operand is missing ");exit(0);}
| expression '|''|' expression {printf("\nlogical or recog!");$$=($1||$4);printf("\n %d",$$);}
| expression '|''|' {printf("Syntax error: Right operand is missing ");exit(0);}
| '!' expression {printf("\nlogical not recog!");$$=!($2);printf("\n %d",$$);}
| '!' {printf("Syntax error: Right operand is missing ");exit(0);}

| expression '<' expression {printf("\nless than recog!");$$=($1<$3);printf("\n %d",$$);}
| expression '<' { printf ("\n Syntax error: Right operand is missing ");exit(0);}
| expression '>' expression {printf("\ngreater than recog!");$$=($1>$3);printf("\n %d",$$);}
| expression '>' { printf ("\n Syntax error: Right operand is missing ");exit(0);}
| expression '<''=' expression {printf("\nless than or equal recog!");$$=($1<=$4);printf("\n %d",$
$);}
| expression '<''=' { printf ("\n Syntax error: Right operand is missing ");exit(0);}
| expression '>''=' expression {printf("\ngreater than or equal!");$$=($1>=$4);printf("\n %d",$$);}
| expression '>''=' { printf ("\n Syntax error: Right operand is missing ");exit(0);}
| expression '!''=' expression {printf("\nNot equal recog!");$$=($1!=$4);printf("\n %d",$$);}
| expression '!''=' { printf ("\n Syntax error: Right operand is missing ");exit(0);}
| expression '=''=' expression {printf("\ndouble equal recog!");$$=($1==$4);printf("\n %d",$$);}
| expression '=''=' { printf ("\n Syntax error: Right operand is missing ");exit(0);}
| id
| num
;
;
%%
main()
{
printf(" Enter logical expression\n");
yyparse();

}

yyerror()
{
printf(" Invalid logical expression\n");
exit(1);
}
