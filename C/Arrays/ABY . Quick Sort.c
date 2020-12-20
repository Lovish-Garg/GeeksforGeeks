#include <stdio.h>

void print_arr(int [], int);
int partition(int [], int, int);
void quick_sort(int [], int, int);

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

        printf("\nInput data in array->\n");
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);

        printf("\nArray before sorting->\n");   
        print_arr(arr, n);

        quick_sort(arr, 0, n - 1);
        
        printf("\n\nArray after sorting->\n");   
        print_arr(arr, n);

        printf("\n\n");
    }
}

void quick_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = partition(arr, l, r);

        quick_sort(arr, l, mid - 1);
        quick_sort(arr, mid + 1, r);// mid + 1 because mid is now at its correct place
    }
}

void swap(int *num, int *num2)
{
    int temp = *num;
    *num = *num2;
    *num2 = temp;
}

int partition(int arr[], int l, int r )
{
    int pivot = arr[r];

    int change = l;// we will use this variable to use swap

    /*
        In this loop we will bring all numbers smaller than pivot before it
    */
   
    for (int i = l; i < r; ++i)// i < r because arr[r] is our pivot
    {
        if (arr[i] < pivot)
            swap(&arr[change++], &arr[i]);

    }
    swap(&arr[change], &arr[r]);

    return change;
}

void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}