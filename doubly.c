//doubley linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left,*right;
};
struct node* insert(struct node*,int);
struct node* delete(struct node*,int);
struct node* search(struct node*,int);
//struct node* dl=(struct node*)0,*t;

int main()
{
int option,data,item;
struct node *ans;
struct node* dl=(struct node*)0;//empty dl
do
{
printf("\n1.INSERT \n");
printf("\n2.DELETE\n");
printf("\n3.SEARCH\n");
printf("\n4.EXIT\n");
printf("\n\tOPTION=");
scanf("%d",&option);
switch(option)
{
	case 1: printf("data=");
		scanf("%d",&data);
		dl=insert(dl,data);
		break;
	case 2:printf("item=");
		scanf("%d",&data);
		dl=delete(dl,data);
		break;
	case 3:printf("item=");
	       scanf("%d",&data);
	       ans=search(dl,data);
	       if(ans==(struct node*)0)
	       printf("Not found\n");
	       else
	       printf("Found\n");
	       break;
      case 4:exit(0);
      default:printf("invalid");
      }}while(1);}
//function to insert an iteM double linked list
struct node* insert(struct node* dl,int item)
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t->data=item;
	t->left=(struct node*)0;
	t->right=dl;
	if(dl!=(struct node *)0)
	dl->left=t;
	return t;
	}
//function to search an item
struct node* search(struct node* dl,int item)
{
	while(dl!=(struct node*)0 && dl->data!=item)
	dl=dl->right;
	return dl;
	}
//function to delete an item
struct node* delete(struct node* dl,int item)
{
	struct node* t=search(dl,item); 
	if(t==(struct node*)0)
	printf("not found\n");
	else 
	{
	if(t->left==(struct node*)0 && t->right==(struct node*)0)
	 	dl=(struct node*)0;
	else if(t->right==(struct node *)0) //case of last node
		t->left->right=t->right;
	
	else if (t->left==(struct node*)0)
	{
        	t->right->left=t->left;
        	dl=dl->right;
        }
	else
         {
         t->left->right=t->right;
         t->right->left=t->left;
         }
          free(t);
          printf("%d deleted",item);
        
          }
        
     	   return dl;
 }
