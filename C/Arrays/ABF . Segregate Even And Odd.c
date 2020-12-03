// This is C version of GFG problem Segregate Even and Odd Numbers and This program also sorts the even and odd numbers.
#include <stdio.h>

void segregate(int [], int);
void print_arr(int [], int);
void merge_sort(int arr[], int l, int r);
void merge(int arr[], int mid, int l, int r);

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

        segregate(arr, n);

        printf("\nAfter sorting->\n");
        print_arr(arr, n);
    }
}

void swap(int *num, int *num2)
{
    int temp = *num;
    *num = *num2;
    *num2 = temp;
}
void segregate(int arr[], int n)
{
    int l = 0; 
    int r = n - 1;

    while (l < r)
    {
        while (arr[l] % 2 == 0 && l < r)
            l++;

        while (arr[r] % 2 == 1 && l < r)
            r--;

        if (l < r)
        {
            swap(&arr[l] , &arr[r]);
            l++;
            r--;
        }
    }   
    merge_sort(arr, 0, l - 1); // here I'm sorting all even numbers
    merge_sort(arr, l, n - 1);// here I'm sorting all Odd numbers
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

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\n");
}
