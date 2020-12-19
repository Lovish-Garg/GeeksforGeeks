#include <stdio.h>
#include <stdlib.h>

#define STACK 100// stack size

typedef struct node
{
	int top;
	int items[STACK];
}node;


void nextGreater(int [], int);

int main(void)
{
	int t;

	printf("Testcases: ");
	scanf("%d", &t);

	while (t--)
	{
		int n;

		printf("Elements: ");
		scanf("%d", &n);

		int arr[n];

		printf("\nInput data in array->\n");
		for (int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);
		
		nextGreater(arr, n);

		printf("\n");
	}
	
}

int isFull(node *stack)
{	
	return stack->top == STACK - 1;
}

int isEmpty(node *stack)
{
	return stack->top == -1;
}

void push(node *stack, int data)
{
	if (isFull(stack))
	{
		printf("\nStack Overflow\n");
		exit(0);
	}

	stack->top += 1;
	stack->items[stack->top] = data;
}	

// This function returns the topmost elements in stack
int pop(node *stack)
{	
	if (isEmpty(stack))
	{
		printf("\nStack Unferflow\n");
		exit(0);
	}

	int num = stack->items[stack->top];// number to return
	stack->top -= 1;

	return num;
}

void nextGreater(int arr[], int n)
{	
	if (n == 0)
		return;
	
	node stack;

	stack.top = -1;

	push(&stack, arr[0]);

	for (int i = 1; i < n; ++i)
	{
		int now = arr[i];
		int popped;
		 
		if (!isEmpty(&stack))
		{
			popped = pop(&stack);

			while (popped < now)
			{
				printf("%d --- %d\n", popped, now);

				if (isEmpty(&stack))
					break;
				
				popped = pop(&stack);
			}

			if (popped > now)
				push(&stack, popped);
		}

		push(&stack, now);
	}

	while (!isEmpty(&stack)) 
    { 
        int popped = pop(&stack); 
        int  now = -1; 
        printf("%d -- %d\n", popped, now); 
    } 
}
