#include<stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
} node;
node* insert_end(node* head, int data) {
    if(head == NULL) {
        node* new_node;
        new_node = (node*)malloc(sizeof(node));
        new_node->data = data;
        new_node->next = NULL;
        head = new_node;
        return head;
    }
    node* new_node;
    new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;

    return head;
}

void traverse(node* head) {
    node* temp = head;
    int c=0;
    while(temp != NULL) { c++;
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf(" SIZE=%d",c);
}
int main()
{
   int k,ind,n,i,m,c=0;
   printf("Enter Number of Elements and size of hash table.\n");
   scanf("%d",&n);
   scanf("%d",&m);
   struct node *chain[m];
   for(i = 0; i < m; i++)
      chain[i] = NULL;

   for(i=0;i<n;i++)
   {  k = rand()%100 + 1;
      ind=k%m;
      if(chain[ind]== NULL)
        chain[ind]=insert_end(chain[ind],k);
      else{  c++;
       chain[ind]=insert_end(chain[ind],k);}
   }
   printf("The Hash Table:\n");
   for(i=0;i<m;i++)
   {
      printf("Chain[%d]= ",i);
      traverse(chain[i]);
      printf("\n");
   }
   printf("Number of Collisions=%d\n",c);
   return;
}
