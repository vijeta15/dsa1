#include<stdio.h>

void read(int num[10][10],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
}

void transpose(int num[10][10],int r,int c)
{
    int trans[10][10];
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            trans[i][j]=num[j][i];
        }
    }
}

void display(int num[20][20],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d",num[i][j]);
        }
    }
}
int main()
{
    int num[10][10];
    int r,c,status=1;
    FILE *fp;
    //fp=fopen("text3.txt","r");
    printf("Enter row and columns\n");
    scanf("%d%d",&r,&c);
    read(num,r,c);
    transpose(num,r,c);
   // fclose(fp);
    return 0;
}
