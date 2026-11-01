/*
 * Question:
 * Write a C program using a structure to store details of five students and display the student with the highest CGPA.
 */

#include<stdio.h>
struct STUDENT
{
	int roll;
	char nm[21];
	char br[7];
	float cgpa;
};
int main()
{
	struct STUDENT s[5];
	int i;
	for(i=0;i<5;i++)
	{
		printf("enter name,branch,roll no and cgpa\n");
		scanf("%s",s[i].nm);
		scanf("%s",s[i].br);
		scanf("%d %f",&s[i].roll,&s[i].cgpa);
	}
	float max=s[0].cgpa;
	     int c=0;
	for(i=1;i<5;i++)
	{
		if(s[i].cgpa>max)
		{
			max=s[i].cgpa;
			c=i;
		}
	}
	printf("details of the student with highest cgpa are:\n");
	printf("%s\n %s\n %d\n %f\n",s[c].nm,s[c].br,s[c].roll,s[c].cgpa);
	return 0;
}

		
