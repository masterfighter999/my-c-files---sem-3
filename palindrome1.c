#include<stdio.h>
#include<stdlib.h>

int check(char *str, int n);

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
     if(check(str, i-1)==1)
		printf("Palindrome string\n");
	else
		printf("Not a palindrome string\n");
	return 0;
}
int check(char *str, int n)
{
	for(int i=0;i<=n/2;i++)
		if(str[i]!=str[n-i-1])
			return 0;
	return 1;
}