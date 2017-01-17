
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

#define TEXCC_ERROR_GENERAL 4

void texcc_lexer_free();

struct symtable * SYMTAB;
struct code * CODE;

extern int yyparse();
