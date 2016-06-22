#include<stdio.h>
#include<stdlib.h>
struct NODE
{
	int key;
	char colour;
	struct NODE *left,*right,*parent;
};
typedef struct NODE *node;
node rbinsert(node,int,node);
node insert(node,int,node);
node left_rotate(node,node,node);
node right_rotate(node,node,node);
node getnode(int,char,node);
FILE *outputFile;
static int gName=0; 
void preorderDotDump (node, FILE*,node);
void dotDump(node, FILE *,node);
void main(int argc,char **argv)
{
	FILE *pipe;
	int item,ch,i,val;
	node nil=getnode(0,'b',nil);
	nil->left=NULL;
	nil->right=NULL;
	nil->parent=NULL;
	node root=NULL;
	if(argc != 2)
	{
		printf("Need one argument");
		exit(0);
	}
	outputFile = fopen ("rbt.dot", "w");
    	fclose (outputFile);
	val = atoi(argv[1]);
	outputFile =fopen("rbt.dot","a");
	for(i=0;i<val;i++)
	{
			item=random()%1000;
			printf("%d\t",item);
			root=rbinsert(root,item,nil);
	} 
	if(outputFile!=NULL)
	{
		dotDump(root,outputFile,nil);
	}
	fclose(outputFile);
	pipe=popen("dot -Tps rbt.dot -o rbt.ps","w");
	pclose(pipe);	
	pipe=popen("evince rbt.ps","r"); 
	pclose(pipe);
	
}
void preorderDotDump (node root, FILE* outputFile,node nil)
{
	if (root !=nil) 
	{
		if(root->colour=='b')
			fprintf (outputFile, "%d [label=%d,color=black];\n",root->key, root->key);
		else if(root->colour=='r')
			fprintf (outputFile, "%d [label=%d,color=red];\n",root->key, root->key);
		if (root->left !=nil) 
		         fprintf (outputFile, "%d -> %d ;\n", root->key, (root->left)->key);
		
        	if (root->right !=nil)
            		fprintf (outputFile, "%d -> %d;\n", root->key, root->right->key);
	//	if (root->pptr != NULL)
         //   		fprintf (outputFile, "%d -> %d [style = dashed];\n", root->key, (root->pptr)->key);
        	preorderDotDump (root->right, outputFile,nil);
        	preorderDotDump (root->left, outputFile,nil);
    	}
}

void dotDump(node root, FILE *outFile,node nil)
{
	gName++;
	fprintf (outFile, "digraph BST {\n",gName);
	
	preorderDotDump (root, outFile,nil);
    	fprintf (outFile, "}\n");
}

node insert(node root,int item,node nil)
{
	node x=getnode(item,'r',nil);
	node par,cur;
	if(root==NULL)
		return x;
	par=cur=root;
	while(cur!=nil)
	{
		par=cur;
		if(cur->key>item)
			cur=cur->left;
		else
			cur=cur->right;
	}
	if(par->key>item)
	{
		par->left=x;
		x->parent=par;
	}
	else
	{
		par->right=x;
		x->parent=par;
	}
	return x;//to return the item and not root** very important
}
node rbinsert(node root,int key,node nil)
{
	node x=insert(root,key,nil);
	node y;
	if(root==NULL)
		root=x;
	while(x!=root&&x->parent->colour=='r')
	{
		if(x->parent==x->parent->parent->left)
		{
			y=x->parent->parent->right;
			if(y->colour=='r')
			{
				x->parent->colour='b';//unsure
				y->colour='b';//unsure
				x->parent->parent->colour='r';
				x=x->parent->parent;
			}
			else 
			{
				//y is black
				if(x==x->parent->right)
				{
					x=x->parent;
					root=right_rotate(root,x,nil);
				}
				x->parent->colour='b';
				x->parent->parent->colour='r';
				root=left_rotate(root,x->parent->parent,nil);
			}
		}
		else
		{
			y=x->parent->parent->left;
			if(y->colour=='r')
			{
				x->parent->colour='b';//unsure
				y->colour='b';//unsure
				x->parent->parent->colour='r';
				x=x->parent->parent;
			}
			else 
			{
				if(x==x->parent->left)
				{
					x=x->parent;
					root=right_rotate(root,x,nil);
				}
				x->parent->colour='b';
				x->parent->parent->colour='r';
				root=left_rotate(root,x->parent->parent,nil);
			}
		
		}
	}
	root->colour='b';
	return root;
}
node left_rotate(node root,node x,node nil)
{
	node y=x->right;
	x->right=y->left;
	if(y->left!=nil)
		y->left->parent=x;
	y->parent=x->parent;
	if(x->parent==nil)
		root=y;
	else if(x==x->parent->left)
		x->parent->left=y;
	else
		x->parent->right=y;
	y->left=x;
	x->parent=y;
	return root;
}
node right_rotate(node root,node x,node nil)
{
	node y=x->left;
	x->left=y->right;
	if(y->right!=nil)
		y->right->parent=x;
	y->parent=x->parent;
	if(x->parent==nil)
		root=y;
	else if(x==x->parent->right)
		x->parent->right=y;
	else
		x->parent->left=y;
	y->right=x;
	x->parent=y;
	return root;
}	
node getnode(int key,char colour,node nil)
{
	node n=(node)malloc(sizeof(struct NODE));
	if(n==NULL)
	{
		printf("not enough memory\n");
		exit(0);
	}	
	n->key=key;
	n->colour=colour;
	n->left=n->right=nil;
	n->parent=nil;
	return n;
}		
