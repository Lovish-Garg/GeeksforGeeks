/*
 The input should be n - 1 else I have handled case when the user input value more than n - 1 
 in print_repeating function but then the output may not be correct
 use this program as used on GFG website
*/
#include <stdio.h>
#include <stdlib.h>

void print_Greater(int [], int);

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

		print_Greater(arr, n);
	}

	getchar();
	return 0;
}

void print_Greater(int arr[], int n)
{
	int l = 0, r = 1;
	int product[n];
	product[n - 1] = -1;
	while (l < n)
	{
		if (r == n)
		{
			product[l++] = -1;
			r = l;
		}

		if (arr[l] < arr[r])
		{
			product[l++] = arr[r];
			r = l;
		}	
		else
			r++;
	}

	printf("\nThe Greater numbers->\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", product[i]);
	}

	printf("\n\n");
}
