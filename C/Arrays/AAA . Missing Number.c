// This program is the C version of GFG problem Find Missing Number
#include <stdio.h>

int main() {
    
    int t;
    printf("Testcases: ");
	scanf("%d",&t);
	
	while(t--)
	{
	    int n;
	    
	    printf("Elements: ");
        scanf("%d",&n);
	    
	    int x1 = 0 ,x2 = 0,elem, i;

	    printf("\nInput data in array->\n");

        for(i=0;i<n-1;++i)
	    {
	        scanf("%d",&elem);
	     
            x1 = x1^(i+1);
	     
            x2 = x2^elem;
	    }
        
        x1 = x1 ^ (i + 1);
        
	    printf("%d\n\n",x1^x2);
	}
	return 0;
}
