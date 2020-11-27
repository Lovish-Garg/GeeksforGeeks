// This program is C version of gfg post Count inversions and speciality about this program is that it doesnot sort the actual array but give the inversions correctly.
#include <stdio.h>

int mergeSort(int [], int, int);
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

		printf("\nInversions: %d\n\n", mergeSort(arr, 0, n - 1));
	}

	return 0;
}

int merge(int arr[], int mid, int l, int r)
{
    int inv_count = 0; 
  
    int i = l; /* i is index for left subarray*/
    int j = mid; /* j is index for right subarray*/
    int k = l; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= r)) 
    { 
        if (arr[i] > arr[j])
        { 
            // if (arr[i] > arr[j] then we are doing mid - 1 inversions)
            inv_count = inv_count + (mid - i); 
            j++;
        } 
        else
        {
        	i++;
        }
        k++;
    } 
  
    return inv_count; 
}
int mergeSort(int arr[], int l, int r)
{
	if (l >= r)
		return 0;

	int inv_count = 0;

	int mid = l + (r - l) / 2;

	inv_count += mergeSort(arr, l, mid);
	inv_count += mergeSort(arr, mid + 1, r);

	inv_count += merge(arr, mid + 1, l , r);

	return inv_count;
}
