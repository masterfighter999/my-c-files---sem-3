#include<stdio.h>
#include<stdlib.h>

void reverse(char *str, int l);

int main()
{
    	char *str, ch='\0';
   	int i=0;
     str=(char *)calloc(1,sizeof(char));
     printf("Enter a string\n");
     while(ch!='\n')
     {
         	scanf("%c",&ch);
         	str=(char *)realloc(str,sizeof(char));
         	str[i]=ch;
         	i++;
     }
    
    printf("The string in reverse order is :");
     reverse(str, i-1);
	printf("%s", str);
	free(str);
	return 0;
}

void reverse(char *str, int l)
{
	char ch;
	for(int i=0;i<l/2;i++)
	{
		ch=str[i];
		str[i]=str[l-i-1];
		str[l-i-1]=ch;
	}
}