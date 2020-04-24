#include<stdio.h>
#include<stdlib.h>
#define n 10000
#include<time.h>
int comp=0;
int swap=0;
void quick(int arr[],int low,int high)
{   if(low<high)
    {
          int index=part(arr,low,high);
          quick(arr,low,index-1);
          quick(arr,index+1,high);
     }
}
int part(int arr[],int low,int high)
{  int j,temp;
   int pivot=arr[high];
   int i=(low-1);
   for( j=low;j<=high-1;j++)
   { comp++;
    if(arr[j]<=pivot)
    { i++;
      swap++;
      temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp; }
    }
    temp=arr[i+1];
    arr[high]=arr[i+1];
    arr[i+1]=arr[high];
    return (i+1);
 }
int main(){
 clock_t t;
    t = clock();
 int arr[n];
 int i,j,m,temp;
 for(i=0;i<n;i++)
    arr[i]= rand() ;
 quick(arr,0,n-1);
 for(i=0;i<n;i++)
    printf("%d  ",arr[i]);
  printf("\n");
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC;
  printf("Run Time:%f\n",time_taken);
  printf("Number of swapping:%d\n Number of Comparison:%d\n ",swap,comp);

 }
