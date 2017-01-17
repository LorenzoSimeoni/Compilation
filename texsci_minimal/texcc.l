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
in        "\\in"
integer   "\\integer"
typeint   "\\in \\Integer"
If        "\\If"
printText "printText"
printInt  "printInt"
entier    0|[1-9][0-9]*|[-][1-9][0-9]*
id        [a-zA-Z_][a-zA-Z0-9_]*
phrase    ["][a-zA-Z0-9, ?!]*["]
ESPACE    [ \t]


%%


{begin}             { printf("BEGIN");BEGIN(texsci);   // Start TexSci scanning mode
                      return TEXSCI_BEGIN;
                    }
<texsci>{end}       { BEGIN(INITIAL); // Reset to default scanning mode
                      return TEXSCI_END;
		                }
<texsci>{ESPACE}   { printf(" ");}
<texsci>[\n]        { printf("\n");}
<texsci>{mbox}      { printf("MBOX");return MBOX; }
<texsci>{printText} { printf("PRINTEXT");return PRINTTEXT; }
<texsci>{printInt}  { printf("PRINTINT");return PRINTINT; }
<texsci>{leftarrow} { printf("LEFTARROW");return LEFTARROW; }
<texsci>{Local}     { printf("LOCAL");return LOCAL; }
<texsci>{typeint}   { printf("TYPEINT"); return TYPEINT; }
<texsci>[+]         { printf("PLUS"); return PLUS; }
<texsci>[-]         { printf("MINUS"); return MINUS; }
<texsci>[*]         { printf("MULT"); return MULT; }
<texsci>[=]         { printf("EGAL"); return EGAL; }
<texsci>{If}        { printf("IF"); return IF; }

<texsci>{id}        { yylval.name = strdup(yytext);
                      printf("%s", yytext);
                      return ID;
                    }
<texsci>{phrase}    { yylval.name = strdup(yytext);
                      printf("%s", yytext);
                      return PHRASE;
                    }
<texsci>{entier}    { yylval.value = atoi(yytext);
                      printf("%s", yytext);
                      return INTEGER;
                    }
<texsci>{blankline} { printf("BLANKLINE");return BLANKLINE; }



<texsci>[{}]        { printf("%c",yytext[0]);return yytext[0]; }
<texsci>[()""\\;$]   { /*printf("%c",yytext[0]);*/ }

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
