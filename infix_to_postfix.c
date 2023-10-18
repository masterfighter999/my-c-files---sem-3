/*Name: Swayam Chatterjee
  B.Sc Sem III
  Data Structures
  Infix to postfix expression and evaluation of postfix expression using stack */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

char *stack;
int top = -1;

void push(char x);
char pop();
char *in2pos(char *infix, char *postfix);
int isoperator(char ch);
int priority(char x);
void postfixEvaluation(char *exp);

int main()
{
    char *infix, *postfix, x, ch;
    int i, l, ans;
    stack = (char *)calloc(50, sizeof(char));
    infix = (char *)calloc(1, sizeof(char));
    printf("Enter the expression : \n");
    while(ch!='\n')
     {
         	scanf("%c",&ch);
         	infix[l]=ch;
         	infix=(char *)realloc(infix,sizeof(char));
         	l++;
     }
     infix[l-1]='\0';
     postfix = (char *)calloc(l, sizeof(char));
     in2pos(infix, postfix);
     printf("%s\n", postfix);
     postfixEvaluation(postfix);
    return 0;
}
void push(char x)
{
	top++;
     stack[top] = x;
}
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
char *in2pos(char *infix, char *postfix)
{
	int i = 0, j = 0, x;
	while(infix[i] != '\0')
     {
        if(!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
        }
        else if(infix[i] == '(')
            push(infix[i]);
        else if(infix[i] == ')')
        {
            while((x = pop()) != '(')
            {
                postfix[j]=x;
                j++;
            }
        }
        else
        {
            while(priority(stack[top]) >= priority(infix[i]))
            {
                postfix[j] = pop();
                j++;
            }
            push(infix[i]);
        }
        i++;
     }
    
     while(top != -1)
     {
        postfix[j] = pop();
        j++;
     }
}
int priority(char x)
{
    
    if(x == '^')
    	   return 3;
    if(x == '*' || x == '/')
        return 2;
    if(x == '+' || x == '-')
        return 1;
    return 0;
}

int isoperator(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' || ch =='/' || ch == '(' || ch == ')' || ch == '^')
		return 1;
	else
		return 0;
}
void postfixEvaluation(char *exp)
{
	int n1,n2,n3,num,i=0;
    while(exp[i] != '\0')
    {
        if(!isoperator(exp[i]))
        {
            num = exp[i] - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(exp[i])
            {
		       case '+':
		           n3 = n1 + n2;
		           break;
		       case '-':
		           n3 = n2 - n1;
		           break;
		       case '*':
		           n3 = n1 * n2;
		           break;
		       case '/':
		           n3 = n2 / n1;
		           break;
		       case '^':
		           n3 = (int)pow(n1,n2);
		           break;
            }
            push(n3);
        }
        i++;
    }
    printf("\nThe result of expression  =  %d\n",pop());
}
