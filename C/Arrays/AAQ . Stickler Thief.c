#include <stdio.h>

int get_sum(int arr[], int n)
{
    int num1 = arr[0], num2 = 0, third;
    
    for (int i = 1; i < n; i++)
    {
        third = (num1 > num2) ? num1 : num2;
        
        num1 = num2 + arr[i];
        num2 = third;
    }
    
    return (num1 > num2) ? num1 : num2;     
}

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
            scanf("%d", &arr[i]);
            
        printf("%d\n\n", get_sum(arr, n));
    }
    return 0;
}