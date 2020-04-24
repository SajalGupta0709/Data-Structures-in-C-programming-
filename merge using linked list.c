#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* SortedMerge(struct Node* a, struct Node* b);
void split(struct Node* source, struct Node** front, struct Node** back);
void MergeSort(struct Node** head_Ref)
{
struct Node* head = *head_Ref;
struct Node* a;
struct Node* b;

if ((head == NULL) || (head->next == NULL))
    return;

split(head, &a, &b);
MergeSort(&a);
MergeSort(&b);

*head_Ref = SortedMerge(a, b);
}

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
struct Node* result = NULL;

if (a == NULL)
    return(b);
else if (b==NULL)
    return(a);

if (a->data <= b->data)
{
    result = a;
    result->next = SortedMerge(a->next, b);
}
else
{
    result = b;
result->next = SortedMerge(a, b->next); }
return result;
}
void push(struct Node** head_ref,int z)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data =z;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;}
void split(struct Node* source,struct Node** front, struct Node** back)
{
    struct Node* fast;
    struct Node* slow;
    slow = source;
    fast = source->next;
   while (fast != NULL)
    {
    fast = fast->next;
    if (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    }
  *front = source;
  *back = slow->next;
  slow->next = NULL;
}
void print(struct Node* node){
   while(node!=NULL)
   {
   printf("%d ", node->data);
   node = node->next;
    }
}

int main()
{ int n,z,i;
 struct Node* res = NULL;
 struct Node* a = NULL;

 printf("Enter number of element u want to enter.\n");
 scanf("%d\n",&n);
 printf("Enter elements:");
  for(i=0;i<n;i++)
  {  scanf("%d  ",&z);
    push(&a,z); }
  MergeSort(&a);
  printf("Printed List after Sorting:\n");
  print(a);
  return 0;
}
