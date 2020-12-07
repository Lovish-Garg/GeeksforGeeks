// This program is C version of gfg problem Equilibrium index
#include <stdio.h>
#include <stdlib.h>

void Equilibrian(int [], int);

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

		Equilibrian(arr, n);
	}

	getchar();
	return 0;
}

void Equilibrian(int arr[], int n)
{
	if (n == 1)
	{
		printf("\nEquilibrium: %d\n\n", 1);
		return;
	}

	int sum = 0, l_sum = 0;

	for (int i = 0; i < n; i++)
		sum += arr[i];

	for (int i= 0; i < n; i++)
	{
		sum -= arr[i];// in this way we are getting the sum of right side elements

		if (l_sum == sum)
		{
			printf("\nEquilibrium: %d\n\n", i);
			return;
		}
		l_sum += arr[i];
	}
	printf("\nNo Equilibrium\n\n");// means we didnot find Equilibrium
}
