#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char a[10000],ns[1000][200];
    printf("enter a string\n");
    gets(a);
   // scanf("%s",a);
    int i,j=0,k=0,m=0,n=0,max,min;
    {
        for(i=0;i<a[i]!=NULL;i++)
        {
            if(a[i]==' ')
            {
                ns[k][j]='\0';
                k++;
                j=0;
            }
            else
            {
                ns[k][j]=a[i];
                j++;
            }
        }
        ns[k][j]='\0';
        max=strlen(ns[0]);
        min=strlen(ns[0]);
        for(i=0;i<=k;i++)
        {
            if(max<strlen(ns[i]))

            m=i;
            if(min>strlen(ns[i]))
            n=i;
        }


    }
    printf("largest word =%s and smallest word =%s is",ns[m],ns[n]);
    getch();
   // printf("%s%s",ns[m],ns[n]);
    return 0;
}
