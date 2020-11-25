#include <stdio.h>

int bin_search(int arr[], int l, int r, int key);

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

        int key;
        
        printf("\nNumber: ");
        scanf("%d", &key);

        printf("\nPivot Element: %d index\n\n", bin_search(arr, 0, n - 1, key));
    }
    return 0;
}

int bin_search(int arr[], int l, int r, int key)
{
    if (l > r)
    {
        return -1;
    }
    
    int mid = (l + r) / 2;
    
    if (arr[mid] == key)
    {
        return mid;
    }
    
    if (arr[l] <= arr[mid])
    {
        if (key >= arr[l] && key <= arr[mid])
        {
            return bin_search(arr, l, mid - 1, key);   
        }
        else
        {
            return bin_search(arr, mid + 1, r, key);
        }
    }
    
    if (key >= arr[mid] && key <= arr[r])
    {
        return bin_search(arr, mid + 1, r, key);
    }
    
    return bin_search(arr, l, mid - 1, key);
    
}
