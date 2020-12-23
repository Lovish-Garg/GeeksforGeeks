#include <stdio.h>

void sort(int [], int, int);
void merge(int [], int, int, int);
int get_subset(int [], int, int[], int);

int main(void)
{
    int t;

    printf("Testcases: ");
    scanf("%d", &t);

    while (t--)
    {
        int n;

        printf("Elements (1st Array): ");
        scanf("%d", &n);

        int arr[n];

        printf("\nInput data in array->\n");
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);

        int m;

        printf("\nElements (2nd Array): ");
        scanf("%d", &m);

        int arr2[m];

        printf("\nInput data in array->\n");
        for (int i = 0; i < m; ++i)
            scanf("%d", &arr2[i]);

        int check = get_subset(arr, n, arr2, m);

        (check == 1) ? printf("\n2nd Array is subset of 1st Array\n\n") : printf("\n2nd Array is not a subset of 1st Array\n\n");
    }

    return 0;   
}

int get_subset(int arr[], int n, int arr2[], int m)// just merging in this function and incrementing and check in final that j == elements of arr2
{   
    if (n < m)// first array should be bigger or equal to of second array
        return 0;
    
    if (m == 0 || n == 0)
        return 0;
    
    int i = 0;// for first array 
    int j = 0;// for second array

    // first we need sorting
    sort(arr, 0, n);
    sort(arr2, 0, m);

    while (i < n && j < m)
    {
        if (arr[i] < arr2[j])
            i++;
        
        else if (arr[i] == arr2[j])
        {
            i++;
            j++;
        }

        else// means arr[i] > arr2[j] which means that arr2[j] doesnot exist in 'arr' array then return 
            return 0;
    }

    return (j < m) ? 0 : 1;// j == m as all elements of arr2 are present in arr
}

void sort(int arr[], int l, int r)
{
    
    if (l < r)
    {
        int mid = l + (r - l)/ 2;
        
        sort(arr, l, mid);// divide array as left sub-arr
        sort(arr, mid + 1, r);// divide array as right sub-arr

        merge(arr, l, mid, r);// merge left and right sub-arr
    }
}

void merge(int arr[], int l, int m, int r)
{
    int k = l;

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
