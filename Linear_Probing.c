#include <stdio.h>
#include <stdlib.h>
#define SIZE 13

int hasharr[SIZE]={};
int count;

int CalculateHash(int key) {
    return key % SIZE;
}

void Insert(int element) {
    if(count == SIZE){
        printf("\nTable if FULL\n");
    }
    int probe = CalculateHash(element);
    int i = 0;
    while(hasharr[probe] != 0 && hasharr[probe] != -1) {
        probe = (probe + 1) % SIZE;
        i++;
    }
    hasharr[probe] = element;
    count++;
}

void Delete(int element) {
    if(count==0){
        printf("\nTable if EMPTY\n");
    }
    int loc=Search(element);
    if(loc!=-1) { // means element is present
        hasharr[loc] = -1;
        count--;
    }
}

int Search(int element) {
    if(count == 0){
        printf("\nTable if EMPTY\n");
    }
    int probe = CalculateHash(element);
    while(hasharr[probe] != 0) {
        if(hasharr[probe] == element)
            return probe;
        probe=(probe+1) % SIZE;
    }
    return -1;
}

void PrintList() {
    int i;
    for(i=0;i<SIZE;i++)
        printf("%d%c",hasharr[i],' ');
}

/*
 * 
 */
int main(int argc, char** argv) {

    int element,i;
    int keys[10] = {12,14,16,18,19,20,25,38,51,64};
    count = 0;
    
    for(i = 0; i < 10; i++) {
        //calculate hash key
        element = keys[i];
        Insert(element);
    }
    printf("\nThe contents of the hash table is as follows: \n");
    PrintList();

    
    element = 89;
    int loc = Search(element);
    if(loc == -1) {
         printf("\nElement %d not found.\n",element);
    } else {
        printf("\nElement %d is at position %d in hash table.\n",element, loc);
    }
    
    
    element = 19;
    Delete(element);
    printf("\nThe contents of the hash table after deleting %d is as follows: \n", element);
    PrintList();

    
    
}

