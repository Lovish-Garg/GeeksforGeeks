#include <stdio.h>
#include <stdbool.h>

#define R 6
#define C 5

int min(int a, int b, int c);
void printMaxSubSquare(bool M[R][C]);

int main(void)
{
     bool M[R][C] = {{0, 1, 1, 0, 1},  
                    {1, 1, 0, 1, 0},  
                    {0, 1, 1, 1, 0}, 
                    {1, 1, 1, 1, 0}, 
                    {1, 1, 1, 1, 1}, 
                    {0, 0, 0, 0, 0}}; 
                  
    printMaxSubSquare(M); 
    getchar();  
}

void printMaxSubSquare(bool M[R][C])
{
    int S[R][C];

    for (int i = 0; i < R; i++)
        S[i][0] = M[i][0];

    for (int i = 0; i < C; i++)
        S[0][i] = M[0][i];

    for (int i = 1; i < R; i++)
    {
        for (int j = 1; j < C; j++)
        {
            if (M[i][j] == 1)
                S[i][j] = min(S[i][j - 1], S[i - 1][j],
                S[i - 1][j - 1]) + 1; 

            else
                S[i][j] = 0;
        }
    }

    int max_s = S[0][0], max_i = 0, max_j = 0;
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (max_s < S[i][j])
            {
                max_s = S[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    printf("Maximum size Sub-Array->\n");
    for (int i = max_i; i > max_i - max_s; i--)
    {
        for (int j = max_j; j > max_j - max_s; j--)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int min(int a, int b, int c)
{
    int min = a;
    
    if (min > b)
        min = b;

    if (min > c)
        min = c;

    return min;
}
