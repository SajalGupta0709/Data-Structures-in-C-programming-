#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
  int i,m,r,l,n,s;
  clock_t t;
    t = clock();
  printf("Enter the number of elements u want to enter:");
  scanf("%d\n",&n);
  r=n-1;
  int arr[n];
  for(i=0;i<n;i++)
     scanf("%d",&arr[i]);
  printf("\nEnter element u want  to search:");
  scanf("%d",&s);
  while(l<=r)
  {
    m=l+(r-1)/2;
    if(arr[m]==s)
    {    printf("number found at position %d\n",m+1);
      t = clock() - t;
     double time_taken = ((double)t)/CLOCKS_PER_SEC;
     printf("Run Time:%f\n",time_taken);
      return 0;}
    if(arr[m]<s)
      l=m+1;
    else  r=m-1;
  }
  printf("NUmber not found.\n");
   t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC;
  printf("Run Time:%f\n",time_taken);
}
