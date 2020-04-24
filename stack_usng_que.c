#include<stdio.h>
#include<stdlib.h>
#define capacity 100
struct que{
   int *arr;
   int front;
   int rear;
   };
struct que* createque()
{
 struct que* q=(struct que*)malloc(sizeof(struct que));
 q->front=0;q->rear=0;
 q->arr=(int*)malloc(capacity * sizeof(int));
 return q;
 }
 void insert(int);
 void delete ();


  struct que* q1;
  struct que* q2;
  struct que* q3;

  int main(){
  int x,op;

      q1=createque();
       q3=createque();
      q2=createque();
  do{    printf("1.INSERT\n");
      printf("2.DELETE\n");
      printf("0.EXIT\n");
      printf("Enter Choice\n");
      scanf("%d",&op);
      switch(op)
      {
       case 1:printf("Enter data:\n");
              scanf("%d",&x);
              insert(x);
              break;
       case 2:delete();
              break;
 //      case 3:peek();
        }
      } while(op!=0);
   }
 void insert(int x)
 {
      q2->arr[q2->rear++]=x;
      while(q1->rear!=q1->front)
           q2->arr[q2->rear++]=q1->arr[q1->front++];
      q3=q1;
      q1=q2;
      q2=q3;
      }

 void delete()
 {
  if(q1->rear==q1->front)
  {    printf("UNDERFLOW\n");
       return;}
  int z= q1->arr[q1->front++];
  printf("%d\n",z);
 }

