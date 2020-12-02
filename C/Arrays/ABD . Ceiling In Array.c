#include <stdio.h>

int get_ceiling(int [], int, int);

int main() {
    //code
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

        int check = get_ceiling(arr, n, num);

        (check == -1) ? printf("\nCeiling of %d doesnot exist\n\n", num) : 
                        printf("Ceiling: %d\n\n", arr[check]);
    }
    return 0;
}

int get_ceiling(int arr[], int n, int x)
{
    int l = 0, r = n - 1;

    while (l < r)
    {
        if (arr[r] < x)
            return -1;

        if (arr[l] >= x)
            return x;

        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (x > arr[mid])
        {
            if ((mid + 1 <= r) && arr[mid + 1] >= x)
                return mid + 1;
            else
                l = mid + 1;
        }
        else
        {
            if (mid - 1 >= l && x > arr[mid - 1])
                return mid;

            r = mid - 1;
        }
    } 
    return -1;
}
