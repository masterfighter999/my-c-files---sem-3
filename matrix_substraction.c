#include<stdio.h>
#include<stdlib.h>

int ** Mem_Alc(int r,int c);
void Read(int **arr,int r,int c);
void Display(int **arr,int r,int c);
void Sub(int **arr1,int **arr2,int **arr3,int r,int c);

void main()
{
   	int **arr1,**arr2,**arr3,r,c,i,j;  
   	printf("Enter the number of rows followed by the number of columns:\n");
   	scanf("%d%d",&r,&c);
   	
   	arr1=Mem_Alc(r,c);
   	arr2=Mem_Alc(r,c);
   	arr3=Mem_Alc(r,c);
   	
   	printf("\nEnter the elements of the first matrix:\n");
   	Read(arr1,r,c);
   	
   	printf("\nEnter the elements of the second matrix:\n");
   	Read(arr2,r,c);
   	
   	printf("\nThe elements of the first matrix are as follows:\n");
   	Display(arr1,r,c);
   	
   	printf("\nThe elements of the second matrix are as follows:\n");
   	Display(arr2,r,c);
   	
   	Sub(arr1,arr2,arr3,r,c);
   	
   	printf("\nThe result of substracton of the two matrices is as follows:\n");
   	Display(arr3,r,c);
}

int ** Mem_Alc(int r,int c)
{
	int **arr,i;
	
	arr=(int **)calloc(r,sizeof(int *));
	for(i=0;i<r;i++)
   	{
      		arr[i]=(int *)calloc(c,sizeof(int));
   	}
   	return arr;
}

void Read(int **arr,int r,int c)
{
   	int i,j;
   	
   	for(i=0;i<r;i++)
   	{
      		for(j=0;j<c;j++)
      		{
         		scanf("%d",&arr[i][j]);
      		}
   	}
}

void Display(int **arr,int r,int c)
{
   	int i,j;
   	
   	for(i=0;i<r;i++)
   	{
      		for(j=0;j<c;j++)
      		{
         		printf("%d\t",arr[i][j]);
      		}
      		printf("\n");
   	}
}

void Sub(int **arr1,int **arr2,int **arr3,int r,int c)
{
   	int i,j;
   	
   	for(i=0;i<r;i++)
   	{
      		for(j=0;j<c;j++)
      		{
         		arr3[i][j]=arr1[i][j]-arr2[i][j];
      		}
   	}
}