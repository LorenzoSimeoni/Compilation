%{
  
  //#include "lib.h"
  #include "lib.c"

extern void yyerror(const char * s);
extern int yylex();
  
  extern FILE* yyin;
%}

%union {
    long int value;
    char *name;
    struct {
        struct symbol * ptr;
    } exprval;
}

%token TEXSCI_BEGIN TEXSCI_END BLANKLINE MBOX IF PRINTTEXT PRINTINT LEFTARROW LOCAL MINUX PLUS MINUS MULT ASSIGN OPAR CPAR TYPEINT EGAL
%token <name> ID 
%token <name> PHRASE

%left PLUS MINUS
%left MULT
%nonassoc UMINUS


%token <value> INTEGER
%type <exprval> expr


%%

algorithm_list:
    algorithm_list algorithm
  | algorithm
  ;

algorithm:
    TEXSCI_BEGIN '{' ID '}' BLANKLINE commandes_list TEXSCI_END
    {
      fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", $3);
      free($3);
    }
  | TEXSCI_BEGIN '{' ID '}' BLANKLINE TEXSCI_END
    {
      fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", $3);
      free($3);
    }
  | TEXSCI_BEGIN '{' ID '}' typeVariable_list BLANKLINE commandes_list TEXSCI_END
  ;

typeVariable_list:
    typeVariable_list typeVariable
  | typeVariable
  ;

typeVariable:
    LOCAL '{' list_ID '}'
  ;

list_ID:
    list_ID declarationID
  | declarationID
  ;

declarationID:
    ID TYPEINT
    {

    }
  ;

commandes_list:
    commandes_list commande
  | commande
  ;

commande:
    MBOX '{' PRINTTEXT PHRASE '}'
  {
    fprintf(stderr, "print: %s\n", $4);
    free($4);
  }
  | MBOX '{' PRINTINT expr '}' 
  {

  }
  | ID LEFTARROW expr 
  {

  }
  | IF '{' condition '}' '{' commandes_list '}'
  ;

condition:
    expr EGAL expr
  ;

expr:
   expr PLUS expr
  | expr MINUS expr
  | expr MULT expr
| ID
  { 

  }
| INTEGER
  { 

  }
;


%%

void yyerror(const char * s)
{
    fprintf(stderr,"%s\n",s);
}