#include<stdio.h>
#include<stdlib.h
#include"singylink.h"
 void insert_beg(struct Node **start, int data) 
 { 
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
   new_node->data = data; 
   new_node->next = (*start); 
   new_node->prev = NULL;
   if ((*start) != NULL) 
        (*start)->prev = new_node; 
    (*start) = new_node; 
 }
 void insert_end(struct Node** start, int data) 
 {
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
   struct Node* last = *start; 
   new_node->data = data;
   new_node->next = NULL; 
   if (*start == NULL) { 
        new_node->prev = NULL; 
        *start = new_node; 
        return; 
   }  
   while (last->next != NULL) 
        last = last->next; 
   last->next = new_node; 
   new_node->prev = last;
   return;
 }
 void insert_index(struct Node **start,int index,int data)
 {
    struct Node* newNode=(struct Node*) malloc(sizeof(struct Node));
    struct node *ptr;
    int i; 
    ptr=*start;
    newNode->data=data;
    while(ptr->data!=index)
    {
       ptr=ptr->next;
       newNode
       (ptr->next)->prev = newNode;    
       ptr->next = newNode; 
       newNode->prev = ptr; 
    } 
 }
 void deleteNode(struct Node** start, struct Node* del) 
 {
   if (*start == NULL || del == NULL) 
         return;
   if (*start == del) 
        *start = del->next;      
   if (del->next != NULL) 
        del->next->prev = del->prev;  
   if (del->prev != NULL) 
        del->prev->next = del->next; 
   freee(del);
 } 
 
  
 void delete_key(struct Node** start, int data) 
 { 
   if ((*start) == NULL) 
        return; 
    struct Node* current = *start; 
    struct Node* next; 
    while (current != NULL) { 
      if (current->data == data) { 
         next = current->next; 
          deleteNode(*start, current); 
            current = next; 
        } 
    else
            current = current->next; 
    }  
 }
 void delete_index(struct Node** start, int n) 
{ 
    if (*start == NULL || n <= 0) 
        return; 
    struct Node* current = *start; 
    int i;
    for (int i = 1; current != NULL && i < n; i++) 
        current = current->next;
    if (current == NULL) 
        return; 
    deleteNode(*start, current); 
 } 
  void search_key(struct Node** start, int data)
 {
   int c=0;
   if ((*start) == NULL)
        return;
    struct Node* current = *start;
    struct Node* next;
    while (current != NULL) {
         c++;
      if (current->data == data)
         printf("Key is at node %d\n",c); }
    if(c==0)
      printf("Key is not present\n");
 }
 void delete_list(struct node **start)
 {
    while(start !=NULL)
        start=delete_beg(*start);
 }
 void middle(struct node **start)
 {
  struct Node *slow_ptr = *start;
  struct Node *fast_ptr = *start;
    if (*start!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is %d:\n", slow_ptr->data);
    }
 }
 void node_end(struct node **start)
 {
   int len = 0, i;
   struct Node *temp = *start;
   while (temp != NULL)
    {
        temp = temp->next;
        len++; }
   temp=*start;
   if(len<n)
     return;
   for (i = 1; i < len-n+1; i++)
    temp = temp->next;

    printf ("Middle Element:%d\n", temp->data);
  }

  
void reverse(struct Node **start) 
 { 
     struct Node *temp = NULL;   
     struct Node *current = *start;
     while (current !=  NULL) 
     { 
       temp = current->prev; 
       current->prev = current->next; 
       current->next = temp;               
       current = current->prev; 
     }       
      if(temp != NULL ) 
        *start = temp->prev;  
 }      
 void print()  
 {  
    struct node* temp=head;  
    while(temp!=NULL)  
    {  
        printf("%d",temp->data);  
        temp=temp->next;  
    }  
 }  
