// This is C version of GFG problem of Selection Sort
#include<stdio.h> 

int select(int arr[], int n)
{
    for (int k = n - 1; k >= 0; k--)
    {
        if (arr[k] > arr[n])
        {
            n = k;
        }
    }
    return n;
}
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void selection_sort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
             int j = select(arr, i);
             swap(&arr[i], &arr[j]);
    }
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main() 
{ 

    int n;
    
    printf("Input number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Input data for %d element: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nArray before sorting->\n");
    print_arr(arr, n);
    
    selection_sort(arr, n);
    
    printf("\n\nArray after sorting->\n");
    print_arr(arr, n);

    return 0; 
} 

