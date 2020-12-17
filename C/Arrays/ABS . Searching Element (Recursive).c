// This is recursive approach for Gfg problem Search an Element and this program is in C
#include <stdio.h>

int binarySearch(int [], int, int, int);

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

		int index = binarySearch(arr, 0, n - 1, num);

		(index == -1) ? printf("\nNumber not found\n\n") :
						printf("\nIndex: %d\nNumber: %d\n\n", index, arr[index]);
	}
}

int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r)
	{
		int mid = l + (r - l) / 2;// int mid = (l + r) / 2;

		if (arr[mid] == x)
			return mid;

		else if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		else  
			return binarySearch(arr, mid + 1, r, x);
	}
	
	return -1;
}
