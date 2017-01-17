%{
    #include <stdio.h>
    #include <stdlib.h>
    int i = 0;
    int j = 0;
%}



%%

[\t\n ]+ {printf(" ");}
[^ \t\n]+ {printf("%s",yytext);
i++;}


%%

int main(){
	yyin=fopen("text.txt","r");
	yylex();
	printf("\n%i",i);
	printf("\nProgramme Terminé \n");
	return 0;
}