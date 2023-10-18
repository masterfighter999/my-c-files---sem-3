#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
};

void edit(struct Node *head, struct Node *tail);
struct Node *read(struct Node *head);
void display_std(struct Node *head);
void display_rev(struct Node *tail);
struct Node *insert_beg(struct Node *head, struct Node *tail, int val);
struct Node *insert_end(struct Node *head, struct Node *end, int val);
void insert_middle(struct Node *head,int index,int value);
struct Node *delete_beg(struct Node *head, struct Node *tail);
struct Node *delete_end(struct Node *head, struct Node *tail);
void delete_middle(struct Node *head, int index);

struct Node *mem_alo()
{
	struct Node *p=(struct Node *)calloc(1,sizeof(struct Node));
	p->prev=NULL;
	p->next=NULL;
	return p;
}

void main()
{
	struct Node *head=mem_alo();
	struct Node *tail=mem_alo();
	tail = read(head);
	
	edit(head, tail);
}
struct Node *read(struct Node *head)
{
	struct Node *p = head;
	int d;
  step1:printf("Enter the number to be stored:\n");
	scanf("%d",&p->data);
  step2:printf("Enter 1 to enter new value or 0 to exit:\n");
	scanf("%d",&d);
	if(d==1)
	{
		p->next=mem_alo();
		p->next->prev=p;
		p=p->next;
		goto step1;
	}
	else if(d!=1 && d!=0)
		goto step2;
	p->next = head;
	head->prev = p;
	return p;
}
void edit(struct Node *head, struct Node *tail)
{
	int ch,n,i;
	do{
		printf("\nEnter 1 to insert at beginning, 2 to insert at end, 3 to insert at middle\n");
		printf("Enter 4 to delete at beginning, 5 to delete at end, 6 to delete at middle\n");
		printf("Enter 7 to display forward, 8 to display backward and 0 to EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the number to be inserted at beginning\n");
				scanf("%d",&n);
				head=insert_beg(head,tail,n);
				break;
			case 2: printf("\nEnter the number to be inserted at end\n");
				scanf("%d",&n);
				tail=insert_end(head,tail,n);
				break;
			case 3: printf("\nEnter the number to be inserted at middle followed by index number\n");
				scanf("%d%d",&n,&i);
				insert_middle(head, i, n);
				break;
			case 4: printf("\n%d is deleted\n", head->data);
				head=delete_beg(head,tail);
				break;
			case 5: printf("\n%d is deleted\n", tail->data);
				tail=delete_end(head,tail);
				break;
			case 6: printf("\nEnter the index to be deleted\n");
				scanf("%d",&i);
				delete_middle(head,i);
				break;
			case 7: printf("\nDisplaying forward\n");
				display_std(head);
				break;
			case 8: printf("\nDisplaying backward\n");
				display_rev(tail);
		}
	}while(ch!=0);
	printf("\n---EXIT---\n\n");
}
struct Node *insert_beg(struct Node *head, struct Node *tail, int val)
{
	struct Node *ptr = mem_alo();
	ptr->data=val;
	ptr->prev=tail;
	ptr->next=head;
	head->prev=ptr;
	tail->next=ptr;
	head=ptr;
	return head;
}
struct Node *insert_end(struct Node *head, struct Node *end, int val)
{
	struct Node *ptr = mem_alo();
	ptr->data=val;
	ptr->next=head;
	ptr->prev=end;
	end->next=ptr;
	head->prev=ptr;
	end=ptr;
	return end;
}
void insert_middle(struct Node *head,int index,int value)
{
	struct Node *ptr=mem_alo();
	int i=0;
	ptr->data=value;
	while(i!=index-1)
	{
		head=head->next;
		i++;
	}
	ptr->next=head->next;
	head->next=ptr;
	head=head->next;
	head=head->next;
	ptr->prev=head->prev;
	head->prev=ptr;
}
struct Node *delete_beg(struct Node *head, struct Node *tail)
{
	head=head->next;
	head->prev=tail;
	tail->next= head;
	return head;
}
struct Node *delete_end(struct Node *head, struct Node *tail)
{
	tail=tail->prev;
	tail->next=head;
	head->prev= tail;
	return tail;
}
void delete_middle(struct Node *head, int index)
{
	int i=0;
	struct Node *ptr=(struct Node*)calloc(1, sizeof(struct Node));
	ptr=head->next;
	while(i!=index-1)
	{
		head=head->next;
		ptr=ptr->next;
		i++;
	}
	head->next=ptr->next;
	head=head->next;
	head->prev=ptr->prev;
	free(ptr);
}
void display_std(struct Node *head)
{
	struct Node *p= head;
	while(p->next!= head)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
}
void display_rev(struct Node *tail)
{
	struct Node *p=tail;
	while(p->prev!=tail)
	{
		printf("%d\n",p->data);
		p=p->prev;
	}
	printf("%d\n", p->data);
}
