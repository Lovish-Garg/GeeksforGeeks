	#include <stdio.h>

	int binarySearch(int [], int, int);

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

			int num;

			printf("\nNumber: ");
			scanf("%d", &num);

			int index = binarySearch(arr, n, num);

			(index == -1) ? printf("\nNumber not found\n\n") :
							printf("\nIndex: %d\nNumber: %d\n\n", index, arr[index]);
		}
	}

	int binarySearch(int arr[], int n, int x)
	{
		int l = 0, r = n - 1;

		while (l <= r)
		{
			int mid = l + (r - l) / 2;// int mid = (l + r) / 2;

			if (arr[mid] == x)
				return mid;

			else if (arr[mid] > x)
				r = mid - 1;// number found is in left part of array

			else  
				l = mid + 1;// number found is in right part of array
		}
		return -1;// if number not found
	}
