#include <stdio.h>

int maxPosition(int n,int *a);

int main() {
    //code
    int t;
    
    scanf("%d", &t);
    
    while (t--)
    {
        int nT; // number of plates thief can steal
        scanf("%d", &nT);
        
        int boxes;// number of boxes in mine
        scanf("%d", &boxes);
        
        int arr[boxes * 2]; // array for denoting number of plates and number of gold coins in each box
        
        for (int i = 0, range = boxes  * 2; i < range; i++)
        {
            scanf("%d", &arr[i]);
        }
        
        int p, gc = 0;
        
        while (nT != 0)// mean while number of plates thief can steal != 0
        {
            p = maxPosition(2 * boxes, arr);
            
            if (nT - arr[p - 1] >= 0)// means thief can steal more plates
            {
                gc += arr[p-1]*arr[p];// gc = no. of plates * no. of coins of that plate
	            arr[p] = 0;// so that no. wouldnot come again as max num
	            nT-=arr[p-1];// assigning no. of plates thief can steal more
            }
            else// means thief cannot steal more plates after this plate
            {
                gc += nT * arr[p];
	            nT = 0;
            }
        }
        printf("%d\n",gc);
    }
	return 0;
}

int maxPosition(int n,int *a)
{
    int p, max = 0;
    for(int i = 1; i < n; i = i + 2)// to get max number of coins in plate
    {
        if (max < a[i])
        {
            max = a[i];
            p = i;
        }
    }
    return p;
}
