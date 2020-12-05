/*
 The input should be n - 1 else I have handled case when the user input value more than n - 1 
 in print_repeating function but then the output may not be correct
 use this program as used on GFG website
*/
#include <stdio.h>
#include <stdlib.h>

void sort012(int [], int);
void print_arr(int [], int);

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
			do// this do while loop is for when user input number != 0 || != 1 || != 2 
			{
				scanf("%d", &arr[i]);
			}
			while (arr[i] != 0 && arr[i] != 1 && arr[i] != 2);

		sort012(arr, n);

		printf("\nAfter sorting->\n");
		print_arr(arr, n);
	}

	return 0;
}

void swap(int *num, int *num2)
{
	int temp = *num;
	*num = *num2;
	*num2 = temp;
}

void sort012(int arr[], int n)
{
	int i = 0;
	int m = 0;
	int r = n - 1;

	while (m < r)
	{
		switch(arr[m])
		{
			case 0:
			swap(&arr[i++], &arr[m++]);
				break;

			case 1:
				m++;
				break;

			case 2:
			swap(&arr[m], &arr[r--]);
				break;
		}
	}
}

void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n\n");
}
