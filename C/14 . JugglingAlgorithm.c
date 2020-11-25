#include <stdio.h>

int gcd_count(int a, int b);
void print_arr(int arr[], int n);
void leftrotate(int arr[], int d, int n);

int main() {
    //code
    int t;

    printf("Testcases: ");
    scanf("%d", &t);
    
    while (t--)
    {
        int n, d;

        printf("Elements and Elements to shift: ");
        scanf("%d%d", &n, &d);

        int arr[n];

        printf("Input data in array->\n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        leftrotate(arr, d, n);

        printf("\nAfter rotation->\n");
        print_arr(arr, n);
    }

    return 0;
}


void leftrotate(int arr[], int d, int n)
{
    d = d % n;

    int gcd = gcd_count(d, n);
    for (int i = 0; i < gcd; i++) { 
     /* move i-th values of blocks*/
        int temp = arr[i]; 
        int j = i; 
        while (1) { 
            int k = j + d; 
            if (k >= n) 
                k = k - n; 
            if (k == i) 
                break; 
            arr[j] = arr[k]; 
            j = k; 
        } 
        arr[j] = temp; 
    } 

}

int gcd_count(int a, int b)
{
    int temp;

    while (b)
    {
        temp = a;
        a = b; 
        b = temp % b;
    }
    return a;
}


void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}
