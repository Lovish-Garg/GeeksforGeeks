// This program is the C version of gfg problem and this program finds minimum and largest number in O(n) time complexity
#include <stdio.h>

typedef struct pair
{
    int max;
    int min;
}pair;

pair get_minmax(int [], int);

int main(void)
{
    pair minmax;
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
        minmax = get_minmax(arr, n);

        printf("\nMin: %d\nMax: %d\n\n", minmax.min, minmax.max);

    }

    return 0;
}

pair get_minmax(int arr[], int n)
{
    pair minmax;
    int i;

    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            minmax.max = arr[0];
            minmax.min = arr[1];    
        }
        else 
        {
            minmax.max = arr[1];
            minmax.min = arr[0];
        }
        i = 2;
    }
    else
    {
        minmax.max = arr[0];
        minmax.min = arr[0];
        i = 1;
    }

    while (i < n - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > minmax.max)
                minmax.max = arr[i];

            if (arr[i + 1] < minmax.min)
                minmax.min = arr[i + 1];
        }
        else
        {
            if (arr[i + 1] > minmax.max)
                minmax.max = arr[i + 1];

            if (arr[i] < minmax.min)
                minmax.min = arr[i];
        }

        i += 2;
    }
    return minmax;
}
