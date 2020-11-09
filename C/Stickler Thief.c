#include <stdio.h>

int sum(int arr[], int n);

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
    	    
    	printf("%d\n", sum(arr, n));
	}
	return 0;
}

int sum(int arr[], int n)
{
    int sum_ = arr[0];
    int sum2 = 0;
    int new_sum;
    
    for (int i = 1; i < n; i++)
    {
        new_sum = (sum_ > sum2) ? sum_ : sum2;
        
        sum_ = sum2 + arr[i];
        sum2 = new_sum;
    }
    
    return (sum_ > sum2) ? sum_ : sum2;
}
