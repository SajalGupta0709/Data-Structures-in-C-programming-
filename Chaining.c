/* 
 * File:   main.c
 * Author: Lenovo
 *
 * Created on February 18, 2019, 11:20 PM
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
} node;
    //add a new node at the end of the list
node* Insert_End(node* head, int data) {
    if(head == NULL) {
        node* new_node;
        new_node = (node*)malloc(sizeof(node));
        new_node->data = data;
        new_node->next = head;
        head = new_node;
        return head;
    }
    
    /* Create a new node */
    node* new_node;
    new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    
    /* go to the last node */
    node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
 
    /* create a new node */
    temp->next = new_node;

    return head;
}

void Traverse(node* head) {
    node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main(int argc, char** argv) {
    
    /*-- CHAINING --*/
    int n, hashTableSize, i, index, key;
   
    printf("\nEnter the size of the hash table: ");
    scanf("%d",&hashTableSize);  
    
    struct node *hashTableChaining[hashTableSize];
    for(i = 0; i < hashTableSize; i++) {
        hashTableChaining[i] = NULL;
    }
    
    int keys[10] = {2,5,8,9,6,19,15,69,36,89};
    
    for(i = 0; i < 10; i++) {
        //calculate hash key
        key = keys[i];
        //key = 2*i + 4;
        
        index = key %hashTableSize;

        //check if chain[key] is empty
        if(hashTableChaining[index] == NULL) {
            //Insert directly
            hashTableChaining[index] = Insert_End(hashTableChaining[index], key);  
        } else { //collision
            hashTableChaining[index] = Insert_End(hashTableChaining[index], key);  
        }

    }

    printf("\nThe contents of the hash table is as follows: \n");
    for(i = 0; i < hashTableSize; i++) {
        printf("hashTableChaining[%d] = ",i);
        Traverse(hashTableChaining[i]);
        printf("\n");
    }

    return (EXIT_SUCCESS);
}

