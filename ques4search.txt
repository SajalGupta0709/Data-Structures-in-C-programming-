#include<stdio.h>
#include<stdlib.h>
int main()
{
  int n,i,j;
  printf("Enter no of elements\n");
  scanf("%d",&n);
  int a[n],c=-1;
  for(i=0;i<n;i++)
     scanf("%d",&a[i]);
  for(i=0;i<n;i++)
  {
     for(j=0;j<n;j++)
     {
        if(i!=j && a[i]==a[j])
           c=0;
     }

     if(c==-1)
     {  printf("Req No %d\n",a[i]);
        break;
     } c=-1;
  }
}
