#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void mergesort(int a[],int lb,int up);
void merge(int a[],int lb,int mid,int up);
void selectionsort(int a[],int n);
void quicksort(int a[],int lb,int ub);
int main()
{
    float duration;
    clock_t start,end;
    int lo,up,n,i,num[200];
    srand(time(0));
    printf("enter no\n");
    scanf("%d",&n);
     printf("enter lo\n");
    scanf("%d",&lo);
     printf("enter up\n");
    scanf("%d",&up);
    for(i=0;i<n;i++)

    {
       num[i]=(rand()%(up-lo+1))+lo;
        printf("%d ",num[i]);
    }
    printf("\n");
    start=clock();
    mergesort(num,0,n-1);
    end=clock();
    duration=(float)(end-start)/ CLOCKS_PER_SEC;
     printf("after sort\n");
      for(i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }
    printf("Time taken: %f seconds\n", duration);
    printf("\n");
    start=clock();
    selectionsort(num,n);
       end=clock();
    duration=(float)(end-start)/ CLOCKS_PER_SEC;
     printf("after sort\n");
      for(i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }
    printf("Time taken: %f seconds\n", duration);
    printf("\n");
    start=clock();
    quicksort(num,1,n);
       end=clock();
    duration=(float)(end-start)/ CLOCKS_PER_SEC;
     printf("after sort\n");
      for(i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }
    printf("Time taken: %f seconds\n", duration);
    return 0;
}

void mergesort(int a[],int lb,int up)
{
    int mid;
    if(lb<up)
    {
        mid=(lb+up)/2;
         mergesort(a,lb,mid);
          mergesort(a,mid+1,up);
           merge(a,lb,mid,up);

    }
}
void merge(int a[],int lb,int mid,int up)
{
    int b[20];
   int k=mid+1;
    mid=(lb+up)/2;
   int l=lb;
int   start=lb;
   while(lb<=mid && k<=up)
   {
       if(a[lb]>=a[k])
       {
           b[l]=a[k];
           k++;
       }
       else
       {
           b[l]=a[lb];
           lb++;
       }
       l++;
   }
   if(lb>mid)
   {
       while(k<=up)
       {
           b[l]=a[k];
           l++;
           k++;
       }
   }
   else
   {
     while(lb<=mid)
     {
         b[l]=a[lb];
         l++;
         lb++;
     }
   }

   for(l=start;l<=up;l++)
    a[l]=b[l];
}

void selectionsort(int a[],int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
       {
           if(a[j]<a[min])
           {
               min=j;
           }

       }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
}

void quicksort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }

}
int partition(int a[],int lb,int ub)
{
  int temp;
  int start=lb;
  int end=ub;
  int p=a[lb];
  while(start<end)
  {
      while(a[start]<=p && start<end)
      start=start+1;
      while(a[end]>p)
        end=end-1;
      if(start<end)
      {

          temp=a[start];
          a[start]=a[end];
          a[end]=temp;
      }



  }
  a[lb]=a[end];
  a[end]=p;
  return end;
}
