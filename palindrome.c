#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *str = (char *)malloc(sizeof(int));
    int l, i = 0, c;
    printf("Enter the string:: ");
    scanf("%s", str);
    l = strlen(str);
    char A[l];
    strcpy(A, str);
    
    while (i < (l / 2))
    {
        char temp = str[i];
        str[i] = str[(l - 1) - i];
        str[(l - 1) - i] = temp;
        i++;
    }

    c = strcmp(A, str);
    if (c == 0)
    {
        printf("Yes! it's a palendrom.");
    }
    else{
        printf("It's not palendrom.");
    }

    return 0;
}