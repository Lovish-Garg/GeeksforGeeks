#include <stdio.h>
#include <stdlib.h>

int get_product(int [], int);
void print_corrospond(int [], int);

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

		print_corrospond(arr, n);
	}

	return 0;
}

int get_product(int arr[], int n)
{
	int temp = 1;

	for (int i = 0; i < n; i++)
		temp *= arr[i];

	return temp;
}
void print_corrospond(int arr[], int n)
{
	int product = get_product(arr, n);

	printf("\nThe Corresponding values are->\n");
	for (int i = 0; i < n; i++)
		printf("%d ", product / arr[i]);

	printf("\n\n");
}

