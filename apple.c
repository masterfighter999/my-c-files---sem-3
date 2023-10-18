#include<stdio.h>

main ()
{
    char *str,ch='\0';
    int i,end;
    printf("Enter the size of the string");
    scanf("%d",&end);
    printf("Enter the string");
        
    while(ch!='\n')
     {
         	scanf("%c",&ch);
            str[i]=ch;
     }
}

void print(char *str, int end)
{
    for(int i=0;i<end;i++)
    {
        printf("\n");
      for(int j=0;j<i-1;j++)
        {
            printf("%s",str);
        }
    }    
}