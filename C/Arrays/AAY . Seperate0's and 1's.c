// This program is the C version of gfg problem and this program seperates the 0's and 1's form array in O(n) time complexity
#include <stdio.h>

void sort(int arr[], int n);
void print_arr(int arr[], int n);

int main(void)
{
    int t;

    printf("Testcases: ");
    scanf("%d", &t);

    while (t--)
    {
        int n;

        printf("Input number of elements: ");
        scanf("%d", &n);

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            do
            {
                printf("Input 0 or 1: ");
                scanf("%d", &arr[i]);   
            }
            while (arr[i] != 0 && arr[i] != 1);
            
        }

        sort(arr, n);
        printf("\nAfter sorting->\n");
        print_arr(arr, n);
    }
    
    return 0;
}

void sort(int arr[], int n)
{
    int l = 0, r = n - 1;

    while (l < r)
    {
        while (arr[l] == 0 && l < r)
            l++;
        while (arr[r] == 1 && l < r)
            r--;

        if (l < r)
        {
            arr[l] = 0;
            arr[r] = 1;
            l++;
            r--;
        }
    }
}


void print_arr(int arr[], int n)
{
    printf("Data:  ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nIndex: ");
    for (int i = 0; i < n; i++)
        printf("%d ", i);

    printf("\n\n");
}
