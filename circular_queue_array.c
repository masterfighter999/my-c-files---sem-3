/*Name: Swayam Chatterjee
  B.Sc Sem III
  Data Structures
  Circular Queue using array - enqueue, dequeue, display */

#include<stdio.h>
#include<stdlib.h>

int front = -1, rear = -1, n;

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
		printf("Enter 1 to enqueue, 2 to dequeue, 3 to display and 0 to exit\n");
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
	if((front == rear + 1) || (front == 0 && rear == n - 1))
		printf("\nQueue is full\n\n");
	else
	{
		if (front == -1) 
			front = 0;
    		rear = (rear + 1) % n;
		printf("Enter the element to inserted\n");
		scanf("%d", &queue[rear]);
	}
}
void dequeue(int *queue)
{
	int element;
	if(front == -1)
		printf("\nQueue is empty\n\n");
	else
	{
		element = queue[front];
		if (front == rear) {
      		front = -1;
      		rear = -1;
    		}
    		else 
      		front = (front + 1) % n;
    		printf("\nDeleted element is %d \n", element);
	}
}
void display(int *queue)
{
	int i=0;
	if(front == -1)
		printf("\nQueue is empty\n\n");
	else
	{
		printf("Elements are\n");
		for(i = front; i!=rear;i = (i+1)%n)
			printf("%d\n", queue[i]);
		printf("%d\n", queue[i]);
	}
}
