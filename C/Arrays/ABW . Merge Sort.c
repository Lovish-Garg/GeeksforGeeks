/*
 This program of merge_Sort doesnot make use of two arrays
 just like L for left Sub-array and R for R right sub-array
 this just use a temp array of 'r' size and this program also 
 doesnot need to copy elements of left subarray and right sub-
 arrays then perform operation . This program directly use temp array
 to store sorted version of actual array then copy it to the 
 actual array named 'arr' in this case
*/
#include <stdio.h>

void print_arr(int [], int);
void merge(int [], int, int, int);
void merge_sort(int [], int, int);

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

        merge_sort(arr, 0, n - 1);
        
        printf("\n\nArray after sorting->\n");   
        print_arr(arr, n);

        printf("\n\n");
    }
}

void merge_sort(int arr[], int l, int r)
{
    
    if (l < r)
    {
        int mid = l + (r - l)/ 2;
        
        merge_sort(arr, l, mid);// divide array as left sub-arr
        merge_sort(arr, mid + 1, r);// divide array as right sub-arr

        merge(arr, l, mid, r);// merge left and right sub-arr
    }
}

void merge(int arr[], int l, int m, int r)
{
    int k = l;
    
    /*
        Well I tried with temp[r - l + 1] So that I would create only 
        required space for variables but then in some test-cases
        It showed me undefined behaviour because temp[r - l + 1] will create
        only space for number of elements but in some cases when temp has storage of 
        5 integers but k becomes greater than 5 , then it will act as bug
    */
    int temp[r];

    int first = l;// first for first sub-arr and to get the elements of first sub-arr
    int second = m + 1;// second for second sub-arr and to get the elements of second sub-arr 

    while (first <= m && second <= r)// while (first is in limits of first sub-arr && second in limit of size of whole array)
    {

        if (arr[first] <= arr[second])
            temp[k++] = arr[first++];
        
        else
            temp[k++] = arr[second++];
            
    }

    // to copy the remained elements if remained any
    while (first <= m)
        temp[k++] = arr[first++];

    while (second <= r)
        temp[k++] = arr[second++];

    for (int i = l; i <= r; ++i)
        arr[i] = temp[i];

}

void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}