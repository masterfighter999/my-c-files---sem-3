/* Name: Swayam Chatterjee
   B.Sc Sem III
   Data Structures
   Stack using linked list */

#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int n;
	struct stack *next;
	
};
struct stack *push(struct stack *top);
struct stack *pop(struct stack *top);
void display(struct stack *top);
void edit(struct stack *top);

void main()
{
	struct stack* top = NULL;
	edit(top);
}
void edit(struct stack *top)
{
	int ch;
	do{
		printf("Enter 1 to push, 2 to pop, 3 to display elements into the stack and 0 to exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: top = push(top);
				break;
			case 2: top = pop(top);
				break;
			case 3: display(top);
		}
	}while(ch!=0);
	printf("\n--EXIT--\n\n");
}
struct stack *push(struct stack *top)
{
	int n;
	struct stack *p = (struct stack *)calloc(1, sizeof(struct stack));
	if(p==NULL)
		printf("\nStack Overflow\n\n");
	else
	{
		printf("Enter the data to be inserted\n");
		scanf("%d",&n);
		p->n=n;
		p->next = top;
		top=p;
	}
	return top;
}
struct stack *pop(struct stack *top)
{
	if(top == NULL)
		printf("\nStack Underflow\n\n");
	else
	{
		struct stack *p = top;
		top = top->next;
		printf("\nThe popped element is %d\n\n", p->n);
		free(p);
	}
	return top;
}
void display(struct stack *top)
{
	if(top == NULL)
		printf("\nStack is empty\n\n");
	else
	{
		printf("\nThe elements are \n");
		while(top != NULL)
		{
			printf("%d\n", top->n);
			top = top->next;
		}
	}
}
