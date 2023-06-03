#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *fp1,*fp2;
    char c;
    int co=1;
    fp1=fopen("a.txt","r");
    if(fp1==NULL)
    {
     printf("not exist\n");
     exit(0);

    }
    fp2=fopen("b.txt","w");
    if(fp2==NULL)
    {
     printf("not exist\n");
     exit(0);

    }
    while((c=fgetc(fp1))!=EOF)
    {
        if(c=='\n')
          co++;
    }
    fprintf(fp2,"%d",co);
    fclose(fp1);
    fclose(fp2);

}

