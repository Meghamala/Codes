#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	int key;
	struct NODE *left;
	struct NODE *right;
}node;
int val,in[20],post[20],ind;
static int gName=0;
FILE *outputFile;
node *gentree(int [],int ,int []);
int findkey(int,int [],int);
node *getnode(int);
void copy(int [],int [],int,int,int,int,int [],int[]);
void inorder(node *);
void postorder(node *);
node *insert(int,node *);
void preorderDotDump (node *, FILE*);
void dotDump(node *, FILE *);
void main(int argc, char** argv)
{
	int n,i,item;
	FILE *pipe;
		
	node *root1,*root;
	root1=NULL;
	root=NULL;

	if (argc != 2)
	{
		//printf(" need one argument  \n");
		//exit(0);
	}
	outputFile = fopen ("bst.dot", "w");
    	fclose (outputFile);
	val = atoi(argv[1]);
	outputFile =fopen("bst.dot","a");
	for(i=0;i<val;i++)
	{
		item=random()%1000;
		root1=insert(item,root1); 
						
	}						
	if(outputFile!=NULL)
	{
		dotDump(root1,outputFile);
	}
	fclose(outputFile);
	pipe=popen("dot -Tps bst.dot -o bst.ps","w");
	pclose(pipe);	
	pipe=popen("evince bst.ps","r"); 
	pclose(pipe);
	ind=0;
	inorder(root1);
	ind=0;
	postorder(root1);
				
	root=gentree(in,val,post);
	outputFile = fopen ("bst1.dot", "w");
    	fclose (outputFile);
	outputFile =fopen("bst1.dot","a");
	if(outputFile!=NULL)
	{
		dotDump(root,outputFile);
	}
	fclose(outputFile);
	pipe=popen("dot -Tps bst1.dot -o bst1.ps","w");
	pclose(pipe);	
	pipe=popen("evince bst1.ps","r"); 
	pclose(pipe);
}
node *insert(int item,node *root)
{
	node *temp,*cur,*prev;

	temp=getnode(item);

	if(root==NULL)
		return temp;

	prev=NULL;
	cur=root;		

	while(cur!=NULL)
	{
		prev=cur;
		//No duplicate elements allowed
		if(item==cur->key)
		{
			val++;				
			return root;
					
		}

		if(item < cur->key)
			cur=cur->left;

		else
			cur=cur->right;

	}

	if(item < prev->key)
		prev->left=temp;
		
	
	else
		prev->right=temp;	
	return root;
}
void preorderDotDump (node *root, FILE* outputFile)
{
	if (root != NULL) 
	{
		fprintf (outputFile, "%d [label=%d,color=black];\n",root->key, root->key);
		if (root->left != NULL) 
		         fprintf (outputFile, "%d -> %d ;\n", root->key, (root->left)->key);
		
        	if (root->right != NULL)
            		fprintf (outputFile, "%d -> %d;\n", root->key, root->right->key);
	//	if (root->pptr != NULL)
         //   		fprintf (outputFile, "%d -> %d [style = dashed];\n", root->info, (root->pptr)->info);
        	preorderDotDump (root->right, outputFile);
        	preorderDotDump (root->left, outputFile);
    	}
}

void dotDump(node *root, FILE *outFile)
{
	gName++;
	fprintf (outFile, "digraph BST {\n",gName);
	
	preorderDotDump (root, outFile);
    	fprintf (outFile, "}\n");
}

node *gentree(int in[],int n,int post[])
{
	int a[20],b[20],c[20],d[20];
	int key=post[n-1];
	node *link=getnode(key);
	if(n==0)
		return NULL;
	if(n==1)
		return link;
	int part=findkey(key,in,n);
	copy(a,in,0,part,0,part,b,post);
	copy(c,in,part+1,n,part,n-1,d,post);
	link->left=gentree(a,part,b);
	link->right=gentree(c,n-part-1,d);
	return link;
}
int findkey(int key,int in[],int n)
{
	int i;
	for(i=0;i<n;i++)
		if(key==in[i])
			return i;
	printf("Tree cannot be formed\n");
	exit(0);
} 
node *getnode(int key)
{
	node *n;
	n=(node *)malloc(sizeof(node));
	n->key=key;
	n->left=NULL;
	n->right=NULL;
	return n;
}
void copy(int a[],int in[],int sti,int endi,int stp,int endp,int b[],int post[])				
{
	int i,j=0;
	
	for(i=sti;i<endi;i++)
		a[j++]=in[i];
	j=0;
	for(i=stp;i<endp;i++)
		b[j++]=post[i];
}	
void inorder(node *root)	
{
	if(root==NULL)
		return;
	inorder(root->left);
		in[ind++]=root->key;
	inorder(root->right);
}
void postorder(node *root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	post[ind++]=root->key;
} 		
