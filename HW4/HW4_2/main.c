#define DATA_SIZE 20
#define MAX_INPUT 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dllist.h"

FILE *fp_in;
dllitem* head;

char* read_input();
void insert_sort(char* data);
void remove_sort(dllitem* head);

int main(void)

{
    
    char *token, *delim = " ";
    int i;

    for (char *infix = read_input();  infix != NULL;  infix = read_input())
    {
        
        for (i = 0, token = strtok(infix, delim);(i < MAX_INPUT) && (token != NULL);  ++i, token = strtok(NULL, delim))
        {
			if(i == 0)
                head = create_dllist(token);
            else
                insert_sort(token);      	   	
        }

        print_list(head);
        remove_sort(head);

    }

    return 0;
}

void insert_sort(char* data)
{   
    dllitem* ik;
    char temp[100];
    char comp[100];

    strcpy(comp, data);
    
    ik = head;

    while(ik != NULL)
    {
        if(strcmp(ik->data, comp) > 0)
        {
            strcpy(temp, ik->data);
            strcpy(ik->data, comp);
            strcpy(comp, temp);
        }
        
        ik = ik->next_link;

    }

    insert_item_last(&head, comp);

}

void remove_sort(dllitem* head)
{
    remove_dllist(head);
}

char* read_input()
{
    char *s = (char*)malloc(sizeof(char) * MAX_INPUT);

    if (fp_in == NULL)
    {
        fp_in = fopen("in.txt", "r");
    }

    if (feof(fp_in))
    {
        return NULL;
    }

    fgets(s, MAX_INPUT, fp_in);

    return s;
}