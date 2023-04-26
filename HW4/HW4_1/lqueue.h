#ifndef LQUEUE_HEADER
#define LQUEUE_HEADER

#include "dllist.h"

typedef struct lqueue_info
{
    dllitem *front;
    dllitem *rear;
}lqueue;

lqueue* create_lqueue(char *data);
void enqueue(lqueue *q, char *data);
char* dequeue(lqueue *q);
void remove_lqueue(lqueue *q);
void print_lqueue(lqueue *q);

#endif