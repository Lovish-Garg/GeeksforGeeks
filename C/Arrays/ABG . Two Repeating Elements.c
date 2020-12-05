/*
 The input should be n - 1 else I have handled case when the user input value more than n - 1 
 in print_repeating function but then the output may not be correct
 use this program as used on GFG website
*/
#include <stdio.h>
#include <stdlib.h>

void print_repeating(int [], int);

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
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		print_repeating(arr, n);
	}

	return 0;
}

void print_repeating(int arr[], int n)
{
	if (n < 3)
	{
		if (n == 2)
		{
			if (arr[0] == arr[1])
				printf("Repeating element->\n%d", arr[0]);
			else
				printf("No Repeating Elements");
		}
		printf("\n\n");
		return ;
	}

	int *count = (int *)calloc(sizeof(int), (n - 2)); 
	int i; 
	   
	printf(" Repeating elements are->\n"); 
	for(i = 0; i < n; i++) 
	{
	  	if(count[arr[i]] == 1) 
	    	printf("%d ", arr[i]); 
	    else
	    	count[arr[i]]++; 
	}   
	printf("\n\n");
}
