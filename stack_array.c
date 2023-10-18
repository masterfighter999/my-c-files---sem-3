/* Name:Swayam Chatterjee
   B.Sc Sem III
   Data Structures
   Stack using array */

#include<stdio.h>
#include<stdlib.h>

int n, top=-1;

void edit(int *stack);
void push(int *stack);
void pop(int *stack);
void display(int *stack);

void main()
{
	printf("Enter the size of stack\n");
	scanf("%d",&n);
	int *stack = (int *)calloc(n, sizeof(int));
	edit(stack);
}
void edit(int *stack)
{
	int ch;
	do{
		printf("Enter 1 to push, 2 to pop, 3 to display and 0 to exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push(stack);
				break;
			case 2: pop(stack);
				break;
			case 3: display(stack);
				break;
		}
	}while(ch!=0);
	printf("--EXIT--\n");
}
void push(int *stack)
{
	int x;
	if(top>=n-1)
		printf("\nStack Overflow\n\n");
	else
	{
		printf("Enter the number to be pushed\n");
		scanf("%d", &x);
		top++;
		stack[top]=x;
	}
}
void pop(int *stack)
{
	if(top<=-1)
		printf("\nStack Underflow\n\n");
	else
	{
		printf("The popped element is %d\n\n", stack[top]);
		top--;
	}
}
void display(int *stack)
{
	if(top == -1)
		printf("\nStack is empty\n\n");
	else
	{
		printf("Displaying elements are\n");
		for(int i=top;i>-1;i--)
			printf("%d\n",stack[i]);
	}
}
