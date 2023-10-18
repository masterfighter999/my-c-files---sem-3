#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Elements :%d\n", ptr->data);
        ptr = ptr -> next;
    }
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
int main()
{
    int n,i;
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;
    second->data=11;
    second->next=third;
    third->data=41;
    third->next=fourth;
    fourth->data=66;
    fourth->next=NULL;

    printf("Linked list before deletion\n");
    linkedlistTraversal(head);

    printf("Press 1 to delete a list or 0 to end execution\n");
    scanf("%d",&n);

    if(n==1)
    {
        printf("Insert the index value you wish to delete(Remember index starts from 0)\n");
        scanf("%d",&i);
        head = deleteAtIndex(head,i);
        printf("Linked list after deletion\n");
        linkedlistTraversal(head);
    }
    return 0;
}   