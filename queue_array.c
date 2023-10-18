/*Name: Swayam Chatterjee
  B.Sc Sem III
  Data Structures
  Queue using array - enqueue, dequeue, display */

#include<stdio.h>
#include<stdlib.h>

int front = 0, rear = -1, n;

void edit(int *queue);
void enqueue(int *queue);
void dequeue(int *queue);
void display(int *queue);

void main()
{
	printf("Enter the size of queue\n");
	scanf("%d", &n);
	int *queue = (int *)calloc(n, sizeof(int));
	edit(queue);
}
void edit(int *queue)
{
	int d;
	do
	{
		printf("Enter 1 to inqueue, 2 to dequeue, 3 to display and 0 to exit\n");
		scanf("%d",&d);
		switch (d)
		{
			case 1: enqueue(queue);
				break;
			case 2: dequeue(queue);
				break;
			case 3: display(queue);
		}
	}while(d!=0);
}
void enqueue(int *queue)
{
	if(rear == n)
		printf("\nQueue is full\n\n");
	else
	{
		printf("Enter the element to be added\n");
		rear++;
		scanf("%d", &queue[rear]);
	}
}
void dequeue(int *queue)
{
	if(rear < front)
		printf("\nQueue is empty\n\n");
	else
	{
		printf("Deleted element is %d\n", queue[front]);
		front++;
	}
}
void display(int *queue)
{
	if(front > rear)
		printf("\nQueue is empty\n\n");
	else
	{
		printf("Elements are\n");
		for(int i = front; i<=rear;i++)
			printf("%d\n", queue[i]);
	}
}
