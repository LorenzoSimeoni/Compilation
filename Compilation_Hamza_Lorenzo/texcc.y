%{
  
  //#include "lib.h"
  #include "lib.c"
  #define TEXCC_ERROR_GENERAL 4

  void yyerror(char*);

  // Functions and global variables provided by Lex.
  int yylex();
  void texcc_lexer_free();
  extern FILE* yyin;
%}

%union {
    long int value;
    char *name;
    float valuefloat;
    struct {
        struct symbol * ptr;
    } exprval;
}

%token TEXSCI_BEGIN TEXSCI_END BLANKLINE MBOX IF PRINTTEXT PRINTINT LEFTARROW LOCAL MINUX PLUS MINUS MULT ASSIGN 
%token CARACFIN DIV IN GLOBAL INPUT OUTPUT EMPTY TYPEREAL OPAR CPAR TYPEINT EGAL PRINTREAL
%token <name> ID 
%token <name> PHRASE

%left PLUS MINUS
%left MULT DIV
%nonassoc UMINUS

%token <valuefloat> REAL
%token <value> INTEGER
%type <exprval> expr
%type <value> condition


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
    {
      fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", $3);
      free($3);
    }
  ;

typeVariable_list:
    typeVariable_list typeVariable
  | typeVariable
  ;

typeVariable:
    LOCAL '{' '$' list_ID '$' '}' 
  | GLOBAL '{' '$' list_ID '$' '}' 
  | INPUT '{' '$' list_ID '$' '}' 
  | OUTPUT '{' '$' list_ID '$' '}' 
  ;

list_ID:
    list_ID ',' declarationID
  | declarationID
  ;

declarationID:
    ID IN TYPEINT
    {
      struct symbol * id = symtable_get(SYMTAB,$1);
      if ( id == NULL )
          id = symtable_put(SYMTAB,$1);
    }
    | ID IN TYPEREAL
    {
      struct symbol * id = symtable_get(SYMTAB,$1);
      if ( id == NULL )
          id = symtable_put_reel(SYMTAB,$1);
    }
    | EMPTY
  ;

commandes_list:
    commandes_list commande
  | commande
  ;

commande:
    '$' MBOX '{' PRINTTEXT '(' '$'  PHRASE '$' ')' '}' '$' CARACFIN
  {
    struct symbol * id = symtable_get(SYMTAB,$7);
    if ( id == NULL )
    {
        id = symtable_put_phrase(SYMTAB,$7);
    }
    gencode(CODE,CALL_PRINT_TEXT,id,NULL,NULL);
  }
  | '$' MBOX '{' PRINTINT '(' '$' INTEGER '$' ')' '}' '$' CARACFIN
  {
    struct symbol * id = symtable_const(SYMTAB,$7);
    if(id->kind == CONSTANT){
      gencode(CODE,CALL_PRINT,id,NULL,NULL);
    }
    else{
      fprintf(stderr, "\nErreur: printInt(float)\n");
      exit(3);
    }
  } 
  | '$' MBOX '{' PRINTINT '(' '$' ID '$' ')' '}' '$' CARACFIN 
  {
    struct symbol * id = symtable_get(SYMTAB,$7);
    if ( id == NULL )
    {
        fprintf(stderr,"\nName '%s' undeclared\n",$7);
        exit(3);
    }
    if(id->kind == NAME){
      gencode(CODE,CALL_PRINT,id,NULL,NULL);
    }
    else{
      fprintf(stderr, "\nErreur: printInt(float)\n");
      exit(3);
    }
  }
  | '$' MBOX '{' PRINTREAL '(' '$' ID '$' ')' '}' '$' CARACFIN 
  {
    struct symbol * id = symtable_get(SYMTAB,$7);
    if ( id == NULL )
    {
        fprintf(stderr,"\nName '%s' undeclared\n",$7);
        exit(3);
    }
    if(id->kind == NAMEREEL){
      gencode(CODE,CALL_PRINT,id,NULL,NULL);
    }
    else{
      fprintf(stderr, "\nErreur: printReal(int)\n");
      exit(3);
    }
  }
  | '$' MBOX '{' PRINTREAL '(' '$' REAL '$' ')' '}' '$' CARACFIN
  {
    struct symbol * id = symtable_reel(SYMTAB,$7);
    if(id->kind == REEL){
      gencode(CODE,CALL_PRINT,id,NULL,NULL);
    }
    else{
      fprintf(stderr, "\nErreur: printReal(int)\n");
      exit(3);
    }
  }
  | '$' ID LEFTARROW expr '$' CARACFIN
  {
    struct symbol * id = symtable_get(SYMTAB,$2);
    if ( id == NULL )
    {
        fprintf(stderr,"\nName '%s' undeclared\n",$2);
        exit(3);
    }
    else if( ((id->kind == NAMEREEL && $4.ptr->kind == REEL) || (id->kind == NAMEREEL && $4.ptr->kind == NAMEREEL)) ||
      ((id->kind == NAME && $4.ptr->kind == CONSTANT) || (id->kind == NAME && $4.ptr->kind == NAME)) ) {
    printf("\n\n%u\n", id->kind);
    printf("%u\n\n", $4.ptr->kind);

      gencode(CODE,COPY,id,$4.ptr,NULL);
    }
    else{
      printf("\nProblème de types\n");
      exit(3);
    }
  }
  | IF '{' condition '}' '{' commandes_list '}'
  {

  }
  ;

condition:
    ID EGAL expr
    {
      
    }
  ;

expr: 
   expr PLUS expr 
  { 
    if( ($1.ptr->kind == NAME||$1.ptr->kind == CONSTANT) && ($3.ptr->kind == NAME||$3.ptr->kind == CONSTANT) ) {
      
      $$.ptr = newtemp(SYMTAB);
      gencode(CODE,BOP_PLUS,$$.ptr,$1.ptr,$3.ptr);

    }
    else if( ($1.ptr->kind == NAMEREEL||$1.ptr->kind == REEL) && ($3.ptr->kind == NAMEREEL||$3.ptr->kind == REEL) ){
      $$.ptr = newtempreel(SYMTAB);
      gencode(CODE,BOP_PLUS,$$.ptr,$1.ptr,$3.ptr);
    }
    else{
      printf("\nProblème de types\n");
      exit(3);
    }

  }
  | expr MINUS expr
  { 
    if( ($1.ptr->kind == NAME||$1.ptr->kind == CONSTANT) && ($3.ptr->kind == NAME||$3.ptr->kind == CONSTANT) ) {
      
      $$.ptr = newtemp(SYMTAB);
      gencode(CODE,BOP_MINUS,$$.ptr,$1.ptr,$3.ptr);

    }
    else if( ($1.ptr->kind == NAMEREEL||$1.ptr->kind == REEL) && ($3.ptr->kind == NAMEREEL||$3.ptr->kind == REEL) ){
      $$.ptr = newtempreel(SYMTAB);
      gencode(CODE,BOP_MINUS,$$.ptr,$1.ptr,$3.ptr);
    }
    else{
      printf("\nProblème de types\n");
      exit(3);
    }

  }
| MINUS expr %prec UMINUS
  { 
    if( $2.ptr->kind == NAME ){
      $$.ptr = newtemp(SYMTAB);
      gencode(CODE,UOP_MINUS,$$.ptr,$2.ptr,NULL); 
    }
    else{
      $$.ptr = newtempreel(SYMTAB);
      gencode(CODE,UOP_MINUS,$$.ptr,$2.ptr,NULL);
    }

  }
  | expr MULT expr
  { 
    if( ($1.ptr->kind == NAME||$1.ptr->kind == CONSTANT) && ($3.ptr->kind == NAME||$3.ptr->kind == CONSTANT) ) {
      
      $$.ptr = newtemp(SYMTAB);
      gencode(CODE,BOP_MULT,$$.ptr,$1.ptr,$3.ptr);

    }
    else if( ($1.ptr->kind == NAMEREEL||$1.ptr->kind == REEL) && ($3.ptr->kind == NAMEREEL||$3.ptr->kind == REEL) ){
      $$.ptr = newtempreel(SYMTAB);
      gencode(CODE,BOP_MULT,$$.ptr,$1.ptr,$3.ptr);
    }
    else{
      printf("\nProblème de types\n");
      exit(3);
    }
  }
  | expr DIV expr
  {
    if( ($1.ptr->kind == NAME||$1.ptr->kind == CONSTANT) && ($3.ptr->kind == NAME||$3.ptr->kind == CONSTANT) ) {
      
      $$.ptr = newtemp(SYMTAB);
      gencode(CODE,BOP_DIV,$$.ptr,$1.ptr,$3.ptr);

    }
    else if( ($1.ptr->kind == NAMEREEL||$1.ptr->kind == REEL) && ($3.ptr->kind == NAMEREEL||$3.ptr->kind == REEL) ){
      $$.ptr = newtempreel(SYMTAB);
      gencode(CODE,BOP_DIV,$$.ptr,$1.ptr,$3.ptr);
    }
    else{
      printf("\nProblème de types\n");
      exit(3);
    }
  }
| ID
  { 
    struct symbol * id = symtable_get(SYMTAB,$1);
    if ( id == NULL )
    {
        fprintf(stderr,"\nName '%s' undeclared\n",$1);
        exit(1);
    }
    $$.ptr = id;
  }
| INTEGER
  { 
    $$.ptr = symtable_const(SYMTAB,$1);
  }
| REAL
  {
    $$.ptr = symtable_reel(SYMTAB,$1);
  }
;


%%

void yyerror(char *s) {
  printf(" %s\n ", s);
  exit(2);
}

int main(int argc, char* argv[]) {
  SYMTAB = symtable_new();
  CODE = code_new();
  //fprintf(stderr,"\n\n\n\n\n\n\n%s %s %s\n\n\n\n\n\n\n", argv[0], argv[1], argv[2]);
  if (argc == 2) {
    if ((yyin = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "[texcc] error: unable to open file %s\n", argv[1]);
      exit(TEXCC_ERROR_GENERAL);
    }
  } else {
    fprintf(stderr, "[texcc] usage: %s input_file\n", argv[0]);
    exit(TEXCC_ERROR_GENERAL);
  }

  yyparse();
  
  symtable_dump(SYMTAB);
  symtable_dump_mips(SYMTAB);
  
  code_dump(CODE);
  code_dump_mips(CODE);
  symtable_free(SYMTAB);
  code_free(CODE);

  fclose(yyin);
  texcc_lexer_free();
  return EXIT_SUCCESS;
}
