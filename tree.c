#include<stdio.h>
#include<stdlib.h>
struct NODE
{
	int a[4],count,leaf,disp;
	struct NODE *ptr[4];
	struct NODE *parent,*next;
};
typedef struct NODE *node;
static int gName=0;
int disp=0;
int flag=0,flg=0;
FILE *outputFile;
node getnode(int);
void sort(int [],int);
node search(node,int);
node insert(node,node,int);
void dotDump(node ,FILE* );
void preorderDotDump(node ,FILE* );
/*void main(int argc,char **argv)
{
	node root=NULL,x;
	int val,n,i;
	scanf("%d",&val);
	for(i=0;i<val;i++)
	{
		scanf("%d",&n);
		x=search(root,n);
		root=insert(root,x,n);
	}
}*/


int main()
{
		
	int choice,key,m;	
	node head,new,root=NULL,x;
	int i;
	FILE *pipe;
	head->ptr[0]=head;
	printf("Read n\n"); 
	scanf("%d",&m);
	if(m<=1)
	{
		printf("\nEnter value greater than one\n\n");
		exit(0);
	}	
	while(1)
	{
		printf("1.Insert 2.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	
					printf("Read element\n");
					scanf("%d",&key);
					x=search(head,key);
					new=insert(head,x,key);
					root=head->ptr[0];
					outputFile = fopen("b+tree.dot", "a");
					dotDump(root,outputFile);
					fclose (outputFile);
					pipe=popen("dot -Tps b+tree.dot -o b+tree.ps","w");
					pclose(pipe);	
						
					break;			
				
			case 2:		if(flg==0)
					{
					//root=head->ptr[0];
					outputFile = fopen("b+tree.dot", "a");
					dotDump(root,outputFile);
					fclose (outputFile);
					pipe=popen("dot -Tps b+tree.dot -o b+tree.ps","w");
					pclose(pipe);
					}	
					pipe=popen("evince b+tree.ps","r"); 
					pclose(pipe);
					break;
				
			default:exit(0);
		}
	}
return 0;
}

void dotDump(node root, FILE *outFile)
{
	gName++;
	fprintf (outFile, "digraph tree{\n node [shape = record];\n",gName);
	if(flg==1)
		preorderDotDump(root, outFile);
    	fprintf (outFile, "}\n");
}
FILE *outputFile;


void preorderDotDump(node root, FILE* outputFile)
{
	int i;	
	if (root != NULL) 
	{
		
			
		fprintf (outputFile, "node%d[label=\"<f0>%d",root->disp,root->a[0]);
			
			i=1;
			while(root->a[i]!='\0')
			{			
			
				fprintf (outputFile, "|<f%d>%d",
					i,root->a[i]);
				i++;			
			}
			fprintf (outputFile,"\"];\n");	
			i=0;
				
				while(root->ptr[i]!=NULL && i<4)
				{			
									
					fprintf (outputFile, "\"node%d\":f%d -> \"node%d\":f%d;\n", root->disp,0, root->ptr[i]->disp,0);
					i++;			
				}
        			
			i=0;
        		while(root->ptr[i]!=NULL && i<4)
			{			
				preorderDotDump (root->ptr[i], outputFile);
				
				i++;			
			}
			
        	
    	}
}

node getnode(int n)
{
	int i;
	node x=(node)malloc(sizeof(struct NODE));
	for(i=0;i<4;i++)
	{
		x->a[i]=0;
		x->ptr[i]=NULL;
	}
	x->count=0;
	x->leaf=n;
	x->parent=x->next=NULL;
	return x;
}
void sort(int a[],int count)
{
	int i,j,temp;
	for(i=0;i<count-1;i++)
	{
		for(j=0;j<count-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
node search(node root,int x)
{
	int i;
	if(root==NULL)
		return NULL;
	while(root->leaf==0)
	{
		for(i=0;i<root->count;i++)
		{
			if(x<root->a[i])
			{
				root=root->ptr[i];
				break;
			}
		}
		root=root->ptr[i];
	}
	return root;
}
node insert(node root,node x,int key)
{
	int i;
	node y=NULL,z=NULL;
	if(x==NULL)
	{
		x=getnode(1);
		root=x;
	}
	x->a[(x->count)++]=key;
	sort(x->a,x->count);
	if(x->count==4)
	{
		y=getnode(x->leaf);
		if(x==root)
		{
			node z=getnode(0);
			root=z;
			x->parent=y->parent=root;
			root->ptr[root->count]=x;//initially 0.assigning the parent to x.
		}
		root=insert(root,x->parent,x->a[1]);//insertion to parent
		y->parent=x->parent;
		y->parent->ptr[y->parent->count]=y;//assigning the link of parent to y
		for(i=1;i<4;i++)
		{
			y->a[i-1]=x->a[i];
			x->a[i]=0;
		}
		for(i=2;i<x->count;i++)
		{
			y->ptr[i-2]=x->ptr[i];
			x->ptr[i]=NULL;
		}
		x->count=1;
		y->count=3;
		if(x->leaf==0)//if x is an internal node
		{
			for(i=0;i<3;i++)
			{
				y->a[i]=y->a[i+1];
				if(y->ptr[i]!=NULL)
					y->ptr[i]->parent=y;
			}
			y->a[3]=0;
			(y->count)--;
			return root;
		}	
		y->next=x->next;
		x->next=y;
	}
	return root;
}	
