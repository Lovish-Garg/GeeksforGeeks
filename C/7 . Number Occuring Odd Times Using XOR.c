// This solution fails when the number comes odd times consecutive at end of array
#include <stdio.h>

int get_odd(int arr[], int n)
{
	int bit = 0;  
    for (int i = 0; i < n; i++)      
        bit = bit ^ arr[i];
    
    return bit;
}
int main(void)
{
	int t;

	printf("Testcases: ");
	scanf("%d", &t);// number of testcases

	while (t--)
	{
		int n;

		printf("Elements: ");
		scanf("%d", &n);// number of elements in array

		int arr[n];

		printf("\nInput data in array->\n");

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);// input data in array
		}		
		printf("\n%d occurs odd times\n\n", get_odd(arr, n));
	}
	return 0;
}