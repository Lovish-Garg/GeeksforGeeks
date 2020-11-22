// In this program I have remade a program of gfg in C but in gfg it was in C++.
#include <stdio.h>
#define NA -1

void merge(int arr[], int arr2[], int n, int m);
void moveToEnd(int *ptr, int size);

void print_arr(int [], int);

int main(void)
{
    int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20}; 
    int N[] = {5, 7, 9, 25}; 
    int n = sizeof(N)/sizeof(N[0]); 
    int m = sizeof(mPlusN)/sizeof(mPlusN[0]) - n;
    
    moveToEnd(mPlusN, m + n);
    
    printf("\nAfter moving to end->\n");
    print_arr(mPlusN,m + n);

    merge(mPlusN, N, n, m);

    printf("\n\nAfter merging the arrays->\n ");
    print_arr(mPlusN, m + n);

    printf("\n");
    return 0;
}

void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\t", arr[i]);
}

// function to move the array data of nPlusM to right side
void moveToEnd(int mPlusN[], int size) 
{ 
  int i = 0, j = size - 1; 

  for (i = size-1; i >= 0; i--) 
  {
        if (mPlusN[i] != NA) 
        { 
        mPlusN[j] = mPlusN[i]; 

        j--; 
    }
  }
} 

void merge(int mPlusN[], int N[], int n, int m)
{
    int i = n;// index where our first element exists in this case it is 2 and its index is 4 in mplusN array
    int j = 0;// index for N[] array 
    int k = 0; // index for the current index where the number needs to store and we are incrementing it in each case 

    while (k < (m + n))
    {
        if ((i < (m + n) && mPlusN[i] <= N[j]) || (j == n))
        {
            mPlusN[k] = mPlusN[i];
            i++; 
        }
        else
        {
            mPlusN[k] = N[j];
            j++;
        }
            k++;
    }
}
