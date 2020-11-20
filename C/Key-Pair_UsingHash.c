#include <stdio.h>
#include <stdbool.h>
#define MAX 9999// because in question it was mentioned that max value of A[i] will be smaller tha 10 power 5

void get_sum(int [], int, int);

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

    get_sum(arr, n, num);
}

void get_sum(int arr[], int size, int x)
{
    bool hash[MAX] = {0};// initialising array to zero

    for (int i = 0; i < size; i++)
    {
        int temp = x - arr[i];

        if (hash[temp])// means if hash[temp] == 1
        {
            printf("\nThe sum of %d can be obtained by (%d, %d)\n", x, temp, arr[i]);
            return;
        }
        hash[arr[i]] = 1;
    }
}
