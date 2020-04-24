#include<stdio.h>
#include<stdlib.h>
int main()
{
  printf("Enter no of Elements\n");
  int x,n;
  scanf("%d\n",&n);
  int i,a[n];
  for(i=0;i<n;i++)
      scanf("%d",&a[i]);
  printf("Enter x\n");
  scanf("%d",&x);
  for(i=1;i<n;i++)
  {
     if(a[i]>=x)
     {
         printf("Smaller Number than x is %d\n",a[i-1]);
         printf("Greater Number than x is %d\n",a[i]);
         break;     }
  }
}
