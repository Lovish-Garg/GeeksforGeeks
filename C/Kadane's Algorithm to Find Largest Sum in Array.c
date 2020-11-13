/* This program make use of Kadane's Algorithm
 This algorithm doesnot work when all the numbers in array 
 are negative
*/
#include <stdio.h>

int sub_arr(int arr[], int n);

int main(void)
{
    int n;

    printf("Input the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Input data for %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nThe sum of largest subarray is %d\n", sub_arr(arr, n));
}

int sub_arr(int arr[], int n)
{
    int max_end = 0, max_start= 0;

    for (int i = 0; i < n; i++)
    {
        max_end += arr[i];
    /*  
        If max_end += arr[i] on line 33 results in a negative number, then we make max_end  0.
    */
        if (max_end < 0) 
        {
            max_end = 0;
        }
    /*
        If max_end > max_start then we assign max_start max_send . In this way the largest sum preserves if it is in the start or middle of the array.  
    */
        else if (max_start < max_end)
        {
            max_start = max_end;
        }
    }

    return max_start;
}
