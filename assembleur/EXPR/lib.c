
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lib.h"

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

void symtable_dump(struct symtable * t, FILE* file,int k)
{
    unsigned int i;
    fprintf(file, ".data\n");
    fprintf(file, "   msg: .asciiz \"resultat :\\n\"\n");
    fprintf(file, "   retour: .asciiz \"\\n\"\n");
    name_t montemporaire;

    
    for ( i=0 ; i<t->size; i++ )
    {
        sprintf(montemporaire,"t%d",k);
      if(t->symbols[i].kind==CONSTANT){
        printf("       %p = %ld\n",&(t->symbols[i]),t->symbols[i].u.value);
        //fprintf(file,"   %s: .word ",t->symbols[i].u.value);
      }
      if(t->symbols[i].kind==NAME){
        printf("       %p = %s\n",&(t->symbols[i]),t->symbols[i].u.name);
        if(strcmp(t->symbols[i].u.name,montemporaire) == 0){

        }
        else{
            if(strcmp(t->symbols[i-1].u.name,montemporaire) == 0){
                fprintf(file,"   %s: .word 0\n",t->symbols[i].u.name);
                k++;
                 printf("k=%d",k);
            }
            else{
                fprintf(file,"   %s: .word ",t->symbols[i].u.name);
                if(t->symbols[i-1].kind==CONSTANT){
                    fprintf(file,"%ld\n",t->symbols[i-1].u.value);
                }
                else{
                    int j = i;
                    while(j >= 0 && t->symbols[i-1].kind==NAME){
                        j--;
                    } 
                    printf("j = %d",j);
                    fprintf(file,"%ld\n",t->symbols[j].u.value);
                }
            }
            
        }
        
      }
    }
    printf("       --------\n");
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

void gencode(struct code * c,enum quad_kind k,struct symbol * s1,struct symbol * s2,struct symbol * s3)
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
  name_t name;
  sprintf(name,"t%d",t->temporary);
  s = symtable_put(t,name);
  ++ (t->temporary);
  return s;
}

static void symbol_dump(struct symbol * s, FILE* file)
{
    switch ( s->kind )
    {
        case NAME:
            printf("%s",s->u.name);
            fprintf(file,"   %s: .word ",s->u.name);
            break;
        case CONSTANT:
            printf("%ld",s->u.value);
            fprintf(file,"%ld",s->u.value);
            break;
        default:
            break;
    }
}

static int quad_dump(struct quad * q, FILE* file,int k)
{
    switch ( q->kind )
    {
        case BOP_PLUS:

            fprintf(file, "    lw $t0,%s\n", q->sym2->u.name);
            fprintf(file, "    lw $t1,%s\n", q->sym3->u.name);

            fprintf(file, "    add $t2,$t0,$t1\n");
            break;
        case BOP_MINUS:

            fprintf(file, "    lw $t0,%s\n", q->sym2->u.name);
            fprintf(file, "    lw $t1,%s\n", q->sym3->u.name);

            fprintf(file, "    sub $t2,$t0,$t1\n");
            break;
        case BOP_MULT:
            symbol_dump(q->sym1,file);
            printf(" := ");
            fprintf(file," := ");
            symbol_dump(q->sym2,file);
            printf(" * ");
            fprintf(file," * ");
            symbol_dump(q->sym3,file);
            break;
        case UOP_MINUS:
            symbol_dump(q->sym1,file);
            printf(" := ");
            fprintf(file," := ");
            printf("- ");
            fprintf(file,"- ");
            symbol_dump(q->sym2,file);
            break;
        case CALL_PRINT:

            fprintf(file,"    li $v0,4 \n");
            fprintf(file,"    la $a0,msg \n");
            fprintf(file,"    syscall\n");

            fprintf(file,"    li $v0,1 \n");
            fprintf(file,"    lw $a0,%s \n",q->sym1->u.name);
            fprintf(file,"    syscall \n");


            printf("print ");
            //symbol_dump(q->sym1,file);


            fprintf(file,"    li $v0,4 \n");
            fprintf(file,"    la $a0,retour \n");
            fprintf(file,"    syscall\n ");
            break;
        case COPY:
            switch ( q->sym2->kind )
            {
                case NAME:
                if(q->sym1->u.name){
                    name_t montemporaire;
                    sprintf(montemporaire,"t%d",k);
                    if(strcmp(q->sym2->u.name,montemporaire) == 0){
                        k++;
                        fprintf(file, "    sw $t2,%s\n", q->sym1->u.name);
                    }
                    else{
                        fprintf(file, "    lw $t2,%s\n", q->sym2->u.name);
                        fprintf(file, "    sw $t2,%s\n", q->sym1->u.name);
                    }
                }
                break;
                case CONSTANT:
                break;
            }

            break;
        default:
            printf("BUG\n");
            fprintf(file,"BUG\n");
            break;
    }   
    return k;
}

void code_dump(struct code * c,FILE* file,int k)
{
    unsigned int i;

    fprintf(file,".text\n");
    fprintf(file,"main:\n");

    for ( i=0 ; i<c->nextquad ; i++ )
    {
        printf("%4u | ",i);

        k=quad_dump(&(c->quads[i]),file,k);
        printf("\n");
        fprintf(file,"\n");
    }
    fprintf(file,"    li $v0, 10\n");
    fprintf(file,"    syscall\n ");

}

void code_free(struct code * c)
{
    free(c->quads);
    free(c);
}


