/* Name: Swayam Chatterjee
   B.Sc Sem III
   Data Structures
   Circular Queue using linked list - enqueue, dequeue, display */

#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int data;
	struct queue* next;
};

struct queue *front = NULL;
struct queue *rear = NULL;

void edit();
void enqueue();
void dequeue();
void display();

void main()
{
	edit();
}
void edit()
{
	int d;
	do
	{
		printf("Enter 1 to enqueue, 2 to dequeue, 3 to display and 0 to exit\n");
		scanf("%d",&d);
		switch (d)
		{
			case 1: enqueue();
				break;
			case 2: dequeue();
				break;
			case 3: display();
		}
	}while(d!=0);
}
void enqueue()
{
	int n;
	struct queue *new = (struct queue*)calloc(1, sizeof(struct queue));
	printf("Enter the data to be inserted\n");
	scanf("%d",&n);
	new->data = n;
	new->next = NULL;
	if(rear==NULL && front==NULL)
	{
		front = rear = new;
		rear->next = front;
	}
	else
	{
		rear->next = new;
		rear = new;
		new->next = front;
	}
} 
void dequeue()
{
	struct queue* temp;
	temp = front;
	if(front==NULL && rear==NULL)
		printf("\nQueue is Empty\n\n");
	else if(front == rear)
	{
		printf("The deleted element is %d\n", front->data);
		front = rear = NULL;
		free(temp);
	}
	else{
		printf("The deleted element is %d\n", front->data);
		front = front->next;
		rear->next = front;
		free(temp);
	}
	
	
}
void display()
{
	struct queue *p;
	p = front;
	if(front==NULL && rear==NULL)
		printf("\nQueue is Empty\n\n");
	else
	{
		printf("Elements are\n");
		while(p->next!=front)
		{
			printf("%d\n",p->data);
			p=p->next;
		}
		printf("%d\n",p->data);
	}
}
