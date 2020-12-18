#include <stdio.h>
#include <stdlib.h>

void user_code(void);
void static_code(void);
void print_arr(int r, int c, int *arr);
void rotate_arr(int r, int c,int arr[r][c], int *Pd);

int main(void)
{
	char choice;

	do
	{
		printf("\nInput y for static-code \nInput t for run-time code\n\nInput your choice: ");
		scanf("%c", &choice);
	} 
	while (choice != 'y' && choice != 't');
	
	if (choice == 'y')
		static_code();
	else
		user_code();

	return 0;
}

void static_code()
{
	int arr[][4] = 
	{
		{1,2,3,4},  
        {5,6,7,8}, 
        {9,10,11,12}
	};
	int *p = (int *)arr;
	int *Pdest = (int *)malloc(sizeof(arr));

	printf("\nArray before rotating->\n");
	// In print_arr function *arr means I'm sending address of first element of first row
	print_arr(3, 4, p);// print_arr(r, c, arr)

	rotate_arr(3, 4, arr, Pdest);
	/*
	Here because Pdest arr contain rotated version of user input arr
	so I need to print that Pdest in print_arr function
	*/
	printf("\nArray after rotating->\n");
	print_arr(4, 3, Pdest);
	
	printf("\n");

	free(Pdest);
}

void user_code()
{
	int t;

	printf("Testcases: ");
	scanf("%d", &t);

	while (t--)
	{
		int c, r;

		printf("Rows: ");
		scanf("%d", &r);

		printf("Coloumns: ");
		scanf("%d", &c);

		int arr[r][c];

		printf("\nInput data in array->\n");
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				printf("Number [%d][%d]: ", i, j);
				scanf("%d", &arr[i][j]);
			}
		}

		int *p = (int *)arr;
		int *pd = (int *)malloc(sizeof(arr));

		printf("\nArray before rotating->\n");
		print_arr(r, c, p);

		rotate_arr(r, c, arr, pd);

		printf("\nArray after rotating->\n");
		print_arr(r, c, pd);

		printf("\n");

		free(pd);
	}
}
// this function will take data from arr and store the rotated version of arr in Pd array
void rotate_arr(int r, int c, int arr[r][c], int *Pd)
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			*(Pd + j * r + (r - i - 1)) = arr[i][j];
		}
	}
}

// Here I am copying the address of arr which Pdest contain to arr
void print_arr(int r, int c, int *arr)
{
	for (int  i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			printf("%d ", *(arr + i * c + j));

		printf("\n");
	}
	
}