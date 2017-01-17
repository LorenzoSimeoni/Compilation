
%{
    #include <stdio.h>
    #include "y.tab.h"
%}


%%

[0-9]+	{yylval.value=atoi(yytext); return NUMBER;}
[()+*]	{return yytext[0];}
[\n]	{return yytext[0];}
.		{printf("Car. inconnu: %s",yytext);}
%%