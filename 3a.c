%{
#include<stdio.h>
int c=0;
FILE *fp;
%}
%%
\n { c++; }
["][a-zA-Z0-9]*["] {ECHO; printf(" Valid String in line number %d\n ",c+1);}
["][a-zA-Z0-9]* { ECHO; printf(" InValid String in line number %d\n ",c+1);}
. ;
%%
main()
{
yyin=fopen("3.txt","r");
yylex();
fclose(yyin);
}
