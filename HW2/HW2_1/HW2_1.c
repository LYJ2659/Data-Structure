//**************************************************
//* File Name : HW2_1.c
//* Final Edit Date : 2021. 04. 05
//* Compiler : gcc
//* Test OS : Windows 10
//* Creator : LEE YEONG JUN
//* Student ID : 12161762
//**************************************************

#define MAX_INPUT 100

#include <stdio.h>
#include <stdlib.h>

typedef struct array_info
{
    int *array;
    int size;
} array_info;

array_info read_input();
int write_output(int result);

FILE *fp_out;

//my code start **************************************************
#include  <math.h>
int nindex;
void move(int num, int from, int to)
{
    nindex++;
    printf("\n%d: Move disk %d from tower %c to tower %c", nindex, num,  from+0x40, to+0x40);
}

void hanoi_tower(int n, int from, int by, int to)
{
    if(n == 1)
    { 
        move(n, from, to);
    }
    else
    {
        hanoi_tower(n-1, from, to, by);
        move(n, from, to);
        hanoi_tower(n-1, by, from, to);
    }
}
//my code end **************************************************

int main(void)
{
    array_info input_info = read_input();

    for (int i = 0; i < input_info.size; ++i)
    {
        int disk = input_info.array[i];  // Disk count
        int count = 0;  // Total move count of disks

        // Implement Your Code
        nindex = 0;
        printf("Input n : %d", disk);
        hanoi_tower(disk, 1, 2, 3); 

        count = pow(2, disk) - 1;
        printf("\n-------------------");
        printf("\n");

        // Recommend not to modify below write ouput code
        if (write_output(count) < 0)
        {
            fprintf(stdout, "Error print output to file. Exit program...\n");

            break;
        }
    }

    fclose(fp_out);
    free(input_info.array);

    return 0;
}




// Recommend not to modify below codes

array_info read_input()
{
    int *inputs = (int*)malloc(sizeof(int) * MAX_INPUT);
    int size = 0;
    char temp[20];
    FILE *fp = fopen("in.txt", "r");
    array_info ai;

    while (!feof(fp))
    {
        fgets(temp, 20, fp);

        inputs[size++] = atoi(temp);
    }

    fclose(fp);

    ai.array = inputs;
    ai.size = size;

    return ai;
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
