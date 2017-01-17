%{
  #include <stdlib.h>
  #include <string.h>
  #include "y.tab.h"
%}

%s texsci

begin     "\\begin{texsci}"
end       "\\end{texsci}"
blankline "\\BlankLine"

mbox      "\\mbox"
leftarrow "\\leftarrow"
Local     "\\Local"
Global    "\\Global"
Input     "\\Input"
Output    "\\Output"
Empty     "\\emptyset"
in        "\\in"
integer   "\\integer"
typeint   "\\Integer"
typeReal  "\\Real"
typeComplex "\\Complex"
typeBool  "\\Boolean"
If        "\\If"
printText "printText"
printInt  "printInt"
printReal "printReal"
entier    0|[1-9][0-9]*|[-][1-9][0-9]*
id        [a-zA-Z_][a-zA-Z0-9_]*
reel      [1-9]*[0-9]+[.][0-9]+[1-9]*|[-][1-9]*[0-9]+[.][0-9]+[1-9]*
phrase    \"(\\.|[^"])*\"
ESPACE    [ \t]
CARACFIN  [\\][;]
mult      "\\times"
division  "\\div"


%%


{begin}             { printf("BEGIN");BEGIN(texsci);   // Start TexSci scanning mode
                      return TEXSCI_BEGIN;
                    }
<texsci>{end}       { BEGIN(INITIAL); // Reset to default scanning mode
                      return TEXSCI_END;
                    }
<texsci>{mult}      { printf("MULT"); return MULT; }
<texsci>{ESPACE}    { printf(" ");}
<texsci>[\n]        { printf("\n");}
<texsci>{mbox}      { printf("MBOX");return MBOX; }
<texsci>{printText} { printf("PRINTEXT");return PRINTTEXT; }
<texsci>{printInt}  { printf("PRINTINT");return PRINTINT; }
<texsci>{printReal} { printf("PRINTREAL"); return PRINTREAL; }
<texsci>{leftarrow} { printf("LEFTARROW");return LEFTARROW; }
<texsci>{Local}     { printf("LOCAL");return LOCAL; }
<texsci>{Global}    { printf("GLOBAL");return GLOBAL; }
<texsci>{Input}     { printf("INPUT");return INPUT; }
<texsci>{Output}    { printf("OUTPUT");return OUTPUT; }
<texsci>{Empty}     { printf("EMPTY");return EMPTY; }
<texsci>{typeint}   { printf("TYPEINT"); return TYPEINT; }
<texsci>{typeReal}  { printf("TYPEREAL"); return TYPEREAL; }
<texsci>{in}        { printf("IN"); return IN; }
<texsci>[+]         { printf("PLUS"); return PLUS; }
<texsci>[-]         { printf("MINUS"); return MINUS; }

<texsci>[=]         { printf("EGAL"); return EGAL; }
<texsci>{division}  { printf("DIV"); return DIV; }
<texsci>{If}        { printf("IF"); return IF; }

<texsci>{id}        { yylval.name = strdup(yytext);
                      printf("ID%s", yytext);
                      return ID;
                    }
<texsci>{reel}      { yylval.valuefloat = atof(yytext);
                      printf("REAL%s", yytext);
                      return REAL;}
<texsci>{phrase}    { yylval.name = strdup(yytext);
                      printf("PHRASE%s", yytext);
                      return PHRASE;
                    }
<texsci>{entier}    { yylval.value = atoi(yytext);
                      printf("%s", yytext);
                      return INTEGER;
                    }
<texsci>{blankline} { printf("BLANKLINE");return BLANKLINE; }

<texsci>{CARACFIN}  { printf("CARACFIN"); return CARACFIN; }

<texsci>[{}$""(),]  { printf("%c",yytext[0]);return yytext[0]; }
<texsci>.           { printf("\nTOKEN INVALIDE\n"); exit(1); }

[\n]                { }
.                   { }

%%

/**
 * texcc_lexer_free function:
 * this function frees the memory allocated for the lexer. It frees
 * flex's buffer (it supposes there is only one buffer) since flex does
 * never free it itself.
 */
void texcc_lexer_free() {
  yy_delete_buffer(YY_CURRENT_BUFFER);
  free(yy_buffer_stack);
}