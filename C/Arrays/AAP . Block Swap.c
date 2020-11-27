#include <stdio.h>

void print_arr(int [], int);
void leftrotate(int [], int, int);

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
		{
			scanf("%d", &arr[i]);
		}

		int d;
		printf("Numbers by which to rotate: ");
		scanf("%d", &d);
		
		leftrotate(arr, d, n);

		printf("\nAfter rotating->\n");
		print_arr(arr, n);
	}
	return 0;
}

void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		fprintf(stdout, "%d ", arr[i]);
	}
	printf("\n\n");
}
void swap(int arr[], int fi, int si, int d)// fi = 0 || si = 3 || d = 3
{
	for (int i = 0; i < d; i++)
	{
		int temp = arr[fi + i];
		arr[fi + i] = arr[si + i]; 
		arr[si + i] = temp;
	}
}

void leftrotate(int arr[], int d, int n)
{
	if (d == 0 || d == n)
		return;

	int i = d;// 3
	int j = n - d;// 5 - 3 = 2

	while (i != j)
	{	
		if (i < j)
		{
			swap(arr, d - i, d + j - i, i);
			j -= i;
		}
		else
		{
			swap(arr, d - i, d, j);
			i -= j;
		}
	}

	swap(arr, d - i, d, i);
}