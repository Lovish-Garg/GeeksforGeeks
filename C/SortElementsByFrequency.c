// this program resulted 0.1 time in submition of Sort Elements By Frequency Part 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int arr[], int n);// for sorting input array
void sort2(int n, int [n][2]);// for sorting 2d count array
void print_arr(int arr[], int n, int arr2[n][2]);// print arr with the help of count array

int main(void)
{
    int t;
    scanf("%d", &t); // example 1

    while (t--)
    {
        int n;

        scanf("%d", &n);// Example 5 

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);// Input : 5 5 4 6 4 
        }

        sort(arr, n);// sorter 

        int count[n][2];
        // Initialse Variable-Length array to 0
        memset(count, 0, sizeof(count));

        for (int i = 0; i < n; i++)
        {
            count[i][0] = i;
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count[i][1]++;
                }
            }
        }

        printf("\n\n");
        sort2(n, count);
        print_arr(arr, n, count);
    }
    
}

// Selction Sort but through this we can also sort Times a number repeats and also compare its indexes to decide which number to put first
void sort2(int n, int arr[n][2])
{
    for (int i = 0; i < n; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[min][1] <= arr[j][1])
            {
                if (arr[min][1] < arr[j][1])
                {
                    min = j;
                }
                else if (arr[min][0] > arr[j][0])
                {
                    min = j;
                }
            }
        }
        int temp = arr[i][1];
        arr[i][1] = arr[min][1];
        arr[min][1] = temp;

        temp = arr[i][0];
        arr[i][0] = arr[min][0];
        arr[min][0] = temp;
    }
}

// Selection Sort
void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;

        for (int j = i; j < n; j++)
            {
                if (arr[min] >= arr[j])
                {
                    min = j;
                }    
            }
            
            int temp = arr[i];
            
            arr[i] = arr[min];
            
            arr[min] = temp;
    }
}

void print_arr(int arr[], int n, int arr2[n][2])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[arr2[i][0]]);
    }
}
