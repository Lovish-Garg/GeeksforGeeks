#include <stdio.h>

void print_arr(int arr[], int n) ;
void reverse_arr(int [], int, int);
void leftrotate(int arr[], int d, int n);

int main(void)
{
    int t;

    printf("Testcases: ");
    scanf("%d", &t);

    while (t--)
    {
        int n, d;

        printf("Elements and Elements to shift: ");
        scanf("%d%d", &n, &d);

        int arr[n];

        printf("\nInput data in array->\n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        leftrotate(arr, d, n);

        printf("\nAfter array rotation->\n");

        print_arr(arr, n);
    
    }
    
}

void leftrotate(int arr[], int d, int n)
{   
    if (d == 0)
        return;

    d = d % n;
    /*
        Here the logic is just like an array is 
        Numbers: 1 | 2 | 3 | 4 
        Indexes: 0 | 1 | 2 | 3 
        
        And we need to shift 2 numbers then, 
        
        reversing first two numbers result in 
        2 1 3 4
        reversing other left numbers result in 
        2 1 4 3
        Then reversing the whole array result in 
        3 4 1 2
    */
    reverse_arr(arr, 0, d - 1);
    reverse_arr(arr, d, n - 1);
    reverse_arr(arr, 0, n - 1);
}

void reverse_arr(int arr[], int start, int end)
{
    int temp;

    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void print_arr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 

    printf("\n\n");
} 
