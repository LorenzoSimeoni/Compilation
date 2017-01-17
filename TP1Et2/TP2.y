%{
#include <stdio.h>
	int yylex();
void yyerror(char*);


%}


%%
S: C C '\n' {printf("%d\n",$1); return 0;}
 ;
C: 'c' C 	{printf("'c' C\n");}
 | 'd' 		{printf("'d'\n");}
 ;


%%




void yyerror(char* msg){
	printf("syntax error: %s\n", msg);
}

int main()
{
	printf("Entrez dans une chaîne : \n");
	yyparse();
	printf("Aurevoir\n");
	return 0;
}
