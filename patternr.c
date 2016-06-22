#include<stdio.h>
#include<stdlib.h>
void pattern(int ,int );
void pattern1(int ,int );
main()
{
  int n;
     printf("Enter n: ");
     scanf("%d",&n);
     pattern(n,n);
     pattern1(n-1,n);
}


void pattern(int n, int m)
{
   int i,j,k,l;
   if(n==1)
{   
     for(i=0;i<n;i++)
 {    for(j=0;j<n-i;j++)
       printf(" ");
      printf("\n");
      
}
}
else
    pattern(n-1,m);
  
     for(j=0;j<=m-n-1;j++)
     {
      printf(" ");
     }
      for(k=1;k<=n;k++)
       {  printf("%d",k);
       }
     for(l=n-1;l>0;l--)
     {   printf("%d",l);
     } printf("\n");
}

void pattern1(int n, int m)
{
   int i,j,k,l;
   if(n==1)
    {   
     
     for(j=0;j<n;j++)
      { 
        printf(" ");
      }
      for(k=1;k<=m-n;k++)
      {
       printf("%d",k);
       }
      for(l=m-n-2;l>=0;l--)
        printf("%d",l+1);
      printf("\n");
      }

else
    pattern1(n-1,m);
  
     for(j=0;j<=n;j++)
     {
      printf(" ");
     }
      for(k=1;k<m-n-1;k++)
       {  printf("%d",k);
       }
     for(l=m-n-2;l>=0;l--)
     {   printf("%d",l+1);
     } printf("\n");
}
