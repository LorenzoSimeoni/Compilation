
#include "EXPRc.h"

int main()
{
    SYMTAB = symtable_new();
    CODE = code_new();
    int r = yyparse();
    FILE* file =NULL;
    file = fopen("mipstest2","w+");
    int k = 0;
    symtable_dump(SYMTAB,file,k);
    k=0;
    code_dump(CODE,file,k);
    symtable_free(SYMTAB);
    code_free(CODE);
    fclose(file);
    return r;
}
