//**************************************************
//* File Name : HW2_2.c
//* Final Edit Date : 2021. 04. 05
//* Compiler : gcc
//* Test OS : Windows 10
//* Creator : LEE YEONG JUN
//* Student ID : 12161762
//**************************************************

#define MAX_INPUT 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct input_info
{
    int *array;
    int size;
    int target;
}input_info;

input_info read_input();
int write_output(int result);

FILE *fp_in;
FILE *fp_out;

// my code start***************************************
int BSearch(int ar[], int len, int target)
{
    int first = 0;
    int last = len - 1;
    int mid;
 
    while(first <= last)
    {
        mid = (first + last)/2; 
  
        if(target == ar[mid]) 
        {
            return mid; 
        }
        else 
        {
            if(target < ar[mid]) 
            { 
                last = mid - 1; 
            }
            else
            { 
                first = mid + 1; 
            }
        }
    }
    return -1;
}
//my code end ***************************************



int main(void)
{
    input_info info = read_input();

    while (info.size > 0)
    {
        int *array = info.array;
        int array_size = info.size;
        int search_target = info.target;
        int find_index = -1;  // Find result

        // Implement Your Code

        find_index = BSearch(array, array_size, search_target);
        printf("\n search number = %d   index = %d",search_target,  find_index);
        
        // Recommend not to modify below I/O code
        if (write_output(find_index) < 0)
        {
            fprintf(stdout, "Error print output to file. Exit program...\n");

            break;
        }

        free(info.array);

        info = read_input();
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}




// Recommend not to modify below codes

input_info read_input()
{
    int *array = (int*)malloc(sizeof(int) * MAX_INPUT);
    char array_input[MAX_INPUT], target_input[MAX_INPUT];
    char *token, *delim = " ";
    int temp2, i;
    input_info ii;

    if (fp_in == NULL)
    {
        fp_in = fopen("in.txt", "r");
    }

    if (feof(fp_in))
    {
        ii.size = -1;

        return ii;
    }

    fgets(array_input, MAX_INPUT, fp_in);
    fgets(target_input, MAX_INPUT, fp_in);

    for (i = 0, token = strtok(array_input, delim); 
        (i < MAX_INPUT) && (token != NULL);
        ++i, token = strtok(NULL, delim))
    {
        array[i] = atoi(token);
    }

    ii.array = array;
    ii.size = i;
    ii.target = atoi(target_input);

    return ii;
}

int write_output(int result)
{
    int statusCode;

    if (fp_out == NULL)
    {
        fp_out = fopen("out.txt", "w");
    }

    statusCode = fprintf(fp_out, "%d\n", result);

    fflush(fp_out);

    return statusCode;
}
