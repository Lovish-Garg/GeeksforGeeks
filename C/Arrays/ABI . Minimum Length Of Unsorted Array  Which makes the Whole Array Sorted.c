#include <stdio.h>
#include <stdlib.h>

void print_index(int [], int);

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

		print_index(arr, n);
	}

	getchar();
	return 0;
}

void print_index(int arr[], int n)
{
	int l;
	for (l = 0; l < n - 1; l++)// this loop gives us the index till where our array is already sorted
		if (arr[l] > arr[l + 1])// if (5 > 2)
			break;

	if (l == n - 1)
	{
		printf("\nThe whole array is sorted\n\n");
		return;
	}

	int r;
	for (r = n - 1; r > 0; r--)// this will give us the index from back till where our array is sorted
		if (arr[r] < arr[r - 1])// if (2 > 5)
			break;

	int max = arr[l], min = arr[l];

	for (int i = l + 1; i <= r; i++)
	{
		if (arr[i] > max)
			max = arr[i];

		if (arr[i] < min)
			min = arr[i];
	}

	for (int i = 0; i < n; i++)
		if (arr[i] > min)
		{
			l = i;
			break;
		}

	for (int i = n - 1; i >= 0; i--)
		if (arr[i] < max)
		{
			r = i;
			break;
		}

	printf("\nUnsorted Array: %d to %d\n\n", l, r);
}
