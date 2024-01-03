#include<stdio.h>
typedef struct{
unsigned char x:1;
}bit;
int uset[]={1,2,3,4,5,6,7,8,9},size=9;;//golabal decularation
void main()
{
void readset(bit[],int n);
void printset(bit[]);
void unionset(bit[],bit[],bit[]);
void interset(bit[],bit[],bit[]);
void difference(bit[],bit[],bit[]);
bit a[10]={0},b[10]={0},c[10]={0};//array initization
int n;
printf("\nNumberof elements in set A:");
scanf("%d",&n);
readset(a,n);
printf("\nNumber of elements in set B:");
scanf("%d",&n);
readset(b,n);
printf("\nset A:");
printset(a);
printf("\nset B:");
printset(b);
printf("\nunion operation:");
printf("\n\t AUB=");
unionset(a,b,c);
printset(c);
printf("\nIntersection operation:\n");
printf("\n\tAnB=");
printset(c);
printf("\n Difference operation:");
printf("\n\tA-B=");
difference(a,b,c);
printset(c);
}
//TO read a set and store as bit string

void readset(bit a[],int n)
{
int i,x,k;
printf("Enter %d elements:",n);
for(i=0;i<n;i++)
	{
	scanf("%d",&x);
	for(k=0;k<size;k++)
		{
		if(uset[k]==x)
		{
			a[k].x=1;
			break;
			}
		}
}
return;
}
//To print a set from list string representation
void printset(bit a[])
{
	int k;
	printf("{ ");
	for(k=0;k<size;k++)
	{
		if(a[k].x==1)
			printf(" %d ",uset[k]);
	}
	printf(" }");printf("\n");
	return;
}
//To find union of two set using bit string
void unionset(bit a[],bit b[],bit c[])
{
	int k,x;
	for(k=0;k<size;++k)
		c[k].x=a[k].x | b[k].x;
		return;
}
//To find difference of two set using bit string 
void difference(bit a[],bit b[],bit c[])
{
 	int k;
 	for(k=0;k<size;++k)
 	{
 		if(a[k].x==1)
 			c[k].x=a[k].x^b[k].x;
 	}
 	return;
 	}		
