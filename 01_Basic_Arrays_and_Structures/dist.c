/*
 * Question:
 * Write a C program using a structure to add two distances expressed in kilometres and metres.
 */

#include<stdio.h>
typedef struct distance
{
	int km,m;
}dist;
dist adddistance(dist a, dist b);
int main()
{
	dist a,b;
	printf("enter a\n");
	scanf("%d %d",&a.km,&a.m);
	printf("enter b\n");
	scanf("%d %d",&b.km,&b.m);
	dist res= adddistance(a,b);
	printf("result is: %d km %dm\n",res.km,res.m);
	return 0;
}
dist adddistance(dist a, dist b)
{
	dist sum;
	sum.m=a.m+b.m;
	sum.km=a.km+b.km;
	if(sum.m>=1000)
	{
		sum.m-=1000;
		sum.km++;
	}
	return sum;
}
