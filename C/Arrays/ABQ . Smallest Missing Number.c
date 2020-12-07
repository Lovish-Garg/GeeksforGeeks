// this program finds the smallest misisng number from 0 to n - 1
#include <stdio.h>

int binary_search(int [], int, int);
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

		printf("\nSmallest Missing Number: %d\n\n",  binary_search(arr, 0, n - 1));
	}
}

int binary_search(int arr[], int l, int r)
{	
	if (l > r)
		return r + 1;

	if (l != arr[l])
		return l;

	int mid = l + (r - l) / 2;

	if (arr[mid] == mid)
		return binary_search(arr, mid + 1, r);

	return binary_search(arr, l, mid);
}
