/*Name: Swayam Chatterjee
  B.Sc Sem III
  Data Structures
  Queue using linked list - enqueue, dequeue, display */

#include<stdio.h>
#include<stdlib.h>

struct queue *front = NULL;
struct queue *rear = NULL;

struct queue
{
	int data;
	struct queue *next;
};

void edit();
void enqueue(int n);
void dequeue();
void display();

void main()
{
	edit();
}
void edit()
{
	int d, n;
	do
	{
		printf("Enter 1 to inqueue, 2 to dequeue, 3 to display and 0 to exit\n");
		scanf("%d",&d);
		switch (d)
		{
			case 1: printf("Enter the element to be stored\n");
				scanf("%d", &n);
				enqueue(n);
				break;
			case 2:dequeue();
				break;
			case 3: display();
		}
	}while(d!=0);
}
void enqueue(int n)
{
	struct queue *p = (struct queue *)calloc(1, sizeof(struct queue));
	if(p==NULL)
		printf("\nQueue is full\n\n");
	else
	{
		p->data = n;
		p->next = NULL;
		if(front==NULL)
			front=rear=p;
		else
		{
			rear->next = p;
			rear = p;
		}
	}
}
void dequeue()
{
	struct queue *p = front;
	if(front == NULL)
		printf("\nQueue is empty\n\n");
	else
	{
		front= front->next;
		printf("The element removed is %d\n", p->data);
		free(p);
	}
}
void display()
{
	struct queue *p = front;
	if(p == NULL)
		printf("\nQueue is empty\n\n");
	else
	{
		printf("\nElements are\n");
		while(p != NULL)
		{
			printf("%d\n", p -> data);
			p = p->next;
		}
	}
}
