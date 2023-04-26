#ifndef LSTACK_HEADER
#define LSTACK_HEADER

#include "dllist.h"

typedef struct lstack_info
{
    dllitem *head;
    dllitem *top;
}lstack;

lstack* create_lstack(char *data);
void push(lstack *s, char *data);
char* pop(lstack *s);
void remove_lstack(lstack *s);
void print_lstack(lstack *s);

#endif