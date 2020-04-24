#include<stdlib.h>
void reverse(int* arr,int length)
{
  int t,l=0,r=length-1;
  while(l<r)
  {
   t=arr[l];
   arr[l]=arr[r];
   arr[r]=t;
   l++;
   r--;
  }
}
void heapify(int* arr,int length,int index)
{
  int l,t,r,small;
  while(1)
  {
     l=((index+1)*2)-1;
     r=(index+1)*2;
     if(l>=length)  return;
     int small=(r<length)?(arr[l]<arr[r]?l:r):l;
     if(arr[index]>arr[small])
     {  t=arr[index];
        arr[index]=arr[small];
        arr[small]=t;
        index=small;}
     else   break;
     }
}
void delete(int *arr,int length)
{
  if(length<0) return ;
  int t;
  t= arr[0];
  arr[0]=arr[length-1];
  arr[length-1]=t;
  heapify(arr,length-1,0);
}
void deletion(int *arr,int length)
{
  if(length<0) return ;
  int i;
  printf("delete:\n");
  arr[0]=arr[length-1];
  heapify(arr,length-2,0);
  for(i=0;i<length-1;i++)
     printf("%d ",arr[i]);
   printf("\n");
   printf("NEW ROOT TO BE SEARCHED:%d\n",arr[0]);

}
void heapsort(int* arr,int length)
{
   int i;
   for (i = length / 2 - 1; i >= 0; i--)
        heapify(arr, length, i);
   for(i=0;i<length;i++)
       delete(arr,length-i);
   reverse(arr,length);
 }
int main()
{  int n,i;
   printf("Enter number of elements\n");
    scanf("%d",&n);
   int arr[n];
   printf("Enter array\n");
   for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
   heapsort(arr,n);
   printf("Heap:\n");
   for(i=0;i<n;i++)
     printf("%d ",arr[i]);
   printf("\n");
   deletion(arr,n);
}
