#include <stdio.h>

int get_missing(int a[], int n) 
{ 
    int num = 1; 
     
    for (int i = 2; i<= (n+1); i++)
    {
        num+=i;
        num -= a[i-2];
    }
    return num; 
} 

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

		printf("Missing Number: %d\n\n", get_missing(arr, n));
	}

	return 0;
}