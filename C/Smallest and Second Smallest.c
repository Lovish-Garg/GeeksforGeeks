#include <stdio.h>
#include <limits.h>

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

		int first = INT_MAX;
		int second = INT_MAX;

		for (int i = 0; i < n ;i++)
		{
			if (arr[i] < first)
			{
				second = first;
				first = arr[i];
			}

			else if (arr[i] < second && arr[i] != first)
			{
				second = arr[i];
			}
		}
        
        if ((first != INT_MAX && second != INT_MAX))
	    	printf("%d %d\n", first, second);
		else
	        printf("-1\n");
	}
	return 0;
}
