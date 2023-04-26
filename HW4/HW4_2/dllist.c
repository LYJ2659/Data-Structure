#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dllist.h"

dllitem* create_dllist(char *data)
{
    dllitem *node = (dllitem*)malloc(sizeof(dllitem));

    strcpy(node->data, data);

    node->prev_link = NULL;
    node->next_link = NULL;

    return node;
}

// If prev is NULL, insert & change head
void insert_item(dllitem **head, char *data, dllitem *prev)
{
    if (*head == NULL)
    {
        *head = create_dllist(data);
    }
    else
    {
        dllitem *node = (dllitem*)malloc(sizeof(dllitem));

        strcpy(node->data, data);

        if (prev == NULL)
        {
            node->prev_link = NULL;
            node->next_link = *head;

            (*head)->prev_link = node;

            *head = node;
        }
        else
        {
            node->prev_link = prev;
            node->next_link = prev->next_link;

            if (prev->next_link != NULL)
            {
                prev->next_link->prev_link = node;
            }

            prev->next_link = node;
        }
    }
}

void insert_item_index(dllitem **head, char *data, int index)
{
    dllitem *prev = NULL;
    dllitem *node;

    // Find prev data with index
    for (int i = 0; i < index; ++i)
    {
        if (prev == NULL)
        {
            prev = *head;
        }
        else
        {
            if (prev->next_link == NULL)
            {
                break;
            }
            else
            {
                prev = prev->next_link;
            }
        }
    }
    
    insert_item(head, data, prev);
}

void insert_item_last(dllitem **head, char *data)
{
    dllitem *prev = *head;
    dllitem *node;

    if (prev == NULL)
    {
        *head = create_dllist(data);
    }
    else
    {
        while (prev->next_link != NULL)
        {
            prev = prev->next_link;
        }

        node = (dllitem*)malloc(sizeof(dllitem));

        strcpy(node->data, data);

        node->prev_link = prev;
        node->next_link = NULL;

        prev->next_link = node;
    }
}

// If target is NULL, no operation
void remove_item(dllitem **head, dllitem *target)
{
    if (target != NULL)
    {
        if (target->prev_link != NULL)
        {
            target->prev_link->next_link = target->next_link;
        }
        else
        {
            remove_head(head);

            return;
        }

        if (target->next_link != NULL)
        {
            target->next_link->prev_link = target->prev_link;
        }

        free(target);
    }
}

void remove_item_index(dllitem **head, int index)
{
    dllitem *target = *head;

    // Find target
    for (int i = 0; i < index; ++i)
    {
        if (target->next_link == NULL)
        {
            break;
        }
        else
        {
            target = target->next_link;
        }
    }

    remove_item(head, target);
}

void remove_head(dllitem **head)
{
    dllitem *old_head = *head;

    *head = (*head)->next_link;

    (*head)->prev_link = NULL;

    free(old_head);
}

// If head is NULL, no operation
void remove_item_last(dllitem **head)
{
    dllitem *target = *head;

    if (target == NULL)
    {
        return;
    }

    while (target->next_link != NULL)
    {
        target = target->next_link;
    }

    if (target->prev_link == NULL)
    {
        remove_head(head);
    }
    else
    {
        target->prev_link->next_link = NULL;
    }

    free(target);
}

void remove_dllist(dllitem *head)
{
    dllitem *now = head;
    dllitem *next;

    while (now != NULL)
    {
        next = now->next_link;

        free(now);

        now = next; 
    }
}

void print_list(dllitem *head)
{
    dllitem *temp = head;

    printf("--Print Linked List Items--\n");

    while (temp != NULL)
    {
        printf("%s\n", temp->data);

        temp = temp->next_link;
    }

    printf("\n");
}