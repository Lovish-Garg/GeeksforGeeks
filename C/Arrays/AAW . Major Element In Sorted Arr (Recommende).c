// This program prints the majority Element 
#include <stdio.h>

int get_major(int [], int, int);

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

        int num;

        printf("\nNumber: ");
        scanf("%d", &num);

        int check =  get_major(arr, n, num);

        (check != -1) ? printf("\nMajor Element: %d\n\n", arr[check]) : printf("\nNo Major Element\n\n");
    }
    return 0;
}

int binary_search(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if ((arr[mid] == x) && (mid == 0 || arr[mid - 1] < arr[mid]))
            return mid;

        else if (x > arr[mid])
            l = mid + 1;

        else
            r = mid - 1;
    }
    return -1;
}

int get_major(int arr[], int n, int x)
{
    int i = binary_search(arr, 0, n - 1, x);
        
    if (i == -1)
        return -1;

    if ((i + n / 2) <= (n - 1) && arr[i + n / 2] == x)
        return i;

    return -1;
}
