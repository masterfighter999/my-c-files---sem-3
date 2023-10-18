/* Name: Swayam Chatterjee
   B.Sc Sem III
   Data Structures
   Binary Search Tree - Traversals( Preorder, Inorder, Postorder)*/

#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

void insert(struct tree *root, int n);
struct tree *create(int n);
struct tree *read(struct tree *root);
void preorder(struct tree *root);
void inorder(struct tree *root);
void postorder(struct tree *root);

void main()
{
	struct tree *root;
	root = read(root);
	printf("\nThe preorder traversal is\n");
	preorder(root);
	printf("\nThe inorder traversal is \n");
	inorder(root);
	printf("\nThe postorder traversal is\n");
	postorder(root);
	printf("\n");
}
struct tree *create(int n)
{
	struct tree *root=(struct tree *)calloc(1,sizeof(struct tree));
	root->data=n;
	root->left=NULL;
	root->right=NULL;
	return root;
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

