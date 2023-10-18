#include <stdio.h>
#include<string.h>

void reverse (char *str);

int main(void)
{
    int *s; 
    s=(char*)malloc(sizeof(char));
    printf("Enter the string : ");
    gets(s);

    reverse(s);
    printf("%s\n",s);

}

void reverse(char *str)
{
    int length = strlen(str);
    int middle = length/2;
    char temp;
    for (int i=0; i<middle;i++)
    {
        temp = str[i];
        str[i]= str[length -i-1];
        str[length -i-1]= temp;
    }
}