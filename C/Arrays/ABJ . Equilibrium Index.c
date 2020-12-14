#include <stdio.h>

int equilibrium(int [], int);

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
		for (int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);

		int check = equilibrium(arr, n);
		
		(check == -1) ? printf("\nThere is not any Equilibrium\n\n") : printf("\nIndex: %d\nEquilibrium: %d\n\n",arr[check], check);
	}

	return 0;
}

int equilibrium(int arr[], int n)
{
	if (n == 1)
		return 0;

	int r_sum = 0;

	for (int i = 0; i < n; i++)
		r_sum += arr[i];// after all iterations r_sum will get sum of whole array

	int l_sum = 0;

	for (int i = 0; i < n; i++)
	{
		r_sum -= arr[i];

		if (r_sum == l_sum)
			return i;

		l_sum += arr[i];
	}

	return -1;
}
