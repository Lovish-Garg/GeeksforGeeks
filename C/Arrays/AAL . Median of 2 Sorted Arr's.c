// This program is the C version of gfg problem O(n) time complexity
#include <stdio.h>

int get_mid(int [], int [], int);

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

        int arr1[n];

        printf("\nInput data in first array->\n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr1[i]);   
        }

        int arr2[n];

        printf("\nInput data in second array->\n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr2[i]);   
        }

        printf("\nMid: %d\n\n", get_mid(arr1, arr2, n));
    }

    return 0;
}

int get_mid(int arr1[], int arr2[], int n)
{
    // for storing mids
    int m1 = -1, m2 = -1;

    // as indexes of arr1 and arr2
    int i = 0, j = 0;

    for (int k = 0; k <= n; k++)
    {
        if (i == n)
        {
            m1 = m2;
            m2 = arr2[0];
            break;
        }

        else if (j == n)
        {
            m1 = m2;
            m2 = arr1[0];
            break;
        }

        if (arr1[i] <= arr2[j])
        {
            m1 = m2;
            m2 = arr1[i];
            i++;
        }

        else
        {
            m1 = m2;
            m2 = arr2[j];
            j++;
        }
    }

    return (m1 + m2) / 2;
}
