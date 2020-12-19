// This program prints the number that comes odd times and when 2 numbers come odd times then program print the smaller number
#include <stdio.h>
#include <string.h>

int get_odd(int arr[], int n, int max)
{
	int hashtable[max + 1]; // here im costructing an array of max element + 1 size so that I can even store max element count
	
	
    memset(hashtable, 0, sizeof(hashtable));
    
	for (int i = 0; i < n; i++)
		hashtable[arr[i]]++;

	for (int i = 0; i <= max; i++)
	{
		if (hashtable[i] % 2 != 0)
			return i;
	}

	return -1;
}
int main(void)
{
	int t;
	
	printf("Testcases: ");
	scanf("%d", &t);

	while(t--)
	{
		int n;
		
		printf("Elements: ");
		scanf("%d", &n);

		int arr[n], max;

		printf("\nInput data in array->\n");

		scanf("%d", &arr[0]);

		max = arr[0];

		for (int i = 1; i < n; i++)
		{
			scanf("%d", &arr[i]);

			if (max > arr[i])
				max = arr[i];
		}

		printf("\n%d occurs odd times in array\n\n", get_odd(arr, n, max));
	}
	return 0;
}