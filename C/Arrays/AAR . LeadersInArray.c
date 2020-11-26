// In Geeks for Geeks there isnot any option of C, So I make the C code for that problem
#include <stdio.h>

void print_leader(int arr[], int n);

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

        printf("Input data in array->\n");

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        printf("\nLeader elements->\n");
        print_leader(arr, n);    
    }
    
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
    printf("%d\n\n", max);
}
