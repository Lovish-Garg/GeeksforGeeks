// This program is C version of Gfg problem Number Of Occurence
/*
	This program works by getting the index of first 
	occurence of number x in array then getting last index
	of occrence in array then print 
	last - first + 1
*/
#include <stdio.h>

int first_occur(int [], int, int);
int last_occur(int [], int, int, int);
void Printcount_occur(int [], int, int);

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
		for(int i = 0; i < n; ++i)
			scanf("%d", &arr[i]);

		int num;

		printf("\nNumber: ");
		scanf("%d", &num);

		Printcount_occur(arr, n, num);

		printf("\n");
	}
}	

void Printcount_occur(int arr[], int n, int x)
{
	int first = first_occur(arr, n, x);

	if (first == -1)// if first contains -1 means x not found
	{
		printf("\n%d not found\n", x);
		return;
	}

	int last = last_occur(arr, first, n, x);

	printf("\nFirst Occurence: %d\nLast Occurence: %d\nTotal Occurence: %d\n", first, last, last - first + 1);		
}

int first_occur(int arr[], int n, int x)
{
	int l = 0, r = n - 1;

	while (l <= r)
	{
		int mid = l + (r - l) / 2;

		if (arr[mid] == x && (mid == 0 || arr[mid - 1] < x))
			return mid;

		// this else if and else part is important because
		/*
			if arrr[mid] == x but it isnot the first occurence then the else part
			will get evaluated and we will search for first occurence in first part
		*/
		else if (x < arr[mid])
			l = mid + 1;

		else
			r = mid - 1; 
	}

	return -1;
}


int last_occur(int arr[], int l, int n, int x)
{
	int r = n -1;

	while (l <= r)
	{
		int mid = l + (r - l) / 2;

		if (arr[mid] == x && (mid == n - 1 || arr[mid + 1] > x))
			return mid;

		// this else if and else part is also important in similar way because
		/*
			if arrr[mid] == x but it isnot the last occurence then the else part
			will get evaluated and we will search for first occurence in second part
			of array
		*/
		else if (x < arr[mid])
			r = mid - 1;

		else
			l = mid + 1;
	}

	return -1;
}