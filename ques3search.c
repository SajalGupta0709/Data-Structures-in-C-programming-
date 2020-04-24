#include<stdio.h>
#include<stdlib.h>
int main()
{
  int n,x=0,i,j;
  printf("Enter no of elements\n");
  scanf("%d",&n);
  int a[n],c=-1;
  for(i=0;i<n;i++)
     scanf("%d",&a[i]);
  for(i=1;i<n-1;i++)
  {
     for(j=0;j<i;j++)
     {
        if(a[j]>a[i])
        {
            c=0;
          break;  }
     }
     if(c==-1)
     {
          for(j=i+1;j<n;j++)
          {
            if(a[j]<a[i])
            {  c=0;
               break;}
      }   }

     if(c==-1)
     { x++;
       printf("Index is %d\n",i);}
    c=-1;
  }
  if(x==0)
  printf("-1\n");
  }
