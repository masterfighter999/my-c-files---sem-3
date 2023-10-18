#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr);
void insertAtEnd(struct Node *head, int data);  
    

int main()
{
    int n,i,a;
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the first element\n");
    scanf("%d",&a);
    head->data = a;
    head->next = NULL;
 

    printf("Linked list before insertion\n");
    linkedlistTraversal(head);

  step1:  printf("Press 1 to add a new list or 0 to end execution\n");
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
    return 0;
}

void linkedlistTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Elements :%d\n", ptr->data);
        ptr = ptr -> next;
    }
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