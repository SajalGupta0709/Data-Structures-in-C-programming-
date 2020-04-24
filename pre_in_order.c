#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
int search(int arr[], int strt, int end, int value);
struct node* newNode(int data);
struct node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;

    if (inStrt > inEnd)
        return NULL;
    struct node* tNode = newNode(pre[preIndex++]);
    if (inStrt == inEnd)
        return tNode;
    int inIndex = search(in, inStrt, inEnd, tNode->data);
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
    return tNode;
}
int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
}
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
int main()
{   int n,i;
    printf("Enter no of elements\n");
    scanf("%d",&n);
    printf("Enter inorder\n");
    int in[n];
    int pre[n];
    for(i=0;i<n;i++)
        scanf("%d",&in[i]);
    printf("Enter preorder\n");
    for(i=0;i<n;i++)
       scanf("%d",&pre[i]);
    int len = sizeof(in) / sizeof(in[0]);
    struct node* root = buildTree(in, pre, 0, len - 1);
    printf("Inorder traversal of the constructed tree is \n");
    printInorder(root);
    getchar();
}
