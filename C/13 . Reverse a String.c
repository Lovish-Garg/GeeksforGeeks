#include <stdio.h>
#include<string.h> 
#define MAX 1000

void strev(char string[], int, int);

int main() 
{
    //code
    int t;

    printf("Testcases: ");
    scanf("%d", &t);
    
    fflush(stdin);
    while (t--)
    {
        char string[MAX];

        printf("String: ");
        fgets(string, sizeof(string), stdin);
        
        strev(string, 0,  strlen(string) - 1);
        
        puts(string);
        printf("\n");
    }
    return 0;
}
// here i'm swapping between start and end and recursively calling strrev with start++ and end-- 
void strev(char string[], int start, int end)
{
    if (start >= end)
        return;
        
   char temp = string[start];
   string[start] = string[end];
   string[end] = temp;
   
   return strev(string, start + 1, end - 1);
}
