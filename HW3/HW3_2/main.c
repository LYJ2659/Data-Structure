#define MAX_INPUT 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_input();

FILE *fp_in;

char stack[MAX_INPUT];
int top = -1;

void push(char num) 
{
	if (top >= MAX_INPUT) 
    {
		printf("\nstack overflow");
		return;
	}
	stack[++top] = num;
}

char pop() 
{
	if (top <= -1) 
    {
		printf("\n no stack");
		return -1;
	}
	return stack[top--];
}

char return_top() 
{
	if (top <= -1)
		return -1;

	return stack[top];
}

void init_stack() 
{ 
    top = -1; 
}

int is_stack_empty() 
{ 
    return (top <= -1); 
}

int is_operator(char num) 
{ 
    return (num == '+' || num == '-' || num == '*' || num == '/'); 
}

int is_num(char num) 
{ 
    return (num >= '0' && num <= '9'); 
}

int is_Lalphabet(char num) 
{ 
    return (num >= 'A' && num <= 'Z');
	
}

int is_Salphabet(char num) 
{ 
	return (num >= 'a' && num <= 'z');
}

int operator_priority(char num) 
{
	if (num == '(')
		return 0;
	if (num == '+' || num == '-')
		return 1;
	if (num == '*' || num == '/')
		return 2;
	if (num == ')')
		return 3;
	return -1;
}

int main(void)
{
    char dest[MAX_INPUT];
    char *token, *delim = " ";
    int temp2, i;

    for (char *infix = read_input();
        infix != NULL;
        infix = read_input())
    {
        temp2 =0;
		init_stack();
		printf("\n Infix : ");
		printf("%s\n", infix);

        for (i = 0, token = strtok(infix, delim);(i < MAX_INPUT) && (token != NULL);  ++i, token = strtok(NULL, delim))
        {
			
      	   	if (is_num(*token))
        	{
				dest[temp2++] = *token;
			}
			else if(is_Lalphabet(*token))
			{
				dest[temp2++] = *token;
			} 
			else if(is_Salphabet(*token))
			{
				dest[temp2++] = *token;	
			} 
			else if (*token == '(')
			{
				push(*token);
			}
			else if (*token == ')') 
			{
				while (return_top() != '(') 
				{
					dest[temp2++] = pop();
				}
				pop();
			}
			else if (is_operator(*token))
			{
				
				if (is_stack_empty())
				{
					push(*token);
					
				}
				else
				{
					
					if (operator_priority(*token) > operator_priority(return_top())) 
					{
						push(*token);
					}
					else 
					{
						dest[temp2++] = pop();
						push(*token);
					}
				}
			}
			else 
			{
				printf("\n no recognization character.");
			}
        }

		
		while (!is_stack_empty()) 
		{
			dest[temp2++] = pop();
		}
		dest[temp2] = '\0';

		printf("Postfix : ");
		printf("%s\n", dest);
       
       free(infix);

    }
}




// Recommend not to modify below code
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