
%{
    #include <stdio.h>
%}


%%

[cd\n] {return yytext[0];}
.       {fprintf(stderr, "Caractère inconnu: %s\n",yytext);
return yytext[0];
}


%%