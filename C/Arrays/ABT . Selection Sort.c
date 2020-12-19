#include <stdio.h>

void print_arr(int [], int);
void selection_sort(int [], int);

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
		for(int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);

		printf("\nArray before Sorting->\n");
		print_arr(arr, n);

		selection_sort(arr, n);

		printf("\n\nArray after Sorting->\n");
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

void selection_sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int min_ex = i;
		for (int j = i + 1; j < n; ++j)
			if (arr[j] < arr[min_ex])
				min_ex = j;
		swap(&arr[i], &arr[min_ex]);
	}
}

void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);

}