%{
#include <stdio.h>
	extern FILE *yyin;
	int yylex();
	void yyerror(char*);

void affichebin(unsigned n)
{
	unsigned bit = 0 ;
	unsigned mask = 1 ;
	for (int i = 0 ; i < 32 ; ++i)
	{
		bit = (n & mask) >> i ;
		printf("%d", bit) ;
		mask <<= 1 ;
	}
}
void affichebin2(unsigned n)
{
	unsigned bit = 0 ;
	unsigned mask = 1 ;
	printf("{");
	int i =0;
	while(bit != 1 && i<32){
		bit = (n & mask) >> i ;
		if(bit==1){
			printf("%d",i+1);
		}
		mask <<= 1 ;
		i++;
	}
	for (i ; i < 32 ; ++i)
	{
		bit = (n & mask) >> i ;
		if(bit==1){
			printf(",");
			printf("%d",i+1);
		}
		mask <<= 1 ;
	}
	printf("}");
}
int recherchecarac(char a[],char b) {
	for(int k=0;k<100;k++) {
		if(a[k]==b){
			return(k);
		}
	}
	return -1;
}
	int a[100] = {0 << 31};
	int b = 0 << 31;
	int compteur=0;
	int compteur2=0;
	int compteur3=-1;
	int compteur4=-1;
	char c[102];


%}

%union{ 
	int value;
	char ident;
}

%token <value> ELEMENTS
%token <ident> IDENTIFICATEUR
%token UNION
%token INTER
%token COMP
%token DIFF
%type <value> elem


%left ','

%%

liste:
	instruction {printf("FIN\n");return 0;}
	;

instruction:
	 IDENTIFICATEUR':''='expression {//printf("instruction':='ensemble!\n");
	 compteur2 = recherchecarac(c,$1);
	 //printf("%c:=",$1);
	 if(compteur2!=-1){
	 	if(compteur3!=-1){
	 		a[compteur2]=a[compteur3];
	 		compteur3=-1;
	 	}
	 	else{
	 		a[compteur2] = a[compteur];
	 	}
	 	a[compteur] = 0<<31;
	 	compteur--;
	 	//affichebin2(a[compteur2]);
	 }
	 else{
	 	if(compteur3!=-1){
	 		a[compteur]=a[compteur3];
	 		compteur3=-1;
	 	}
	 	//affichebin2(a[compteur]);
	 	c[compteur]=$1;
	 }
	 compteur++;
	 //printf("\n");
	}
	| IDENTIFICATEUR':''='expression '\n'{//printf("instruction':='ensemble!\n");
	 compteur2 = recherchecarac(c,$1);
	 //printf("%c:=",$1);
	 if(compteur2!=-1){
	 	if(compteur3!=-1){
	 		a[compteur2]=a[compteur3];
	 		compteur3=-1;
	 	}
	 	else{
	 		a[compteur2] = a[compteur];
	 	}
	 	a[compteur] = 0<<31;
	 	compteur--;
	 	//affichebin2(a[compteur2]);
	 }
	 else{
	 	if(compteur3!=-1){
	 		a[compteur]=a[compteur3];
	 		compteur3=-1;
	 	}
	 	//affichebin2(a[compteur]);
	 	c[compteur]=$1;
	 }
	 compteur++;
	 //printf("\n");
	}
	| IDENTIFICATEUR':''='expression ' ' {//printf("instruction':='ensemble!' '\n");	
	 compteur2 = recherchecarac(c,$1);
	 //printf("%c:=",$1);
	 if(compteur2!=-1){
	 	if(compteur3!=-1){
	 		a[compteur2]=a[compteur3];
	 		compteur3=-1;
	 	}
	 	else{
	 		a[compteur2] = a[compteur];
	 	}
	 	a[compteur] = 0<<31;
	 	compteur--;
	 	//affichebin2(a[compteur2]);
	 }
	 else{
	 	if(compteur3!=-1){
	 		a[compteur]=a[compteur3];
	 		compteur3=-1;
	 	}
	 	//affichebin2(a[compteur]);
	 	c[compteur]=$1;
	 }
	 compteur++;
	 //printf("\n");
	}
	| instruction IDENTIFICATEUR {
		printf("%c:=",$2);
		compteur2=recherchecarac(c,$2);
		if(compteur2!=-1){
			affichebin2(a[compteur2]);
			printf("\n");
		}
		else{
			printf("Problème %c pas défini",$2);
			return 0;
		}
	}
	| instruction IDENTIFICATEUR '\n'{
		printf("%c:=",$2);
		compteur2=recherchecarac(c,$2);
		if(compteur2!=-1){
			affichebin2(a[compteur2]);
			printf("\n");
		}
		else{
			printf("Problème %c pas défini",$2);
			return 0;
		}
	}
	| instruction IDENTIFICATEUR':''='expression ' ' {//printf("instruction instruction':='ensemble' '!\n");	
	 compteur2 = recherchecarac(c,$2);
	 //printf("%c:=",$2);
	 if(compteur2!=-1){
	 	if(compteur3!=-1){
	 		a[compteur2]=a[compteur3];
	 		compteur3=-1;
	 	}
	 	else{
	 		a[compteur2] = a[compteur];
	 	}
	 	a[compteur] = 0<<31;
	 	compteur--;
	 	//affichebin2(a[compteur2]);
	 }
	 else{
	 	if(compteur3!=-1){
	 		a[compteur]=a[compteur3];
	 		compteur3=-1;
	 	}
	 	//affichebin2(a[compteur]);
	 	c[compteur]=$2;
	 }
	 compteur++;
	 //printf("\n");
	}
	| instruction IDENTIFICATEUR':''='expression {//printf("instruction instruction':='ensemble!%d\n",compteur3);	
	 compteur2 = recherchecarac(c,$2);
	 //printf("%c:=",$2);
	 if(compteur2!=-1){
	 	if(compteur3!=-1){
	 		a[compteur2]=a[compteur3];
	 		compteur3=-1;
	 	}
	 	else{
	 		a[compteur2] = a[compteur];
	 	}
	 	a[compteur] = 0<<31;
	 	compteur--;
	 	//affichebin2(a[compteur2]);
	 }
	 else{
	 	if(compteur3!=-1){
	 		a[compteur]=a[compteur3];
	 		compteur3=-1;
	 	}
	 	//affichebin2(a[compteur]);
	 	c[compteur]=$2;
	 }
	 compteur++;
	 //printf("\n");
	}
	| instruction IDENTIFICATEUR':''='expression'\n' {//printf("instruction instruction':='ensemble!%d\n",compteur3);	
	 compteur2 = recherchecarac(c,$2);
	 //printf("%c:=",$2);
	 if(compteur2!=-1){
	 	if(compteur3!=-1){
	 		a[compteur2]=a[compteur3];
	 		compteur3=-1;
	 	}
	 	else{
	 		a[compteur2] = a[compteur];
	 	}
	 	a[compteur] = 0<<31;
	 	compteur--;
	 	//affichebin2(a[compteur2]);
	 }
	 else{
	 	if(compteur3!=-1){
	 		a[compteur]=a[compteur3];
	 		compteur3=-1;
	 	}
	 	//affichebin2(a[compteur]);
	 	c[compteur]=$2;
	 }
	 compteur++;
	 //printf("\n");
	}
	;

expression:
	operande					{//printf("expression\n");
}
	| operande UNION operande 	{
	if(compteur3 != -1 && compteur4!=-1){
		a[compteur]=(a[compteur4]|a[compteur3]);
		compteur3=-1;
		compteur4=-1;
	}
	else if(compteur3!= -1 && compteur4==-1){
		a[compteur]=(a[compteur]|a[compteur3]);
		compteur3=-1;
	}
	//printf("operande UNION operande\n");
}
	| operande INTER operande	{
	if(compteur3 != -1 && compteur4 !=-1){
		a[compteur]=(a[compteur4]&a[compteur3]);
		compteur3=-1;
		compteur4=-1;
	}
	else if(compteur3 != -1 && compteur4 ==-1){
		a[compteur]=(a[compteur]&a[compteur3]);
		compteur3=-1;
	}
	//printf("operande INTER operande\n");
}
	| operande DIFF operande	{
	if(compteur3 != -1 && compteur4 !=-1){
		a[compteur]=(a[compteur3]^(a[compteur3]&a[compteur4]));
		compteur3=-1;
		compteur4=-1;
	}
	else if(compteur3 != -1 && compteur4 ==-1){
		a[compteur]=(a[compteur]^(a[compteur]&a[compteur3]));
		compteur3=-1;
	}
	//printf("operande DIFF operande\n");
}
	| COMP operande	{
	if(compteur3!=-1) {
		int inttransition=2147483647;
		inttransition=inttransition<<1;
		inttransition=(inttransition|1);
		a[compteur]=(a[compteur3]^inttransition);
		compteur3=-1;
	}
	else{
		int inttransition=2147483647;
		inttransition=inttransition<<1;
		inttransition=(inttransition|1);
		a[compteur]=(a[compteur]^inttransition);
	}
	//printf("COMP operande\n");
}
	;

operande:
	IDENTIFICATEUR 	{
	if(compteur3!=-1){
		compteur4 = recherchecarac(c,$1);
		if(compteur4==-1){printf("%cn'est pas un élément existant!",$1);return 0;}
	}
	else{
		compteur3 = recherchecarac(c,$1);
		if(compteur3==-1){printf("%cn'est pas un élément existant!",$1);
	return 0;}}
	//printf("IDENTIFICATEUR\n");
}
	| ensemble		{//printf("operande\n");
}
	;

ensemble:
	'{''}'		{//printf("'{''}'\n");
}
	|'{'elem'}' {//printf("'{'elements'}'\n");
}
	;

elem:
	elem','elem 	{//printf("elem','elem\n");
}
  | ELEMENTS		{b=1<<$1-1; a[compteur]=(a[compteur]|b);//printf("ELEMENTS\n");
}
  ;

%%

void yyerror(char* msg){
	printf("syntax error: %s\n", msg);
}

int main()
{
	printf("Entrez une chaîne : \n");
	yyin=fopen("testgrammaire.txt","r");
	yyparse();
	printf("Aurevoir\n");
	return 0;
}