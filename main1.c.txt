#include<stdio.h>
#include<stdlib.h>
#include "singlylink.h"
int main(){
struct Node *start=NULL;

int data,index,op;
  do {
      printf("\n1. Insert an element in the beginning");
      printf("\n2. Insert an element in the end");
      printf("\n3. Insert an element at a particular index position of the list.");
      printf("\n4. Delete an element from the list given the key.");
      printf("\n5. Delete an element from the list given the index of the n  intode.");
      printf("\n6. Search an elememt from the list given the key");
      printf("\n7. Delete the list");
      printf("\n8. Search an element from the list given the index of the node.");
      printf("\n9. Get the nth node from the list.");
      printf("\n10. Get the nth node from the end of the list.");
      printf("\n11. Count the number of nodes of the list.");
      printf("\n12. Get the middle element of the list.");
      printf("\n13. Print the list.");
      printf("\n14. Reverse the list.");
      printf("\n15. check if list contain loop  and print the number of loops.");
      printf("\n0.exit.");
      printf("\n\n Enter your option :");
      scanf("%d",&op);
      switch(op)
      {
         case 1:printf("\n Enter data");
                scanf("%d",&data);
                insert_beg(&start, data);
                break;
         case 2:printf("\n Enter data");
                scanf("%d",&data);
                insert_end(&start,data);
                break;
         case 3:printf("\n Enter index and data");
                scanf("%d %d",&index,&data);
                insert_index(&start,index,  data);
                break;
         case 4:printf("\n Enter key");
                scanf("%d",&data);
                delete_key(&start,data);
                break;
         case 5:printf("\n Enter index");
                scanf("%d",&index);
                delete_index(&start,index);
                break;
         case 6:printf("\n Enter key");
                scanf("%d",&data);
                search_key(&start,data);
                break;
         case 7:delete_list(&start);
                break;
         case 8:printf("\n Enter index");
                scanf("%d",&index);
                search_index( &start,index);
                break;
         case 9:printf("\n Enter nth node");
                scanf("%d",&index);
                search_index( &start,index);
                break;
        case 10:printf("\n Enter nth node from the end. ");
                scanf("%d",&index);
                 node_end(&start, index);
                break;
        case 11:count(&start);
                break;
        case 12:middle(&start);
                break;
        case 13:print(&start);
                break;
        case 14:reverse(&start);
                break;
        case 15:is_circular(&start);
                break;
              }
     }while(op!=0);
     return 0;
  }
