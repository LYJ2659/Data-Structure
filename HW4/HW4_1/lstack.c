#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lstack.h"

lstack gLstack;
char re_data[100];

lstack* create_lstack(char *data)
{   
    gLstack.head = create_dllist(data);
    gLstack.top = gLstack.head;

    return &gLstack;
}

void push(lstack *s, char *data)
{
    insert_item_last(&s->head, data);

    dllitem *prev = s->head;
    while (prev->next_link != NULL)
    {
        prev = prev->next_link;
    }

    s->top = prev;

}

char* pop(lstack *s)
{
    strcpy(re_data, s->top->data);
    s->top = s->top->prev_link;
    remove_item_last(&s->top->next_link);
    return re_data;
}

void remove_lstack(lstack* s)
{
    remove_dllist(s->head);
}

void print_lstack(lstack* s)
{   
    print_list(s->head);

}