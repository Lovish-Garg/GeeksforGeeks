// This program is C version of Gfg problem Number Of Occurence
#include <stdio.h>

int count(int [], int, int);
int first_occurence(int[], int, int);
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

		int occur = count(arr, n, num);

		(occur == 0) ? 	printf("\nNumber not found\n\n") : 
						printf("\nOccurence: %d\n\n", occur); 
	}
}

int count(int arr[], int n, int x) 
{
	    int occur = 0;
	    int index = first_occurence(arr, n, x);
	    
	    for (int i = index; i < n; i++)
	        if (arr[i] == x)
	            occur++;
	           
	    return occur;
}

int first_occurence(int arr[], int n, int x)// this function returns the index of first occurence where the number was found
{
	int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        
        if (arr[mid] == x)
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
                return mid;
            
            r = mid - 1;
        }
        else if (x < arr[mid])
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
}
