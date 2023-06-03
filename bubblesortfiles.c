#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num[10];
    int temp;
    FILE *fp1,*fp2;
    fp1=fopen("a.txt","r");
    fp2=fopen("b.txt","w");
    int n;
    fscanf(fp1,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fp1,"%d",&num[i]);
    }
    for(int k=0;k<n-1;k++)
    {
        for(int m=0;m<n-k-1;m++)
        {
            if(num[m]<num[m+1])
            {
                temp=num[m];
                num[m]=num[m+1];
                num[m+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        fprintf(fp2," %d",num[i]);
    }

    fclose(fp1);
    return 0;
}
