#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define NUM_POINTS 12
#define NUM_COMMANDS 3
//int find_mindis(float ,float ,float );

int k=3;
int main(int argc, char** argv)
{	
	int  i=0,j,a1,x2,b1,y2,a2,b2,a3,b3,c,c1[50],c2[50],c3[50],c4[50],c5[50],c6[50],ct1,ct2,ct3,pos;
	int sum[10],av1,av2,av3,av4,av5,av6;        
	float  r1,r2,r3;
    char * commandsForGnuplot[] = {"set title \"Nearest destination\"","set palette model RGB defined (0 \"red\",1 \"blue\",2 \"green\")", "plot 'data.temp' using 1:2:3 notitle with points pt 2 palette"};
    double xvals[NUM_POINTS] ;
    double yvals[NUM_POINTS] ;
	printf( "Enter centroid Positions (a1,b1),(a2,b2),(a3,b3): \n" );
        scanf( "%d" ,&a1);
        scanf( "%d" ,&b1);
	scanf( "%d" ,&a2);
	scanf( "%d" ,&b2);
	scanf( "%d" ,&a3);
	scanf( "%d" ,&b3);
	xvals[0]=a1;
	yvals[0]=b1;
	xvals[1]=a2;
	xvals[1]=b2;
	xvals[1]=a3;
	xvals[1]=b3;
      for (c = 1; c <= 100; c++) 
     {	printf("jfh");
    		x2 = rand()%100 ;
		y2 = rand()%100 ;
		xvals[c]=x2;
		yvals[c]=y2;
    		printf("(%d,%d)\n", x2 ,y2);
		r1 = sqrt((float)pow((y2-b1),2) +(float)pow((x2-a1),2));
		r2 = sqrt((float)pow((y2-b2),2) +(float)pow((x2-a2),2));
		r3 = sqrt((float)pow((y2-b3),2) +(float)pow((x2-a3),2));
                printf( "Distance= %f\t%f\t%f\t\n\n" ,r1,r2,r3);
		//pos = find_mindis(r1,r2,r3);
		if(r1<=r2 && r1<=r3)
		pos=1;
		else if(r2<=r1 && r2<=r3)
		pos=2;
		else if(r3<=r1 && r3<=r2)
		{pos=3;}
		printf("%d\n",pos);
		switch(pos)
			{
				case 1:c1[i++]=x2;
					c2[i++]=y2;ct1++;
					
					break;
				case 2:c3[i++]=x2;
					c4[i++]=y2;ct2++;
					break;
				case 3: c5[i++]=x2;
					c6[i++]=y2;ct3++;
					break;
			}
		printf("%d\n",ct1);
		if(ct1!=0)
		{for(i=0;i<ct1;i++)
		{
				sum[0]+=c1[i];
				sum[1]+=c2[i];
			printf("\n");
		} av1=(sum[0]/ct1);
		  av2=(sum[1]/ct1);
		printf("Updated centroid (%d,%d)\n",av1,av2);}
		else printf("0\n");
		if(ct2!=0)		
		{for(i=0;i<ct2;i++)
		{
				sum[2]+=c3[i];
				sum[3]+=c4[i];
			printf("\n");
		}av3=(sum[2]/ct2);
		  av4=(sum[3]/ct2);
		printf("Updated centroid (%d,%d)\n",av3,av4);}
		else printf("0\n");
		if(ct3!=0)		
		{for(i=0;i<ct3;i++)
		{
				sum[4]+=c5[i];
				sum[5]+=c6[i];
			printf("\n");
		}av5=(sum[4]/ct3);
		  av6=(sum[5]/ct3);
		printf("Updated centroid (%d,%d)\n",av5,av6);}
		else printf("0\n");	
     }
return 0;
	
/*int find_mindis(float d1,float d2,float d3)
{
	if(d1<=d2 && d1<=d3)
	{pos=1;
	return pos;}
	if(d2<=d1 && d2<=d3)
	{pos=2;
	return pos;}
	if(d3<=d1 && d3<=d2)
	pos=3;
	return pos;
}*/
}
       //printf("The nearest coordinate is: (%d,%d) at a distance of %f\n\n",xleast,yleast,least);
    FILE * temp1 = fopen("data1.temp", "w");
	FILE * temp2 = fopen("data2.temp", "w");
	FILE * temp3 = fopen("data3.temp", "w");
    Opens an interface that one can use to send commands as if they were typing into the
     *     gnuplot command line.  "The -persistent" keeps the plot open even after your
     *     C program terminates.
     
    FILE * gnuplotPipe = fopen ("gnuplot -persistent", "w");
    int i;
    for (i=0; i < ct1; i++)
    {
    fprintf(temp1, " %d\t%d\n", c1[i],c2[i]); //Write the data to a temporary file
    }
 for (i=0; i < ct2; i++)
    {
    fprintf(temp2, " %d\t%d\n", c3[i],c4[i]); //Write the data to a temporary file
    }
 for (i=0; i < ct3; i++)
    {
    fprintf(temp3, " %d\t%d\n", c5[i],c6[i]); //Write the data to a temporary file
    }
    for (i=0; i < NUM_COMMANDS; i++)
    {
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    }
    return 0;
}
