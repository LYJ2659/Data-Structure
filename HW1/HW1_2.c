//**************************************************
//* File Name : HW1_2.c
//* Final Edit Date : 2021. 03. 21
//* Compiler : gcc
//* Test OS : Windows 10
//* Creator : LEE YEONG JUN
//* Student ID : 12161762
//* File Name : HW1_2.c
//* File Name : HW1_2.c
//**************************************************

#include <stdio.h>
#include <stdlib.h> 


int main(void)
{
    
    
    int *A = (int *)malloc(sizeof(int));
    *A = 5;
    
    int *C = (int *)malloc(sizeof(int));
    *C = *A - 1;
       
    int **B = &A;
   
    printf("Result A, B, C :  %d  %d  %d\n", *A,  **B, *C);

    printf("Result Address :  %p  %p  %p\n", &A,  B, &C);

    free(A);
    free(C);

    return 0;
}




