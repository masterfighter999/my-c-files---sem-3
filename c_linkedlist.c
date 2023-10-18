#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr);
void insertAtEnd(struct Node *head, int data);
struct Node *insertAtFirst(struct Node *head,int data);
struct Node *insertAtIndex(struct Node *head,int data, int index); 
struct Node *deleteFirst(struct Node *head); 
struct Node *deleteAtIndex(struct Node *head, int index); 
struct Node *deleteAtLast(struct Node *head); 
struct Node *sort_asc(struct Node *head);

int main()
{
    int n,i,a,b,index;
    struct Node *head;
    
    head = (struct Node *)calloc(1,sizeof(struct Node));
    printf("Enter the first element\n");
    scanf("%d",&a);
    head->data = a;
    head->next = head;
 

    printf("Linked list before insertion\n");
    linkedlistTraversal(head);

  step1:  printf("Press 1 to add a new list at the end, 2 to add a new node at beginning, 3 to add a new node at index or 0 to end execution\n");
    scanf("%d",&n);

    if(n==1)
    {
        printf("Insert the value you wish to enter\n");
        scanf("%d",&i);
        insertAtEnd(head,i);
        printf("Linked list after insertion\n");
        linkedlistTraversal(head);
        goto step1;
    }

    if(n==2)
    {
        printf("Insert the value you wish to enter\n");
        scanf("%d",&i); 
        head=insertAtFirst(head,i);
        linkedlistTraversal(head);
        goto step1;
    }

    if(n==3)
    {
        printf("Insert the index value\n");
        scanf("%d",&index);
        printf("Insert the value you wish to enter\n");
        scanf("%d",&i);
        head=insertAtIndex(head,i,index);
        linkedlistTraversal(head);
        goto step1;
    }

    else
    {
  step2:  printf("Press 1 to delete the first element of the list, 2 to delete a node on the list, 3 to delete the last element or 0 to end execution\n");
    scanf("%d",&n);

    if(n==1)
    {
        head=deleteFirst(head);
        linkedlistTraversal(head);
        goto step2;
    }

    if(n==2)
        {
        printf("Insert the index value you wish to delete(Remember index starts from 0)\n");
        scanf("%d",&i);
        head = deleteAtIndex(head,i);
        printf("Linked list after deletion\n");
        linkedlistTraversal(head);
        goto step2;
        }

    if(n==3)
    {
        head=deleteAtLast(head);
        linkedlistTraversal(head);
        goto step2;
    }
    }
   
printf("Enter 1 to sort the list in ascending order or 0 to end execution\n");
scanf("%d", &b);
if(b==1)
{
    head=sort_asc(head);
    linkedlistTraversal(head);
}
     return 0;
}

void linkedlistTraversal(struct Node *head)
{   
    struct Node *ptr=head;
    do{
        printf("Elements is %d\n", ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

void insertAtEnd(struct Node *head, int data)
{
    struct Node *p=head;
    //struct Node *ptr =(struct Node*)malloc(sizeof(struct Node));
    //ptr-> data =data;
    while(p->next!=NULL)
        p=p-> next;
    
    p->next = (struct Node*)malloc(sizeof(struct Node));
    p=p->next;
    p->data=data;
    p->next =NULL;
    //return head;
}

// Inserting an element at the beginning
struct Node *insertAtFirst(struct Node *head,int data)
{
    struct Node *ptr = (struct Node*)calloc(1,sizeof(struct Node));
    ptr->data=data;
    
    struct Node *p = head->next;
    while(p->next != head)
    {
        p=p->next;
    }

    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head; 
}

//Inserting the element at a given index
struct Node *insertAtIndex(struct Node *head,int data, int index)
{
    struct Node *ptr = (struct Node*)calloc(1,sizeof(struct Node));
    struct Node *p = head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

//deleting the first element from the  list
struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

//Deleting the element at a given index
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for(int i=0; i<index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

//Deleting the last element
struct Node *deleteAtLast(struct Node *head)
{
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->next != NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct Node *sort_asc(struct Node *head)
{
	struct  Node *p,*q;
	p=head;
	int t;
    //p = (struct Node*)calloc(1,sizeof(struct Node));
   // q = (struct Node*)calloc(1,sizeof(struct Node));

	while(p->next!=NULL)
	{
		q=p->next;
		while(q!=NULL)
		{
			if(p->data>q->data)
			{
				t=p->data;
				p->data=q->data;
				q->data=t;
			}
			q=q->next;
		}
		p=p->next;
	}
 
	return head;
} 


