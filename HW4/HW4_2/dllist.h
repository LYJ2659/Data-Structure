#ifndef LLIST_HEADER
#define LLIST_HEADER

#define DATA_SIZE 20

typedef struct dllist_item
{
    struct dllist_item *prev_link;
    char data[DATA_SIZE];
    struct dllist_item *next_link;
}dllitem;

dllitem* create_dllist(char *data);
void insert_item(dllitem **head, char *data, dllitem *prev);
void insert_item_index(dllitem **head, char *data, int index);
void insert_item_last(dllitem **head, char *data);
void remove_item(dllitem **head, dllitem *target);
void remove_item_index(dllitem **head, int index);
void remove_head(dllitem **head);
void remove_item_last(dllitem **head);
void remove_dllist(dllitem *head);
void print_list(dllitem *head);

#endif