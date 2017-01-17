%{
#include <stdio.h>
#include <ctype.h>
#include "y.tab.h"
%}

%%

[0-9]+	{yylval.value=atoi(yytext); 
if(yylval.value <= 32){
	return ELEMENTS;
}
else{
	printf("Les éléments sont compris entre 0 et 32!");
}
}
[a-zA-Z] 			{yylval.ident=toupper(yytext[0]); return IDENTIFICATEUR;}
[{,}:=]				{return yytext[0];}
[\n]				{return yytext[0];}
[ ]					{return yytext[0];}
"UNION"|"union"		{return UNION;}
"INTER"|"inter" 	{return INTER;}
"COMP"|"comp" 		{return COMP;}
"DIFF"|"diff"		{return DIFF;}
.					{printf("Car. inconnu: %s",yytext);}	

%%
