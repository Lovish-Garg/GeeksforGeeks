// This program is the C version of gfg problem Middle of Three
#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int get_max(int A, int B, int C)
{
    if (A > B) swap(&A, &B);

    if (B > C) swap(&B, &C);

    if (A > B) swap(&A, &B);

    return B;
}

int main(void)
{
    int t;

    printf("Testcases: ");
    scanf("%d", &t);

    while (t--)
    {
        int A, B, C;

        printf("Input 3 values->\n");
        scanf("%d%d%d", &A, &B, &C);

        printf("\nMiddle : %d\n\n", get_max(A, B, C));
    }

    return 0;
}

