#define ELEMENTS 257
#define IDENTIFICATEUR 258
#define UNION 259
#define INTER 260
#define COMP 261
#define DIFF 262
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{ 
	int value;
	char ident;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
