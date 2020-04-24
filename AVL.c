#include<stdio.h>
#include<stdlib.h>
 struct Node
 { int key;
    struct Node *left;
    struct Node *right;
    int height;
};
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    return(node);
}
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
     y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
      return x;
}
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
struct Node* insert(struct Node* node, int key)
{
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);
if (balance > 1 && key < node->left->key)
        return rightRotate(node);
if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 if (balance > 1 && key > node->left->key)
   {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
   }
if (balance < -1 && key < node->right->key)
   {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
return node;
}
struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;

    return current;
}
struct Node* delete(struct Node* root, int key)
{
      if (root == NULL)
        return root;

     if ( key < root->key )
        root->left = delete(root->left, key);
    else if( key > root->key )
        root->right = delete(root->right, key);
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left :  root->right;


            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
             *root = *temp;
             free(temp);
        }
        else
        {
               struct Node* temp = minValueNode(root->right);
             root->key = temp->key;

            root->right = delete(root->right, temp->key);
        }
    }
    if (root == NULL)
      return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

      if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

      if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
      if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
void preorder(struct Node *root)
{
    if (root != NULL)
    {   printf("%d \n", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \n", root->key);
        }
}
void printGivenLevel(struct Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->key);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }

}
void levelorder(struct Node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
/*void lca(struct Node *root,int n1,int n2)
{
     struct node *temp=root;
     while(1){
     if(temp->key>n1 && temp->key>n2)
             temp=temp->left;
     else if(temp->key<n1&& temp->key<n2)
             temp=temp->right;
     else     break;
     }
     printf("least commmon ancestor is:%d\n",temp->key);
}*/
int main() {
    struct Node *root=NULL;
    int op,key,key1;
    do
    {
     printf("1:Insert\n");
     printf("2:Delete\n");
   //  printf("3:Search\n");
     printf("4:Inorder\n");
     printf("5:Preorder\n");
     printf("6:Postorder\n");
     printf("7:Levelorder\n");
     printf("8:Height\n");
 //    printf("9:Height of Node\n");
    // printf("10:Depth of Node\n");
   //  printf("11:Least Common Ancestor\n");
     printf("0:EXIT\n");
     scanf("%d",&op);
     switch(op){
     case 1:printf("Enter Key.\n");
            scanf("%d",&key);
           root= insert(root,key);
            break;
     case 2:printf("Enter key\n");
           scanf("%d",&key);
           root= delete(root,key);
            break;
    // case 3:printf("Enter Search Key.\n");
      //      scanf("%d",&key);
       //     search(root,key);
         //  break;
     case 4:inorder(root);
            break;
     case 5:preorder(root);
            break;
     case 6:postorder(root);
            break;
     case 7:levelorder(root);
            break;
     case 8:printf(" The height of tree is %d\n",height(root)+1);
             break;
 /*    case 9:printf("Enter node \n");
            scanf("%d",&key);
            height(root,key);
            break;*/
 //    case 10:printf("Enter Node\n");
   //          scanf("%d",&key);
     //        depnode(root,key);
       //      break;
    /* case 11:printf("Enter Node1 and node2\n");
              scanf("%d%d",&key,&key1);
             lca(root,key,key1);
             break;*/
    }
    }while(op!=0);
   return 0;
}
