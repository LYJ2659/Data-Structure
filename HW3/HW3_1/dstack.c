#include <stdio.h>
#include <stdlib.h>

#include "dstack.h"

#define STACK_CAPA 5

dstack dstk;

dstack create_dstack()
{
    dstk.capacity = STACK_CAPA;
    dstk.count = 0;
    dstk.stack = (uint *) malloc(sizeof(unsigned int) * STACK_CAPA); 
    return dstk;

}

void push(dstack* dk, uint val)
{
    if(dk->count > (dk->capacity - 1))
    {
        printf("-- count %d capa %d \n", dk->count, dk->capacity);
        dk->capacity += STACK_CAPA;

        dk->stack = (uint *) realloc(dk->stack, sizeof(unsigned int) * dk->capacity);
        printf("Memory reallocation");
        printf("Stack size added... size : %d\n", dk->capacity);
        
        push(dk, val);
        dk->count++;

    }
    else
    {
        dk->stack[dk->count] = val;
        dk->count++;
        
    }
}

int pop(dstack* dk)
{
    uint val;
    if(isEmpty(dk))
    {
        return -1;
    }
    
    dk->count--;
    val = dk->stack[dk->count];
    return val;

}

int peek(dstack* dk)
{
    if(isEmpty(dk))
    {
        return -1;
    }
    return dk->stack[dk->count-1];
}

int contains(dstack* dk, uint val)
{
    for(int i = 0; i < dk->count; i++)
    {
        if(dk->stack[i] == val)
            return 1;
    }
    return 0;
}

int isEmpty(dstack* dk)
{
    if(dk->count == 0)
    {
        printf("Error: stack is empty \n");
        return 1;
    }
    return 0;
}

void destroy_dstack(dstack* dk)
{
    
       free(dk -> stack);
    
}





// You don't need to modify below code

void print_dstack_info(dstack *p_dstack)
{
    printf("Stack : ");

    for (int i = 0; i < p_dstack->count; ++i)
    {
        printf("%d ", p_dstack->stack[i]);
    }
    
    printf("\nCount : %ld\n", p_dstack->count);
    printf("Capacity : %ld\n\n", p_dstack->capacity);
}