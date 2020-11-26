// This program prints the majority Element but it cannot be accurate as it only checks the arr[n / 2 + 1] element but time complexity is O(1) 
// That's why there is another solution for this program using Binary Search
#include <stdio.h>

int get_major(int [], int);

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

        printf("Input data in array->\n");// Input should be sorted as the problem is Find Majority Element in Sorted Array.
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        printf("\nMajor: %d\n\n", get_major(arr, n));
    }

    return 0;
}

int get_major(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    if (n == 2)
    {
        if (arr[1] == arr[0])
            return arr[0];
        else
            return -1;
    }
        
    if (arr[0] <= arr[n / 2 + 1])
        return arr[n / 2 + 1];

    return -1;

}
