#include<stdio.h>
#include<stdlib.h>
main()
{
    int n,i,j,k,l;
	printf("Enter n: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
 	{
	 for(j=0;j<n-i;j++)
	{
	    printf(" ");
        }
	for(k=0;k<=i;k++)
	{ 
  	printf("%d",k+1);
	}
	for(l=i-1;l>=0;l--)
	{
	printf("%d",l+1);
	}
	printf("\n");
	}

       for(i=1;i<=n-1;i++)
	{
	for(j=0;j<=i;j++)
	{
	 printf(" ");
	}
	for(k=0;k<n-i;k++)
	{
	printf("%d",k+1);
	}
	for(l=n-i-2;l>=0;l--)
	{
	printf("%d",l+1);
	}
        printf("\n");
	}

}
