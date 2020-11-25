#include <stdio.h>

int get_index(int arr[], int l, int r, int num)
{
	while (l <= r)
	{
		if (arr[l] == num)
			return l;

		else if (arr[r] == num)
			return r;

		else
			get_index(arr, ++l, --r, num);
	}
	return -1;
}

int main(void)
{
	int t, num;
	printf("Testcases and number: ");
	scanf("%d%d", &t, &num);// First input testcases then number to search

	while (t--)
	{
		int n;
		printf("Elements: ");
		scanf("%d", &n);// input number of elements

		int arr[n];


		printf("\nInput data in array->\n");

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);// input data in array
		}

		printf("\n%d is at %d index\n\n", num, get_index(arr, 0, n - 1, num));// result
	}

	return 0;
}