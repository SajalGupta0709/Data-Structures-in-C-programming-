#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

void insert(struct node **root,int data)
{
    struct node *newnode =  (struct node *)malloc(sizeof(struct node));
    newnode->key = data;
    newnode->left = newnode->right = NULL;
 if (*root == NULL) {
         *root=newnode;
         return;}
 struct node* temp=*root;
 struct node* parent =*root;
while(temp!=NULL){
  if(temp->key>data)
  {
     parent=temp;
     temp=temp->left;}
  else if (temp->key<data)
  {
    parent=temp;
    temp=temp->right;}}
(parent->key>data)?(parent->left=newnode):(parent->right=newnode);
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
struct node*  minValueNode(struct node* node)
{
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}
struct node*  delete(struct node *root, int key)
{
    if (root == NULL) return root;
    if (key < root->key)
            root->left = delete(root->left, key);
    else if (key >root->key)
        root->right= delete(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

     struct node* temp =minValueNode(root->right);
     root->key = temp->key;
     root->right = delete(root->right, temp->key);
    }return root;
}
void search(struct node *root,int key)
{
         while (root != NULL)
         {
          if (root->key == key)
          {   printf("Key Found\n");
          return;
          }
          else if (key > root->key)
            root = root->right;
      else if (key < root->key)
            root = root->left;
         }
     printf("Key is not found\n");
}
void preorder(struct node *root)
{
    if (root != NULL)
    {   printf("%d \n", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \n", root->key);
        }
}
int height(struct node* root)
{
    if (root==NULL)
        return 0;
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
void printGivenLevel(struct node* root, int level)
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
void levelorder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
int getLevel(struct node *root, int data, int level)
{
    if (root == NULL)
        return 0;

    if (root->key == data)
        return level;
  int downlevel = getLevel(root->left, data, level+1);
    if (downlevel != 0)
        return downlevel;

    downlevel = getLevel(root->right, data, level+1);
    return downlevel;
}
void heinode(struct node *root, int data)
{
     int h=getLevel(root,data,1);
         h--;
    printf("The height of %d is :%d\n",data,h);
}
void depnode(struct node *root, int data)
{    int hei=height(root);
     int h=getLevel(root,data,1);
         h--;
         h=hei-h;
    printf("The depth of %d is :%d\n",data,h);}
void lca(struct node *root,int n1,int n2)
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
}
int main() {
    struct node *root=NULL;
    int op,key,key1;
    do
    {
     printf("1:Insert\n");
     printf("2:Delete\n");
     printf("3:Search\n");
     printf("4:Inorder\n");
     printf("5:Preorder\n");
     printf("6:Postorder\n");
     printf("7:Levelorder\n");
     printf("8:Height\n");
     printf("9:Height of Node\n");
     printf("10:Depth of Node\n");
     printf("11:Least Common Ancestor\n");
     printf("0:EXIT\n");
     scanf("%d",&op);
     switch(op){
     case 1:printf("Enter Key.\n");
            scanf("%d",&key);
            insert(&root,key);
            break;
     case 2:printf("Enter key\n");
            scanf("%d",&key);
           root= delete(root,key);
            break;
     case 3:printf("Enter Search Key.\n");
            scanf("%d",&key);
            search(root,key);
            break;
     case 4:inorder(root);
            break;
     case 5:preorder(root);
            break;
     case 6:postorder(root);
            break;
     case 7:levelorder(root);
            break;
     case 8:printf(" The height of tree is %d\n",height(root));
             break;
     case 9:printf("Enter node \n");
            scanf("%d",&key);
            heinode(root,key);
            break;
     case 10:printf("Enter Node\n");
             scanf("%d",&key);
             depnode(root,key);
             break;
     case 11:printf("Enter Node1 and node2\n");
             scanf("%d%d",&key,&key1);
             lca(root,key,key1);
             break;
    }
    }while(op!=0);
   return 0;
}
