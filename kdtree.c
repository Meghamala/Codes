#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int ptr[2]; 
	struct Node *ll,*rl;
};
typedef struct Node *node;

node insert(node ,int []);
node insertrec(node ,int [],int );
node getnode(int []);
void inorder(node );

int main()
{
	int n,i,j,p[n][2];
	node root=NULL;
	printf("Enter n: ");
	scanf("%d",&n);
	
	//printf("Enter the points\n");
	for(i=0;i<n;i++)
	{
	for(j=0;j<2;j++)
	{
		scanf("%d",&p[i][j]);
	}
	}
	for(i=0;i<n;i++)
	{
	for(j=0;j<2;j++)
	{
		printf("%d  ",p[i][j]);
	}
	printf("\n");
	}
	//for(; ;)
	//{
	//printf("Enter choice\n 1:Insert\n 2:display\n");
	//scanf("%d",&ch);
	//switch(ch)
	//{
	//n=sizeof(p)/sizeof(p[0]);
		 for(j=0;j<n;j++)
			{
				root=insert(root,p[j]);
			} 
		 inorder(root);
	
	return 0;
}

node insert(node R, int p[])
{
	return insertrec(R,p,0);
}


node insertrec(node R,int p[],int d)
{
	node x;
	int cd;
	if(R==NULL)
	{
		x=getnode(p);
		return x;
	}
	cd=d%2;
	if(p[cd]<=R->ptr[cd])
	{
		R->ll=insertrec(R->ll,p,d+1);
	}
	else
	{
		R->rl=insertrec(R->rl,p,d+1);
	}
	return R;
}

node getnode(int a[])
{
	node y;
	int i;
	y=(node)malloc(sizeof(struct Node));
	 for(i=0;i<2;i++)
	{
		y->ptr[i]=a[i];
	}
	y->ll=y->rl=NULL;
	return y;
}
 	
void inorder(node R)
{
 	int i;
	if(R==NULL)
	{
	 return;
	}
	inorder(R->ll);
	printf("(");
	for(i=0;i<2;i++)
	{
	printf("%d  ",R->ptr[i]);
	}
	printf(")");
	inorder(R->rl);
}
