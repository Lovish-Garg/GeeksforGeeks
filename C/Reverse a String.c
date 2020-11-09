#include <stdio.h>
#include<string.h> 
#define MAX 1000

void strrev(char string[], int, int);

int main() 
{
	//code
	int t;
	scanf("%d\n", &t);
    
	while (t--)
	{
	    char string[MAX];
	    scanf("%s", string);
	    
	    strrev(string, 0,  strlen(string) - 1);
	    
	    printf("%s\n", string);
	}
	return 0;
}
// here i'm swapping between start and end and recursively calling strrev with start++ and end-- 
void strrev(char string[], int start, int end)
{
    if (start >= end)
        return;
        
   char temp = string[start];
   string[start] = string[end];
   string[end] = temp;
   
   return strrev(string, start + 1, end - 1);
}
