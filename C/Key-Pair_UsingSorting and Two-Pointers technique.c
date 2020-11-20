// C version of GFG problem Key-Pair using Sorting and Two pointer Technique
#include <stdio.h>
#include <stdbool.h>
#define MAX 9999// because in question it was mentioned that max value of A[i] will be smaller tha 10 power 5

void get_sum(int [], int, int);
void merge_sort(int arr[], int l, int r);
void merge(int arr[], int mid, int l, int r);

int main(void)
{   
    int n;

    printf("Input number of elements in array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Input data for %d element: ", i);
        scanf("%d", &arr[i]);
    }

    int num;

    printf("\nInput the sum for two elements in array: ");
    scanf("%d", &num);

    merge_sort(arr, 0, n - 1);

    get_sum(arr, n, num);
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

void get_sum(int arr[], int size, int x)
{
    int left = 0, right = size - 1;
   
    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == x)
        {
            printf("\nThe sum of %d can be obtained by (%d, %d)\n", x, arr[left], arr[right]);
            return;
        }
        
        else if (x > sum)// as array is sorted It means that arr[left] has low value and we should increment it by left++ and this means point to the next number in array
            left++;

        else 
            right--;
    }
    printf("\n%d not found\n", x);// when we donot found any x as sum of 2 numbers in array
}
