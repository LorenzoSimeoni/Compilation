%{
#include <stdio.h>
	int yylex();
	void yyerror(char*);


%}

%union{ 
	int value;

}

%token <value> NUMBER
%type <value> expr

%left '+'
%left '*'

%%

axiom:
	expr '\n' {printf("Resultat = %d\n",$1);return 0;}
	;

expr:
	 expr'+'expr 	{$$=$1+$3;printf("expr %d'+'expr %d %d\n",$1,$3,$$);}
  | expr'*'expr 		{$$=$1*$3;printf("expr %d'*'expr %d %d\n",$1,$3,$$);}
  | '('expr')'			{$$=$2;printf("'('expr %d')'\n",$2);}
  | NUMBER				{$$=$1;printf("NUMBER %d\n",$1);}
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