#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lqueue.h"

lqueue gLqueue;
char re_queue[100];

lqueue* create_lqueue(char *data)
{
    gLqueue.front = create_dllist(data);
    gLqueue.rear = gLqueue.front;

    return &gLqueue;

}

void enqueue(lqueue *q, char *data)
{
    insert_item_last(&q->front, data);

    dllitem *prev = q->front;
    while(prev->next_link != NULL)
    {
        prev = prev->next_link;
    }
    
    q->rear =prev;
}

char* dequeue(lqueue *q)
{
    strcpy(re_queue, q->front->data);
    q->front = q->front->next_link;
    remove_head(&q->front->prev_link);
    return re_queue;
}

void remove_lqueue(lqueue *q)
{
    remove_dllist(q->front);
}
void print_lqueue(lqueue *q)
{
    print_list(q->front);

}