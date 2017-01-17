

#include <stdlib.h>
#include <string.h>
#include <stdio.h>



/* TABLE DES SYMBOLES */

struct symbol {
  enum { NAME, CONSTANT, REEL, NAMEREEL, PHRAS } kind;
    union {
        char name[200];
        long int value;
        float value2;
    } u;
};


struct symtable * SYMTAB;
struct symtable {
    unsigned int capacity;
    unsigned int temporary; 
    unsigned int size;
    struct symbol * symbols;
};

struct quad {
  enum quad_kind { BOP_PLUS, BOP_MINUS, BOP_MULT, UOP_MINUS, BOP_DIV, COPY, CALL_PRINT, CALL_PRINT_TEXT } kind;
  struct symbol * sym1;
  struct symbol * sym2;
  struct symbol * sym3;
};

struct code * CODE;
struct code {
    unsigned int capacity;
    unsigned int nextquad;
    struct quad * quads;
};


struct symtable * SYMTAB;
struct code * CODE;

struct symtable * symtable_new()
{
    struct symtable * t = malloc(sizeof(struct symtable));
    t->capacity = 1024;
    t->symbols = malloc(t->capacity*sizeof(struct symbol));
    t->temporary = 0;
    t->size = 0;
    return t;
}

static void symtable_grow(struct symtable * t) 
{
    t->capacity += 1024;
    t->symbols = realloc(t->symbols,t->capacity*sizeof(struct symbol));
    if(t->symbols == NULL) 
    {
      fprintf(stderr,"Error attempting to grow symbol table (actual size is %d)\n",t->size);
        exit(1);
    }
}

struct symbol * symtable_const(struct symtable * t, long int v) 
{
    unsigned int i;
    for ( i=0 ; i<t->size && t->symbols[i].u.value != v; i++ );
    if(i==t->size)
    {
        if(t->size==t->capacity)
          symtable_grow(t);
        struct symbol *s = &(t->symbols[t->size]);
        s->kind = CONSTANT;
        s->u.value = v;
        ++ (t->size);
        return s;
    }
    else 
    {
        return &(t->symbols[i]);
    }
}



struct symbol * symtable_reel(struct symtable * t, float v) 
{
    int i;
    for ( i=0 ; i<t->size && t->symbols[i].u.value2 != v; i++ );
    if(i==t->size)
    {
        if(t->size==t->capacity)
          symtable_grow(t);
        struct symbol *s = &(t->symbols[t->size]);
        s->kind = REEL;
        s->u.value2 = v;
        ++ (t->size);
        return s;
    }
    else 
    {
        return &(t->symbols[i]);
    }
}








void printsym(struct symtable * t){
    int i = 0;
    for ( i=0 ; i<t->size; i++ ){
        printf("%u ",t->symbols[i].kind);
        if(t->symbols[i].kind == CONSTANT){
            printf("%ld\n", t->symbols[i].u.value);
        }
        else{
            printf("NULL\n");
        }
        
    }
}

struct symbol * symtable_get(struct symtable * t, const char * id) 
{
    unsigned int i;

    for ( i=0 ; i<t->size && strcmp(t->symbols[i].u.name,id) != 0; i++ );
    if(i<t->size)
      return &(t->symbols[i]);
    return NULL;
}

struct symbol * symtable_put(struct symtable * t, const char * id) 
{
    if(t->size==t->capacity)
      symtable_grow(t);
    struct symbol *s = &(t->symbols[t->size]);
    s->kind = NAME;
    strcpy(s->u.name,id);
    ++ (t->size);
    return s;
}


struct symbol * symtable_put_reel(struct symtable * t, const char * id) 
{
    if(t->size==t->capacity)
      symtable_grow(t);
    struct symbol *s = &(t->symbols[t->size]);
    s->kind = NAMEREEL;
    strcpy(s->u.name,id);
    ++ (t->size);
    return s;
}

struct symbol * symtable_put_phrase(struct symtable * t, const char * id) 
{
    if(t->size==t->capacity)
      symtable_grow(t);
    struct symbol *s = &(t->symbols[t->size]);
    s->kind = PHRAS;
    strcpy(s->u.name,id);
    ++ (t->size);
    return s;
}



void symtable_dump(struct symtable * t)
{
    unsigned int i;
    for ( i=0 ; i<t->size; i++ )
    {
        if(t->symbols[i].kind==CONSTANT)
            printf("       %p = %ld\n",&(t->symbols[i]),t->symbols[i].u.value);
        else if(t->symbols[i].kind==NAME)
            printf("       %p = %s\n",&(t->symbols[i]),t->symbols[i].u.name);
        else if(t->symbols[i].kind==PHRAS)
            printf("       %p = %s\n",&(t->symbols[i]),t->symbols[i].u.name);  
        else if(t->symbols[i].kind==REEL)
            printf("       %p = %lf\n",&(t->symbols[i]),t->symbols[i].u.value2);
        else if(t->symbols[i].kind==NAMEREEL)
            printf("       %p = %s\n",&(t->symbols[i]),t->symbols[i].u.name);
    }
    printf("       --------\n");
}



void symtable_dump_mips(struct symtable *t)
{
    FILE *f=fopen("output.s","w");
    fprintf(f,"\n\n.data\n");
    unsigned int i;
    int count=1;
    for ( i=0 ; i<t->size; i++ )
    {
        switch ( t->symbols[i].kind )
        {
            case CONSTANT :
                //fprintf(f,"    %ld: .word 0\n",t->symbols[i].u.value);
                break;
            case PHRAS :
                fprintf(f,"    text%d : .asciiz %s\n",count,t->symbols[i].u.name);
                count++;
                break;
            
            case NAME :
                if(strncmp((const char *) t->symbols[i].u.name,"$t",1)!=0)
                {
                    fprintf(f,"    %s: .word 0\n",t->symbols[i].u.name);
                }
                break;
            case NAMEREEL :
                if(strncmp((const char *) t->symbols[i].u.name,"$t",1)!=0)
                {
                    fprintf(f,"    %s: .float 1.0\n",t->symbols[i].u.name);
                }
                break;
            case REEL :
                break;
            default:
            break;
        }

    }
    fprintf(f, "enter : .asciiz \" \\n\" \n");
    fprintf(f,".text\n");
    fclose(f);
}


void symtable_free(struct symtable * t)
{
    free(t->symbols);
    free(t);
}

struct code * code_new()
{
    struct code * r = malloc(sizeof(struct code));
    r->capacity = 1024;
    r->quads = malloc(r->capacity*sizeof(struct quad));
    r->nextquad = 0;
    return r;
}

static void code_grow(struct code * c)
{
    c->capacity += 1024;
    c->quads = realloc(c->quads,c->capacity*sizeof(struct quad));
    if(c->quads == NULL) 
    {
      fprintf(stderr,"Error attempting to grow quad list (actual size is %d)\n",c->nextquad);
        exit(1);
    }
}

void gencode(struct code * c,
              enum quad_kind k,
              struct symbol * s1,
              struct symbol * s2,
              struct symbol * s3)
{
    if ( c->nextquad == c->capacity )
        code_grow(c);
    struct quad * q = &(c->quads[c->nextquad]);
    q->kind = k;
    q->sym1 = s1;
    q->sym2 = s2;
    q->sym3 = s3;
    ++ (c->nextquad);
}

struct symbol *newtemp(struct symtable * t)
{
  struct symbol * s;
  char name[20];
  sprintf(name,"temp%d",t->temporary);
  s = symtable_put(t,name);
  ++ (t->temporary);
  return s;
}


struct symbol *newtempreel(struct symtable * t)
{
  struct symbol * s;
  char name[20];
  sprintf(name,"temp%d",t->temporary);
  s = symtable_put_reel(t,name);
  ++ (t->temporary);
  return s;
}

static void symbol_dump(struct symbol * s)
{
    switch ( s->kind )
    {
        case NAME:
            printf("%s",s->u.name);
            break;
        case NAMEREEL:
            printf("%s",s->u.name);
            break;    
        case PHRAS:  
            printf("%s",s->u.name);            
            break;
        case CONSTANT:
            printf("%ld",s->u.value);
            break;
        case REEL:
            printf("%.4f",s->u.value2);
            break;
        default:
            break;
    }
}


static void symbol_dump_mips(struct symbol * s,FILE* f)
{
   
    switch ( s->kind )
    {
        case NAME:
            fprintf(f,"%s",s->u.name);
            break;
        case NAMEREEL:
            fprintf(f,"%s",s->u.name);
            break;
        case PHRAS:
            fprintf(f,"%s",s->u.name);    
            break;
        case REEL:
            fprintf(f,"%.4f",s->u.value2);
            break;
        case CONSTANT:
            fprintf(f,"%ld",s->u.value);
            break;
        default:
            break;
    }
}

static void quad_dump(struct quad * q)
{
    switch ( q->kind )
    {
        case BOP_PLUS:
            symbol_dump(q->sym1);
            printf(" := ");
            symbol_dump(q->sym2);
            printf(" + ");
            symbol_dump(q->sym3);
            break;
        case BOP_MINUS:
            symbol_dump(q->sym1);
            printf(" := ");
            symbol_dump(q->sym2);
            printf(" - ");
            symbol_dump(q->sym3);
            break;
        case BOP_MULT:
            symbol_dump(q->sym1);
            printf(" := ");
            symbol_dump(q->sym2);
            printf(" * ");
            symbol_dump(q->sym3);
            break;
        case UOP_MINUS:
            symbol_dump(q->sym1);
            printf(" := ");
            printf("- ");
            symbol_dump(q->sym2);
            break;
        case BOP_DIV:
           symbol_dump(q->sym1);
            printf(" := ");
            symbol_dump(q->sym2);
            printf(" / ");
            symbol_dump(q->sym3);
            break;
        
        case CALL_PRINT:
            printf("print ");
            symbol_dump(q->sym1);
            break;
        case CALL_PRINT_TEXT:
            printf("print ");
            symbol_dump(q->sym1);
            break;
        case COPY:
            symbol_dump(q->sym1);
            printf(" := ");
            symbol_dump(q->sym2);
            break;
        default:
            printf("BUG\n");
            break;
    }
}

static void fonction_tomips(struct quad * q, FILE *f, int i)
{
    
        switch ( q->kind )
        {
        case BOP_PLUS:
            if(q->sym3->kind==NAME && q->sym2->kind==NAME)
            {
                fprintf(f,"lw $t0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tlw $t1, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tadd $t2, $t0, $t1");
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);
            }
            else if(q->sym3->kind==CONSTANT && q->sym2->kind==CONSTANT){
                fprintf(f,"li $t0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\taddi $t2, $t0, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);                

            }
            else if(q->sym3->kind==CONSTANT){
                fprintf(f,"lw $t0, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\taddi $t2, $t0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);                

            }
            else if(q->sym2->kind==CONSTANT){
                fprintf(f,"lw $t0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\taddi $t2, $t0, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);                

            }
            if(q->sym3->kind==NAMEREEL && q->sym2->kind==NAMEREEL)
            {
                fprintf(f,"lwc1 $f0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tlwc1 $f2, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tadd.s $f4, $f2, $f0");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);
            }
            else if(q->sym3->kind==REEL && q->sym2->kind==REEL){
                fprintf(f,"li.s $f0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tli.s $f2, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tadd.s $f4, $f2, $f0");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);               

            }
            else if(q->sym3->kind==REEL){
                fprintf(f,"li.s $f0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tlwc1 $f2, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tadd.s $f4, $f0, $f2");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);               

            }
            else if(q->sym2->kind==REEL){
               fprintf(f,"li.s $f0, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tlwc1 $f2, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tadd.s $f4, $f2, $f0");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);               

            }
            

                break;
        case BOP_MINUS:
            if(q->sym3->kind==NAME && q->sym2->kind==NAME)
            {
                fprintf(f,"lw $t0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tlw $t1, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tsub $t2, $t1, $t0");
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);
            }
            else if(q->sym3->kind==CONSTANT && q->sym2->kind==CONSTANT){
                fprintf(f,"li $t0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tli $t1, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tsub $t2, $t1, t0 ");
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);                

            }
            else if(q->sym3->kind==CONSTANT){
                fprintf(f,"li $t0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tlw $t1, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tsub $t2, $t1, t0 ");
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);                

            }
            else if(q->sym2->kind==CONSTANT){
                fprintf(f,"lw $t0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tli $t1, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tsub $t2, $t1, t0 ");
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);                

            }
            if(q->sym3->kind==NAMEREEL && q->sym2->kind==NAMEREEL)
            {
                fprintf(f,"lwc1 $f0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tlwc1 $f2, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tsub.s $f4, $f2, $f0");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);
            }
            else if(q->sym3->kind==REEL && q->sym2->kind==REEL){
                fprintf(f,"li.s $f0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tli.s $f2, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tsub.s $f4, $f2, $f0");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);               

            }
            else if(q->sym3->kind==REEL){
                fprintf(f,"li.s $f0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tlwc1 $f2, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tsub.s $f4, $f2, $f0");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);               

            }
            else if(q->sym2->kind==REEL){
               fprintf(f,"li.s $f0, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tlwc1 $f2, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tsub.s $f4, $f0, $f2");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);               

            }
            break;
        case BOP_MULT:
            if(q->sym3->kind==NAME && q->sym2->kind==NAME)
            {
                fprintf(f,"lw $t0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tlw $t1, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tmult $t0, $t1");
                fprintf(f,"\n\tmflo $t2 ");
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);
            }
            else if(q->sym3->kind==CONSTANT && q->sym2->kind==CONSTANT){
                fprintf(f,"li $t0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tli $t1, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tmult $t0, $t1");
                fprintf(f,"\n\tmflo $t2 ");
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);                

            }
            else if(q->sym3->kind==CONSTANT){
               
                fprintf(f,"li $t0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tlw $t1, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tmult $t0, $t1");
                fprintf(f,"\n\tmflo $t2");
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);              

            }

            else if(q->sym2->kind==CONSTANT){
                
                fprintf(f,"lw $t0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tli $t1, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tmult $t0, $t1");
                fprintf(f,"\n\tmflo $t2");
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);           

            }
            if(q->sym3->kind==NAMEREEL && q->sym2->kind==NAMEREEL)
            {
                fprintf(f,"lwc1 $f0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tlwc1 $f2, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tmul.s $f4, $f2, $f0");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);
            }
            else if(q->sym3->kind==REEL && q->sym2->kind==REEL){
                fprintf(f,"li.s $f0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tli.s $f2, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tmul.s $f4, $f2, $f0");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);               

            }
            else if(q->sym3->kind==REEL){
                fprintf(f,"li.s $f0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tlwc1 $f2, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tmul.s $f4, $f2, $f0");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);               

            }
            else if(q->sym2->kind==REEL){
               fprintf(f,"li.s $f0, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tlwc1 $f2, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tmul.s $f4, $f0, $f2");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);               

            }

            break;
        case BOP_DIV:
            if(q->sym3->kind==NAME && q->sym2->kind==NAME)
            {
                fprintf(f,"lw $s0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tlw $s1, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tdiv $s1, $s0");
                fprintf(f,"\n\tmflo $t2 ");
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);
            }
            else if(q->sym3->kind==CONSTANT && q->sym2->kind==CONSTANT){
                fprintf(f,"li $s0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tli $s1, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tdiv $s1, $s0");
                fprintf(f,"\n\tmflo $t2 ");
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);                

            }
            else if(q->sym3->kind==CONSTANT){
               
                fprintf(f,"li $s0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tlw $s1, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tdiv $s1, $s0");
                fprintf(f,"\n\tmflo $t2");
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);              

            }

            else if(q->sym2->kind==CONSTANT){
                
                fprintf(f,"lw $s0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tli $s1, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tdiv $s1, $s0");
                fprintf(f,"\n\tmflo $t2");
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);           

            }
            if(q->sym3->kind==NAMEREEL && q->sym2->kind==NAMEREEL)
            {
                fprintf(f,"lwc1 $f0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tlwc1 $f2, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tdiv.s $f4, $f2, $f0");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);
            }
            else if(q->sym3->kind==REEL && q->sym2->kind==REEL){
                fprintf(f,"li.s $f0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tli.s $f2, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tdiv.s $f4, $f2, $f0");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);               

            }
            else if(q->sym3->kind==REEL){
                fprintf(f,"li.s $f0, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tlwc1 $f2, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tdiv.s $f4, $f2, $f0");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);               

            }
            else if(q->sym2->kind==REEL){
               fprintf(f,"li.s $f0, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tlwc1 $f2, ");
                symbol_dump_mips(q->sym3,f);
                fprintf(f,"\n\tdiv.s $f4, $f0, $f2");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);               

            }
            break;
        case UOP_MINUS:
            if(q->sym1->kind==NAME && q->sym2->kind==NAME)
            {
                fprintf(f,"lw $t0, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tli $t1, 0");
                fprintf(f,"\n\tsub $t2, $t1, $t0");
                fprintf(f,"\n\tsw $t2, ");
                symbol_dump_mips(q->sym1,f);
            }else if(q->sym1->kind==NAMEREEL && q->sym2->kind==NAMEREEL)
            {
                fprintf(f,"lwc1 $f0, ");
                symbol_dump_mips(q->sym2,f);
                fprintf(f,"\n\tli.s $f2, 0.0");
                fprintf(f,"\n\tsub.s $f4, $f2, $f0");
                fprintf(f,"\n\tswc1 $f4, ");
                symbol_dump_mips(q->sym1,f);
            }
            break;
        case CALL_PRINT:
            if(q->sym1->kind==NAME){   
                fprintf(f,"li $v0, 1\n\tlw $a0, ");
                symbol_dump_mips(q->sym1,f);
                fprintf(f,"\n\tsyscall\n");
                fprintf(f,"\n\tli $v0, 4\n\tla $a0, enter\n\tsyscall");
            }else if(q->sym1->kind==CONSTANT){   
                fprintf(f,"li $v0, 1\n\tli $a0, ");
                symbol_dump_mips(q->sym1,f);
                fprintf(f,"\n\tsyscall\n");
                fprintf(f,"\n\tli $v0, 4\n\tla $a0, enter\n\tsyscall");
            }
            else if(q->sym1->kind==NAMEREEL){
                fprintf(f,"li $v0, 2\n\tlwc1 $f12, ");
                symbol_dump_mips(q->sym1,f);
                fprintf(f,"\n\tsyscall\n");
                fprintf(f,"\n\tli $v0, 4\n\tla $a0, enter\n\tsyscall");
            }else if(q->sym1->kind==REEL){
                fprintf(f,"li $v0, 2\n\tli.s $f12, ");
                symbol_dump_mips(q->sym1,f);
                fprintf(f,"\n\tsyscall\n");
                fprintf(f,"\n\tli $v0, 4\n\tla $a0, enter\n\tsyscall");
            }
            break;

         case CALL_PRINT_TEXT:
            fprintf(f,"li $v0, 4\n\tla $a0, text%d",i);
            fprintf(f,"\n\tsyscall\n");
            fprintf(f,"\n\tli $v0, 4\n\tla $a0, enter\n\tsyscall");
            break;
       

        case COPY:
                if(q->sym1->kind==NAME && q->sym2->kind==NAME)
                {
                    fprintf(f,"lw $t0, ");
                    symbol_dump_mips(q->sym2,f);
                    fprintf(f, "\n\tsw $t0, ");
                    symbol_dump_mips(q->sym1,f);
                }
                else if(q->sym2->kind==CONSTANT)
                {
                    fprintf(f,"li $t0, ");
                    symbol_dump_mips(q->sym2,f);
                    fprintf(f, "\n\tsw $t0, ");
                    symbol_dump_mips(q->sym1,f);   
                }
                else if(q->sym1->kind==NAMEREEL && q->sym2->kind==NAMEREEL)
                {
                    fprintf(f,"lwc1 $f0, ");
                    symbol_dump_mips(q->sym2,f);
                    fprintf(f, "\n\tswc1 $f0, ");
                    symbol_dump_mips(q->sym1,f);
                }
                else if(q->sym2->kind==REEL)
                {
                    fprintf(f,"li.s $f0, ");
                    symbol_dump_mips(q->sym2,f);
                    fprintf(f, "\n\tswc1 $f0, ");
                    symbol_dump_mips(q->sym1,f);   
                }      

            break;
        default:
            fprintf(f,"BUG\n");
            break;
    }

}





void code_dump(struct code * c)
{
    unsigned int i;
    for ( i=0 ; i<c->nextquad ; i++ )
    {
        printf("%4u | ",i);
        quad_dump(&(c->quads[i]));
        printf("\n");
    }
}




void code_dump_mips(struct code * c)
{

    int count =1;
    FILE *f=fopen("output.s","a");
    unsigned int i;
    fprintf(f,"main:\n");
    for ( i=0 ; i<c->nextquad ; i++ )
    {
        
        fprintf(f,"\t");
        fonction_tomips(&(c->quads[i]),f,count);
        if((c->quads[i].kind == CALL_PRINT_TEXT)) 
        {
            count ++;
        }
        
        fprintf(f,"\n");
    }
    fprintf(f,"\n\tli $v0, 4\n\tla $a0, enter\n\tsyscall");
    fprintf(f,"\n\tli $v0, 10\n\tsyscall");


    fclose(f);
}


void code_free(struct code * c)
{
    free(c->quads);
    free(c);
}


