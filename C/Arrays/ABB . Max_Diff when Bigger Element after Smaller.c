#include <stdio.h>

int get_max(int arr[], int n);
int main(void)
{
	int t;

	printf("Testcases: ");
	scanf("%d", &t);

	while (t--)
	{
		// This program prints the Maximum difference between two elements such that larger element appears after the smaller number
		int n;

		printf("Input number of elements: ");
		scanf("%d", &n);

		int arr[n];

		printf("Input data in array->\n");
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		printf("\nOutput: %d\n\n", get_max(arr, n));
	}	
	return 0;
}

int get_max(int arr[], int n)
{
	if (n < 2)
		return -1;

	int max_diff = arr[1] - arr[0];
	int min_elem = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] - min_elem > max_diff)
		{
			max_diff = arr[i] - min_elem;
		}

		if (arr[i] < min_elem)
			min_elem = arr[i];
	}
	return max_diff;
}
