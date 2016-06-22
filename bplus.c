
//B+ TREE INSERTION 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
struct Node
{
	struct node *ptr[100],*pptr,*next;
	int key[100],disp,c;
};
typedef struct node *node;

static int gName=0;
int disp =0;
NODE insert(NODE head, int info,int n);
NODE insertfix(NODE t,int info,int m);
NODE insertparent(NODE t,int key,NODE n1,int m);
int flag=0,flg=0;

node getnode(int n)
{
	node x;
	int i;
	x=(node)malloc(sizeof(struct Node));
	if(x==NULL)
	{
	  printf("not enough memory\n");
	  return;
	}
	for(i=0;i<n;i++)
	{
		x->key[i]=0;
		x->ptr[i]=NULL;
	}
	x->pptr=NULL;
	x->next=NULL;
	x->c=0;
	return x;
}



void sort(int b[],int c)
{
	int i,j,temp;
	for(i=0;i<c-1;i++)
	{
		for(j=0;j<c-i-1;j++)
			{
				if(b[j]>b[j+1])
				{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
				}
			}
	}
}
					

node insert(node root, int k,int n)
{

}
	


void preorderDotDump (NODE root, FILE* outputFile)
{
	int i;	
	if (root != NULL) 
	{
		
			
		fprintf (outputFile, "node%d[label=\"<f0>%d",root->disp,root->key[0]);
			
			i=1;
			while(root->key[i]!='\0')
			{			
			
				fprintf (outputFile, "|<f%d>%d",\
					i,root->key[i]);
				i++;			
			}
			fprintf (outputFile,"\"];\n");	
			i=0;
				
				while(root->ptr[i]!=NULL)
				{			
									
					fprintf (outputFile, "\"node%d\":f%d -> \"node%d\":f%d;\n", root->disp,0, root->ptr[i]->disp,0);
					i++;			
				}
        			
			i=0;
        		while(root->ptr[i]!=NULL)
			{			
				preorderDotDump (root->ptr[i], outputFile);
				
				i++;			
			}
			
        	
    	}
}

void dotDump(NODE root, FILE *outFile)
{
	gName++;
	fprintf (outFile, "digraph tree{\n node [shape = record];\n",gName);
	if(flg==1)
		preorderDotDump (root, outFile);
    	fprintf (outFile, "}\n");
}
FILE *outputFile;


int main()
{
		
	int choice,key,m;	
	node new,head,root=NULL,p;
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
					
					
					new=insert(head,key,m);
					root=head->ptr[0];
					outputFile = fopen("b+tree.dot", "a");
					dotDump (root,outputFile);
					fclose (outputFile);
					pipe=popen("dot -Tps b+tree.dot -o b+tree.ps","w");
					pclose(pipe);	
						
					break;			
				
			case 2:		if(flg==0)
					{
					root=head->ptr[0];
					outputFile = fopen("b+tree.dot", "a");
					dotDump (root,outputFile);
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
