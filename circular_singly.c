#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void read(struct Node *head);
void edit(struct Node *head);
void display(struct Node *head);
struct Node *insert_beg(struct Node *head, int val);
void insert_end(struct Node *head, int val);
void insert_middle(struct Node *head, int index, int value);
struct Node *delete_beg(struct Node *head);
void delete_end(struct Node *head);
void delete_middle(struct Node *head, int index);

struct Node *mem_alo()
{
	struct Node *head = (struct Node *)calloc(1, sizeof(struct Node));
	head->next = NULL;
}
int main()
{
	struct Node *head = mem_alo();
	read(head);
	edit(head);
	return 0;
}
void read(struct Node *head)
{
	int d;
	struct Node *p = head;
  step1:printf("Enter the number to be stored:\n");
	scanf("%d",&p->data);
  step2:printf("Enter 1 to enter new value or 0 to exit:\n");
	scanf("%d",&d);
	if(d==1)
	{
		p->next=mem_alo();
		p=p->next;
		goto step1;
	}
	else if(d!=1 && d!=0)
		goto step2;
	p->next = head;
}
void edit(struct Node *head)
{
	int ch,n,i;
	do{
		printf("\nEnter 1 to insert at beginning, 2 to insert at end, 3 to insert at middle\n");
		printf("Enter 4 to delete at beginning, 5 to delete at end, 6 to delete at middle\n");
		printf("Enter 7 to display forward and 0 to EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the number to be inserted at beginning\n");
				scanf("%d",&n);
				head=insert_beg(head,n);
				break;
			case 2: printf("\nEnter the number to be inserted at end\n");
				scanf("%d",&n);
				insert_end(head,n);
				break;
			case 3: printf("\nEnter the number to be inserted at middle followed by index number\n");
				scanf("%d%d",&n,&i);
				insert_middle(head, i, n);
				break;
			case 4: head=delete_beg(head);
				printf("\nSuccessfully deleted\n");
				break;
			case 5: delete_end(head);
				printf("\nSuccessfully deleted\n");
				break;
			case 6: printf("\nEnter the index to be deleted\n");
				scanf("%d",&i);
				delete_middle(head,i);
				break;
			case 7: printf("\nDisplaying\n");
				display(head);
		}
	}while(ch!=0);
	printf("\n---EXIT---\n\n");
}
struct Node *insert_beg(struct Node *head, int val)
{
	struct Node *ptr = mem_alo();
	struct Node *p=head;
	while(p->next!=head)
		p=p->next;
	ptr->data=val;
	ptr->next=head;
	p->next = ptr;
	head=ptr;
	return head;
}
void insert_end(struct Node *head, int val)
{
	struct Node *ptr = mem_alo();
	struct Node *p = head;
	ptr->data=val;
	while(p->next!=head)
		p=p->next;
	p->next = ptr;
	ptr->next = head;
}
void insert_middle(struct Node *head,int index,int value)
{
	struct Node *ptr= mem_alo();
	struct Node *p = head;
	int i=0;
	ptr->data=value;
	while(i!=index-1)
	{
		p=p->next;
		i++;
	}
	ptr->next = p->next;
	p->next = ptr;
}
struct Node *delete_beg(struct Node *head)
{
	struct Node *p=head;
	while(p->next!=head)
		p=p->next;
	head=head->next;
	p->next = head;
	return head;
}
void delete_end(struct Node *head)
{
	struct Node *p = head;
	struct Node *pre = p;
	while(p->next!=head)
	{
		pre = p;
		p=p->next;
	}
	pre->next = head;
	free(p);
}
void delete_middle(struct Node *head, int index)
{
	int i=0;
	struct Node *ptr=mem_alo();
	struct Node *p = head;
	ptr=head->next;
	while(i!=index-1)
	{
		p=p->next;
		ptr=ptr->next;
		i++;
	}
	p->next=ptr->next;
	free(ptr);
}
void display(struct Node *head)
{
	struct Node *p = head;
	while(p->next != head)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
}
