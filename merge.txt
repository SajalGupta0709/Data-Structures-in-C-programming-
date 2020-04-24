#include<stdio.h>
#include<stdlib.h>
#define n 10000
#include<time.h>
int comp=0;
int swap=0;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
   for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i=j=0;
     k=1;
 while (i < n1 && j < n2)
    { comp++;
        if (L[i] <= R[j])
        { swap++;
            arr[k] = L[i];
            i++;
        }
        else
        { swap++;
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 while (i < n1)
    { swap++;
        arr[k] = L[i];
        i++;
        k++;
    }
  while (j < n2)
    { swap++;
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {  int m = l+(r-l)/2;
       mergeSort(arr, l, m);
              mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
int main(){
 clock_t t;
    t = clock();
 int arr[n];
 int i,j,m,temp;
 for(i=0;i<n;i++)
    arr[i]= rand() ;
 mergeSort(arr,0,n);
 for(i=0;i<n;i++)
    printf("%d  ",arr[i]);
  printf("\n");
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC;
  printf("Run Time:%f\n",time_taken);
  printf("Number of swapping:%d\n Number of Comparison:%d\n ",swap,comp);

 }
