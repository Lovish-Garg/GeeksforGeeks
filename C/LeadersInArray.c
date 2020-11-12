#include <stdio.h>

void print_leader(int arr[], int n);

int main(void)
{
    int n;

    printf("Input size of the array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Input data for %d element: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nLeader elements in array are-> ");
    print_leader(arr, n);
}

void print_leader(int arr[], int n)
{
    int max = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)// scanning the array from right side and when we found a number greater than the max then we print it and max[i].
    {
        if (arr[i] >= max)
        {
            printf("%d ", max);
            max = arr[i];
        }
    }
    printf("%d ", max);
}
