#include<stdio.h>
#include<stdlib.h>
 struct Node
 {
	int data;
	struct Node *next;
 }
 void insert_beg(struct Node **start,int data)
 {
    struct Node *new_Node,*ptr;
    new_Node=(struct Node *)malloc(sizeof(*struct Node));
	new_Node->data=data;
	ptr=*start;
	while(ptr->next!=*start)
		ptr=ptr->next;
	ptr->next=new_Node;
	new_Node->next=*start;
	*start=new_Node;
 }
 void insert_end(struct **start,int data)
 {
	 struct *ptr=*start;
	 struct Node *new_Node =  (struct Node *)malloc(sizeof(struct Node)); 
     new_Node -> data = data;
     while(ptr->next!=*start)
          ptr=ptr->next;	  
     ptr->next=new_Node; 
     *new_Node-> next = *start; 
 }	 
 void insert_index(struct **start,int index, int data)
 {
	 struct Node *newNode, *curNode;
     int i;
	 newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        curNode = *start;
		if(index==1)
			insert_beg(*start,data);
		else 
        {
           for(i=2; i<=index-1; i++)
               curNode = curNode->next;
            newNode->next = curNode->next;
            curNode->next = newNode;
		}
 }
 void delete_key(struct **start, int data)
 {  
       if (*start == NULL) 
        return;  
    struct Node *curr = *start, *prev; 
    while (curr->data != key) 
    { 
        if (curr->next == *start) 
        { 
            printf("\nGiven Node is not found"
                   " in the list!!!"); 
            break; 
        } 
  
        prev = curr; 
        curr = curr -> next; 
    }  
    if (curr->next == *start) 
    { 
        *start = NULL; 
        free(curr); 
        return; 
    }  
    if (curr == *start) 
    { 
        prev = *start; 
        while (prev -> next != *start) 
            prev = prev -> next; 
        *start = curr->next; 
        prev->next = *start; 
        free(curr); 
    } 
    else if (curr -> next == *start) 
    { 
        prev->next = *start; 
        free(curr); 
    } 
    else
    { 
        prev->next = curr->next; 
        free(curr); 
    } 
 } 
 void delete_index(struct **start,int index)
 {
	 struct Node *previous = **start, *next = **start; 
	 int len=0,count=1;
	 if(*start==NULL)
		 len=0;
	 else{
		 do{
			 previous=previous->next;
			 len++;
		 }while(previous!=*start;
	 }
	 previous=*start;
	 if (**start == NULL) 
        printf("\nDelete Last List is empty\n"); 
    if (index >= len || index < 0) 
        printf("\nIndex is not Found\n");     
    while (len > 0) { 
        if (index == count) { 
            previous->next = next->next; 
            free(next); 
        } 
        previous = previous->next; 
        next = previous->next; 
        len--; 
        count++; 
    } 	
 }
 void search_key(struct Node **start, int data)
 {
	int index = 0;
    struct Node *current = *start;
    do{
		if (current->data == data)
			printf("Key found at index %d \n", index);
        current = current->next;
		index++;
    } while (current != *start);
 }
 void search_index(struct **start, int index)
 {
	 int c=0;
	 struct Node *temp=*start;
	 if(*start!=NULL)
	 {
		 do {
			 c++;
			 if(c==index)
			 {	 printf("Key at givem index is %d\n",temp->data);
			  break; }
		} while(temp!=*start);
	 }
    if(c!=index)
		printf("Given index is out of list count.\n");
 } 
 void delete_List(struct Node** start) 
 { 
   struct Node* current = *start; 
   struct Node* next;   
   while (current != *start)  
   { 
       next = current->next; 
       free(current); 
       current = next; 
   } 
   *start=NULL;
 }
 void node_end( struct **start, int index)
 {
	int len = 0, i; 
    struct Node *temp =*start; 
	do
    { 
        temp = temp->next; 
        len++; 
    } while(temp!=*start);
	temp=*start;
	for (i = 1; i < len-n+1; i++) 
    temp = temp->next;   
    printf ("Nth node from the end is %d", temp->data); 
 }
 void count(struct **start)
 {
	 struct Node* current = *start; 
    int count = 0; 
    if (*start == NULL) 
        printf("Number of Nodes are 0.\n");
    else { 
        do { 
            current = current->next; 
            count++; 
        } while (current != *start); 
    } 
	printf("Number of Nodes are %d\n"),count);
 }
 void middle(struct **start)
 {
	 
	 
 }
  void print(struct Node **start) 
 { 
    struct Node *temp = *start; 
    if (*start != NULL) 
    { 
        do
        { 
            printf("%d ", temp->data); 
            temp = temp->next; 
        } 
        while (temp != *start); 
    } 
    printf("\n"); 
 }  
  void reverse(Node** start) 
{ 
    struct Node* prev = NULL; 
    struct Node* current = *start; 
    struct Node *next;
    do { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } while (current != (*start)); 
    (*start)->next = prev; 
    *start = prev; 
 } 
  
	