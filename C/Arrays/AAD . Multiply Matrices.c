#include <stdio.h>

void multiply( int n, int [n][n], int [n][n], int [n][n]);
void print_arr(int n, int arr[n][n]);

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

		int arr[n][n];
		printf("\nInput data for 1st array->\n");

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);

		int arr2[n][n];

		printf("\nInput data for 2nd array->\n");
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &arr2[i][j]);

		int result[n][n];

		multiply(n, arr, arr2, result);
		printf("The result array->\n");
		print_arr(n, result);
	}
}

void print_arr(int n, int arr[n][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void multiply(int n, int arr[n][n], int arr2[n][n], int result[n][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < n; k++)
				result[i][j] += arr[i][k] * arr[k][j];
		}
	}
}