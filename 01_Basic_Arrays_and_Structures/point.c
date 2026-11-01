/*
 * Question:
 * Write a C program using a structure to find the distance between two points.
 */

#include<stdio.h>
#include<math.h>
struct POINT
{
	float xco,yco;
};
int main()
{
	struct POINT a,b;
	printf("enter coordinates of 1rst point\n");
	scanf("%f %f",&a.xco,&a.yco);
	printf("enter coordinates of 2nd point\n");
	scanf("%f %f",&b.xco,&b.yco);
	float dist= sqrt(((b.xco-a.xco)*(b.xco-a.xco))+((b.yco-a.yco)*(b.yco-a.yco)));
	printf("distance is:%f\n",dist);
	return 0;
}
