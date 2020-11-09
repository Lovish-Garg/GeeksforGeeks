#include <stdio.h>
#include <stdlib.h>

int major_elem(int arr[], int n);
int cmpfunc(const void * a, const void * b);

int main() {
	//code
	int t;
	
	scanf("%d", &t);
	
	while (t--)
	{
	    int n;
	    scanf("%d", &n);
	    
	    int arr[n];
	    
	    for (int i = 0; i < n; i++)
	    {
	        scanf("%d", &arr[i]);
	    }
	    
	    printf("%d\n", major_elem(arr, n));
	}
	return 0;
}

/*
  Here the logic is that after sorting array the elements which are same should belong in a straight line 
*/
int major_elem(int arr[], int n)
{
    qsort(arr, n, sizeof(int), cmpfunc);
    
    int temp = arr[0], count = 1, max_elemen = -1, ele = 0, f1 = 0;
    
    for (int i = 1; i < n; i++)
    {
        if (temp == arr[i])
        {
            count ++;
        }
        else
        {
            count = 1;
            temp = arr[i];
        }
        
        if (max_elemen < count)
        {
            max_elemen = count;
            ele = arr[i];
            
            if (max_elemen > (n / 2))
            {
                f1 = 1;
                goto l1;
            }
        }
    }
    l1:
    
    return (f1 == 1) ? ele : -1;
    
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

