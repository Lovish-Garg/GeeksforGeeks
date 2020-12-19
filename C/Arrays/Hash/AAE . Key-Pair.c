// This is C version of GFG problem Key-Pair
#include <stdio.h>
#include <stdbool.h>
#define MAX 9999// because in question it was mentioned that max value of A[i] will be smaller tha 10 power 5

void get_sum(int [], int, int);

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
        
        int num;

        printf("\nNumber: ");
        scanf("%d", &num);

        get_sum(arr, n, num);    
    }
    return 0;
}

void get_sum(int arr[], int size, int x)
{
    bool hash[MAX] = {0};// initialising array to zero

    for (int i = 0; i < size; i++)
    {
        int temp = x - arr[i];
        /*
            Example we have arr[i] = 7 then if x = 10
            x - 7 = 3
            then if hash[temp] or hash[3] which means 3 is in array
            Then we can print the temp and the arr[i]
        */

        if (hash[temp])// means if hash[temp] == 1
        {
            printf("\nThe sum of %d can be obtained by (%d, %d)\n\n", x, temp, arr[i]);
            return;
        }
        hash[arr[i]] = 1;
    }
    printf("\nThe sum of %d can't be obtained\n\n", x);
}
