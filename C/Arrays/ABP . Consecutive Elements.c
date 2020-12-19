// This is C version of GFG problem Consecutive array elements
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int get_consecutive(int [], int);
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

		int check = get_consecutive(arr, n);

		(check == true) ? printf("\nThe array is consecutive\n\n") : printf("\nThe array is not consecutive\n\n");

	}
}


int get_min(int arr[], int n)
{
	int min = arr[0];

	for (int i = 0; i < n; i++)
		if (arr[i] < min)
			min = arr[i];

	return min;
}

int get_max(int arr[], int n)
{
	int max = arr[0];

	for (int i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];

	return max;
}

int get_consecutive(int arr[], int n)
{
	if (n < 1)
		return false;

	int min = get_min(arr, n);
	int max = get_max(arr, n);

	bool *count = (bool *)calloc(n, sizeof(int));// default value will be false

	if (max - min + 1 == n)
	{
		for(int i = 0; i < n; i++)
		{
			if (count[arr[i] - min] == true)// it means we have a duplicate number and it is noy right
				return false;

			count[arr[i] - min] = true;// else it means that we have found this number first time and we are marking this.
		}
		free(count);
		return true;
	}
	free(count);
	return false;
}
