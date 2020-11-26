// This is C version of GFG problem Majority Element
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node 
{
    int count;
    int data;
    struct node *left, *right;
}node;

int major_elem = INT_MIN;

node *create_node(int num)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->count = 1;
    temp->data = num;
    temp->left = temp->right = NULL;

    return temp;
}

node *insert(node *root, int num, int count)
{
    if (root == NULL)
        return create_node(num);

    if (num == root->data)
    {
        root->count++;

        if (root->count > (count / 2))
        {
            major_elem = num;
        }
    }
    else if (num < root->data)
        root->left = insert(root->left, num, count);

    else 
        root->right = insert(root->right, num, count);

    return root;
}

void free_(node *root)
{
    if (root == NULL)
        return;

    free_(root->left);
    free_(root->right);

    free(root);
}

int main(void)
{
    int t;

    printf("Testcases: ");
    scanf("%d", &t);

    while (t--)
    {
        int n;
        
        node *root = NULL;

        printf("Elements: ");
        scanf("%d", &n);

        int num;

        printf("\nInput data in array->\n");

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num);
            root = insert(root, num, n);
        }
        
        if (n == 1)
            printf("\n%d is major element\n\n", root->data);    
        else 
            printf("\nMajor element is %d\n\n", major_elem = (major_elem == INT_MIN) ? INT_MIN : major_elem);

        free_(root);
    }
    return 0;
}
