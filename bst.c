/* Name: Swayam Chatterjee
   B.Sc Sem III
   Data Structures
   Binary Search Tree - Creation, Insertion and Deletion */
#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

void edit(struct tree *root);
void insert(struct tree *root, int n);
struct tree *create(int n);
struct tree *read(struct tree *root);
void preorder(struct tree *root);
void inorder(struct tree *root);
void postorder(struct tree *root);
struct tree *inOsu(struct tree *root);
struct tree *delete(struct tree *root, int n);

void main()
{
	struct tree *root;
	root = read(root);
	edit(root);
}
struct tree *create(int n)
{
	struct tree *root=(struct tree *)calloc(1,sizeof(struct tree));
	root->data=n;
	root->left=NULL;
	root->right=NULL;
	return root;
}
void edit(struct tree *root)
{
	int ch, n;
	do{
		printf("\nEnter 1 to insert, 2 to delete and 3 to display and 0 to halt\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the number to inserted\n");
				scanf("%d",&n);
				insert(root, n);
				break;
			case 2: printf("Enter the number to be deleted\n");
				scanf("%d", &n);
				delete(root, n);
				break;
			case 3: printf("\nThe preorder traversal is\n");
				preorder(root);
				printf("\nThe inorder traversal is \n");
				inorder(root);
				printf("\nThe postorder traversal is\n");
				postorder(root);
				printf("\n");
		}
	}while(ch!=0);
	printf("\n--EXIT--\n");
}
struct tree *read(struct tree *root)
{
	int d,n;
	printf("Enter the root data\n");
	scanf("%d",&n);
	root=create(n);
	printf("Enter 1 to input new numbers\n");
	scanf("%d",&d);
	while(d==1)
	{
		printf("Enter data to insert in the tree	\n");
		scanf("%d",&n);
		insert(root, n);
		printf("Enter 1 to input new numbers\n");
		scanf("%d",&d);
	}
	return root;
}
void insert(struct tree *root, int n)
{
	struct tree *p;
	while(root!=NULL)
	{
		p=root;
		if(n>=root->data)
			root=root->right;
		else
			root=root->left;
	}
	struct tree *ptr=create(n);
	if(n<p->data)
		p->left=ptr;
	else
		p->right=ptr;
}
struct tree *inOsu(struct tree *root)
{
	root=root->right;
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}
struct tree *delete(struct tree *root, int n)
{
	struct tree *isu;
	if(root==NULL)
		return NULL;
	
	if(n < root->data)
		root->left=delete(root->left, n);
	else if(n > root->data)
		root->right=delete(root->right, n);
	else
	{
		if(root->left==NULL)
		{
			struct tree *t=root;
			root=root->right;
			free(t);
		}
		else if(root->right==NULL)
		{
			struct tree *t=root;
			root=root->left;
			free(t);
		}
		else if(root->left==NULL && root->right==NULL)
		{
			free(root);
			root= NULL;
		}
		else
		{
			isu=inOsu(root);
			root->data=isu->data;
			root->right=delete(root->right, isu->data);
		}
	}
	return root;
}
void preorder(struct tree *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct tree *root)
{
	if (root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void postorder(struct tree *root)
{
	if (root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

