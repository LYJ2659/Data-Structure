#ifndef _DSTACK_H_
#define _DSTACK_H_

typedef unsigned int uint;

typedef struct dstack
{
    uint *stack;
    size_t count;
    size_t capacity;
}dstack;

dstack create_dstack();  // Create new dynamic stack
void push(dstack*, uint);  // push value
int pop(dstack*);  // pop value. If stack is empty, return -1
int peek(dstack*);  // peek value. If stack is empty, return -1
int contains(dstack*, uint);  // Check stack contain search value. True = 1, False = 0
int isEmpty(dstack*);  // Check stack is empty. True = 1, False = 0;
void destroy_dstack(dstack*);  // Destroy dynamic stack. You must call this function end of dstack lifetime.
void print_dstack_info(dstack*);  // Print dynamic stack info

#endif