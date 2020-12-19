// This program implements Bubble-Sort Algorithm for Sorting
#include <stdio.h>

void bubble_sort(int [], int);
void print_arr(int [], int );

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

		printf("\nInput data in aray->\n");
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		printf("\nArray before sorting->\n");
		print_arr(arr, n);

		bubble_sort(arr, n);

		printf("\n\nArray after sorting->\n");
		print_arr(arr, n);

		printf("\n\n");
	}
}

void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void bubble_sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - i - 1; ++j)// because after each i++ we are getting last elements as Ith smallest in array
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
}