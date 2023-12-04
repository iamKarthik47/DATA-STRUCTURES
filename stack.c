//push and pop using using linked list stack
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
void main()
{
struct node *sp=(struct node *)0;//empty stack
struct node *push(struct node *,int);
struct node *pop(struct node *,int*);
int search(struct node *,int);
int option,item,ans,data;
do
{
printf("1.push\n");
printf("2.pop\n");
printf("3.search \n");
printf("4.exit\n");
printf("select option=\n");
scanf("%d",&option);
switch(option)
{
	case 1:printf("data=");
		scanf("%d",&data);
		sp=push(sp,data);
	break;
	case 2:if(sp==(struct node*)0)
		printf("EMPTY STACK\n");
		else
		{
		sp=pop(sp,&item);
		printf("poped item=%d\n",item);
	          }
	break;
	case 3:printf("data for searching=\n");
		scanf("%d",&item);
		ans=search(sp,item);
	        if(ans!=0)
		printf("found \n");
		else
		printf("not found\n");
		break;
	case 4:exit(0);
	}}
	while(1);
	}
	
//function push on item
//linked stack
	struct node*push(struct node*sp,int data)
	{
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t->data=data;
	t->next=sp;
	return t;
	}
//function to pop an element
	struct node *pop(struct node *sp,int* item)
	{
	struct node*t=sp;
	if(sp!=(struct node*)0)//empty or not
	{
	*item=sp->data;
	sp=sp->next;
	free(t);
	}
	return sp;
	}
//function to search an item
	int search(struct node *sp,int item)
	{
	while(sp!=(struct node *)0 && sp->data!=item)
		sp=sp->next;
		if(sp==(struct node*)0)
			return 0;
		else
			return 1;
	}
		
	
