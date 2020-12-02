// This only prints the number of elements excluding duplicates
#include <stdio.h>

void merge_sort(int arr[], int l, int r);
void merge(int arr[], int mid, int l, int r);
void printUnion(int [], int [], int, int);
int main() {
    //code
    int t;
    scanf("%d", &t);
    
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        
        int arr1[n], arr2[m];
        
        int arr[n + m], i, j;
        
        for (i = 0; i < n; i++)
        {
            scanf("%d", &arr1[i]);
            arr[i] = arr1[i];
        }
            
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr2[j]);
            arr[i + j] = arr2[j];
        }
            
        merge_sort(arr, 0, n + m - 1);
        j = 0;
        for (i = 0; i < n + m; i++)
            if (i == 0 || (arr[i] != arr[i - 1]))
                j++;     
                
        printf("%d\n", j);
    }
    return 0;
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;

        merge_sort(arr, l, mid);// divide the first half
        merge_sort(arr, mid + 1, r);// divide the second half 
        merge(arr, mid,  l, r);// merge the two halfs
    }
}

void merge(int arr[], int mid, int l, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + j + 1];

    int i = 0; 
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

