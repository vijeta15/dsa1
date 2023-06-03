 #include<stdio.h>
 #include<stdlib.h>
 void main()
  {
     FILE *fp1,*fp2;
     char str[100],longest[100];
     int len=0;
     fp1=fopen("a.txt","r");
     if(fp1==NULL)
     {
      printf("not exist\n");
      exit(0);

     }



     while(fgets(str,sizeof(str),fp1)!=NULL)
     {
        if(len<strlen(str))
        {
            strcpy(longest,str);
            len=strlen(str);
        }
    }

    printf("%s",longest);
     fclose(fp1);


}

