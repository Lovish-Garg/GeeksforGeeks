// This program is C version of gfg post Count inversions and speciality about this program is that it doesnot sort the actual array but give the inversions correctly.
    #include <stdio.h>
    #include <stdlib.h>

    int mergeSort(int [], int [], int, int);
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

            int *temp = (int *)malloc(sizeof(int) * n);// allocating memory for temp array
            
            printf("\nInversions: %d\n\n", mergeSort(arr, temp, 0, n - 1));
        }

        return 0;
    }

    int merge(int arr[], int temp[], int mid, int l, int r)
    {
        int inv_count = 0; 
      
        int i = l; /* i is index for left subarray*/
        int j = mid; /* j is index for right subarray*/
        int k = l; /* k is index for resultant merged subarray*/

        while ((i <= mid - 1) && (j <= r)) 
        { 
            if (arr[i] <= arr[j])
            { 
                temp[k++] = arr[i++];

            } 
            else
            {
                temp[k++] = arr[j++];
                // if (arr[i] > arr[j] then we are doing mid - 1 inversions)
                inv_count = inv_count + (mid - i);
            }
        }

        while (i <= mid - 1) 
            temp[k++] = arr[i++]; 

        while (j <= r)
            temp[k++] = arr[j++];
      
        for (int i = l; i <= r; i++)
            arr[i] = temp[i];
        return inv_count; 
    }

    int mergeSort(int arr[], int temp[], int l, int r)
    {
        if (r <= l)
            return 0;

        int inv_count = 0;

        int mid = l + (r - l) / 2;

        // divide array in two subarrays
        inv_count += mergeSort(arr, temp, l, mid);
        inv_count += mergeSort(arr, temp, mid + 1, r);

        // merging two divided arrays
        inv_count += merge(arr, temp, mid + 1, l , r);
        return inv_count;
    }
