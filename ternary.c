#include<stdio.h>
#include<stdlib.h>
//int ternary(int ,int ,int ,int ,int );

void main()
{
  int n,a[n],i,key,l,h,p;
  scanf("%d",&n);
  printf("Enter the array elements\n");
  for(i=0;i<n;i++)
   {
	scanf("%d",&a[i]);
   }
	l=0,h=n-1;
	printf("Enter key to search\n");
	scanf("%d",&key);
	p=ternary(n,a,key,l,h);
	if(p==-1)
	{
	printf("Unsuccessful\n");
	}
else
	printf("Successful\n");
}

int ternary(int n,int a[],int key,int l,int h)
{
  int m1=0,m2=0,p=-1;
	if(l>h)
	return -1;
	if(l<=h)
	{
		m1=(l+(h-l))/3;
		m2=2*(l+(h-l))/3;
		if(key==a[m1])
		{
			p=1;
			return p;
			
		}
	else if(key==a[m2])
		{
			p=1;
			return p;
		}
			if(key<a[m1])
			return ternary(n,a,key,l,m1-1);
		else
			if(key>a[m2])
			return ternary(n,a,key,m2+1,h);

			else 
				return ternary(n,a,key,m1+1,m2-1);
	}
}
