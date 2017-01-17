
%{
	typedef struct {
		char*** tab;
		int taille;
	}tableau;

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    
    void ValeurSymboles(char *a);
    tableau alloueTableau(int n);
    void afficheTableau(tableau M);
    void initTableau(tableau M);
    int ajoutChaine(char *a, tableau M);
    tableau TableDesSymboles;
    tableau realloueTableau(tableau M);

    

%}



MOTSCLES cin|const|cout|else|if|typedef|while|for

IDPREDEF char|int|float|void|main

 
SYMBOLES "+"|"-"|"*"|"/"|"%"|"!"|"||"|"&&"|"<"|"<="|">"|">="|"=="|"!="|"\""|"\""|"&"|"|"|"="|"("|")"|"["|"]"|"{"|"}"|","|"\'"|";"

CONSTCARAC ['][a-zA-Z][']|['][\\][a-zA-Z][']
%%

{CONSTCARAC} {
printf("200 ");
printf("%s ",yytext);
}


{MOTSCLES} {ValeurSymboles(yytext);}


[a-zA-Z][a-zA-Z0-9]*|{IDPREDEF} {
	int i = ajoutChaine(yytext, TableDesSymboles);
	if(i == 1) {
		TableDesSymboles=realloueTableau(TableDesSymboles);
		i=ajoutChaine(yytext,TableDesSymboles);
	}
	printf("999 ");
	printf("%i ",i+1000);
}

("/*")([^"*"]|[ \t\n]|("*"+([^"*/"]|[\t\n])))*("*/") {printf("%s",yytext);}
[0-9]+ {
printf("201 ");
printf("%s ",yytext);
}
[0-9]+[.][0-9]+|[0-9]+[.][0-9]+[E][-][0-9]+|[0-9]+[.][0-9]+[E][0-9]+ {
printf("202 ");
printf("%s ",yytext);
}


[\n\t ] {printf("%s",yytext);}

{SYMBOLES} { ValeurSymboles(yytext);
}


%%

tableau alloueTableau(int n) {
	int i;
	tableau res;
	res.taille=n;
	res.tab=malloc(n*sizeof(char**));
	for(i=0;i<n;i++) {
		res.tab[i]=malloc(2*sizeof(char*));
	}
	return res;
}
tableau realloueTableau(tableau M) {
	int i;
	M.taille = M.taille*2;
	M.tab=realloc(M.tab,M.taille*sizeof(char**));
	for(i=M.taille/2; i<M.taille;i++) {
		M.tab[i]=malloc(2*sizeof(char*));
		M.tab[i][0]=malloc(7*sizeof(char));
		sprintf(M.tab[i][0],"%d",i+1000);
		M.tab[i][1]=NULL;
	}
	return M;

}

void afficheTableau(tableau M) {
	int i;
	int j;
	for(i=0; i<M.taille; i++) {
		printf("(");
		for(j=0; j<2; j++) {
			printf("%s",M.tab[i][j]);
			printf("  ");
		}
		printf(")\n");
	}
}

void initTableau(tableau M) {
	int i;
	int compteur = 1000;
	for(i=0; i<M.taille; i++) {
		
		M.tab[i][0]=malloc(7*sizeof(char));
		sprintf(M.tab[i][0],"%d",compteur);
		M.tab[i][1]=NULL;

		compteur++;
	}
}

int ajoutChaine(char *a, tableau M){
	int i = 0;

	while(i != M.taille && M.tab[i][1]!=NULL) {
		i++;
		if(strcmp(M.tab[i-1][1],a)==0) {
			return(i-1);
		}
	}
	if(i != M.taille){
		M.tab[i][1] = strdup(a);
	}
	else if(i==M.taille){
		return 1;
	}
	return i;
}

void ValeurSymboles(char *a) {

	if(strcmp(a, "+")==0){
		printf("1 ");
	}
	else if(strcmp(a, "-")==0){
		printf("2 ");
	}
	else if(strcmp(a, "*")==0){
		printf("3 ");
	}
	else if(strcmp(a, "/")==0){
		printf("4 " );
	}
	else if(strcmp(a, "{")==0){
		printf("23 ");
	}
	else if(strcmp(a, "}")==0){
		printf("24 ");
	}
	else if(strcmp(a, "[")==0){
		printf("25 ");
	}
	else if(strcmp(a, "]")==0){
		printf("26 ");
	}
	else if(strcmp(a, "%")==0){
		printf("5 ");
	}
	else if(strcmp(a, "!")==0){
		printf("6 ");
	}
	else if(strcmp(a, "<")==0){
		printf("7 ");
	}
	else if(strcmp(a, ">")==0){
		printf("8 ");
	}
	else if(strcmp(a, "=")==0){
		printf("9 ");
	}
	else if(strcmp(a, "&")==0){
		printf("10 ");
	}
	else if(strcmp(a, "|")==0){
		printf("11 ");
	}
	else if(strcmp(a, "(")==0){
		printf("12 " );
	}
	else if(strcmp(a, ")")==0){
		printf("13 ");
	}
	else if(strcmp(a, ";")==0){
		printf("14 ");
	}
	else if(strcmp(a, ",")==0){
		printf("15 ");
	}
	else if(strcmp(a, "||")==0){
		printf("16 ");
	}
	else if(strcmp(a, "&&")==0){
		printf("17 ");
	}
	else if(strcmp(a, "<=")==0){
		printf("18 ");
	}
	else if(strcmp(a, "==")==0){
		printf("19 ");
	}
	else if(strcmp(a, ">=")==0){
		printf("20 ");
	}
	else if(strcmp(a, "!=")==0){
		printf("21 ");
	}
	else if(strcmp(a, "'")==0){
		printf("22 ");
	}
	else if(strcmp(a, "\"")==0){
		printf("27 ");
	}
	else if(strcmp(a, "cin")==0){
		printf("106 ");
	}
	else if(strcmp(a, "const")==0){
		printf("105 ");
	}
	else if(strcmp(a, "cout")==0){
		printf("104 ");
	}
	else if(strcmp(a, "else")==0){
		printf("101 ");
	}
	else if(strcmp(a, "if")==0){
		printf("100 ");
	}
	else if(strcmp(a, "typedef")==0){
		printf("103 ");
	}
	else if(strcmp(a, "while")==0){
		printf("124 ");
	}
	else if(strcmp(a, "for")==0){
		printf("112 ");
	}

}

int main()
{
	int n = 2;
    TableDesSymboles=alloueTableau(n);
    initTableau(TableDesSymboles);
    yyin=fopen("text.txt","r");
	yylex();
	printf("\n");
	afficheTableau(TableDesSymboles);
	printf("\n Programme Fini.\n");
	return 0;
}