// This program complete gfg Submition in 0.1 Execution time
#include <stdio.h>

int min(int a, int b, int c);
int printMaxSubSquare(int R, int C, int M[R][C]);

int main() {
	//code
	int t;
    scanf("%d", &t);
    
    while (t--)
    {
        int R, C;
        scanf("%d%d", &R, &C);
        
        int M[R][C];
        
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                scanf("%d", &M[i][j]);
                
        
        printf("%d\n", printMaxSubSquare(R, C, M));
    }
	return 0;
}

int printMaxSubSquare(int R, int C, int M[R][C])
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

    int max_s = S[0][0];
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (max_s < S[i][j])
            {
                max_s = S[i][j];
            }
        }
    }
    return max_s;
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
