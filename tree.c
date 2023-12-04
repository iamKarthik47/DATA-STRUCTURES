#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *lchild,*rchild;
};
void main()
{
struct node *insert(struct node*,int);
struct node *delete(struct node*,int);
int search(struct node*,int);
void inorder(struct node*);
int option,data,ans,item;
struct node* root=((struct node *)0);
do
{
printf("\n1.INSERT:");
printf("\n2.DELETE:");
printf("\n3.SEARCH:");
printf("\n4.TRAVERSE:");
printf("\n5.EXIT");
printf("\n\tOption : ");
scanf("%d",&option);
switch(option)
{
	case 1:printf("\n\tDATA : ");
	       scanf("%d",&data);
	       root=insert(root,data);
	       break;
	case 2:printf("\n\tDATA : ");
	       scanf("%d",&data);
	       root=delete(root,data);
	       break;
	case 3:printf("\n\tITEM TO SEARCH : ");
	       scanf("%d",&data);
	       ans=search(root,data);
	       if(ans!=0)
	       printf("FOUND\n");
	       else
	       printf("NOT FOUND\n");
	       break;
	case 4:inorder(root);
	break;
	case 5:exit(0);
	break;
	default:printf("invalid");
	}}
	while(1);
}
//function to insert an item'
struct node *insert(struct node* root,int data)
	{
	struct node *par=(struct node*)0,*t,*troot=root;
	while(root!=(struct node*)0 && data!=root->data)
{
	par=root;
	if(data<root->data)
	{
		root=root->lchild;
		}
	else
	{
	root=root->rchild;
	}}
	if(root!=(struct node*)0)
	printf("dublicate\n");
	else
	{
	     t=(struct node*)malloc(sizeof(struct node));
	     t->data=data;
	     t->lchild=t->rchild=(struct node*)0;
	     if(par==(struct node*)0)
	     troot=t;
	     else if(data<par->data)
	     par->lchild=t;
	     else
	     par->rchild=t;
	     }
	     return troot;
	     }
//function to delete an item
struct node *delete(struct node *root,int data)
{
struct node *par=(struct node*)0,*t=root,*sucpar,*suc;
while(root!=(struct node*)0 && root->data!=data)
  	{
  		par=root;
  		if(data<root->data)
  			root=root->lchild;
  		else
  			root=root->rchild;
  	}
                if(root==(struct node*)0)
                	printf("NOT found\n");
                else{
                
                	if(root->lchild==(struct node*)0 && root->rchild==(struct node*)0)   // 0 child
                	{
                		if(par==(struct node*)0) //zero child - root removal
                			t=(struct node*)0;
                		else if(data<par->data)
                			par->lchild=(struct node*)0;
                		else
                			par->rchild=(struct node*)0;
                	}
                	else if(root->lchild==(struct node*)0 || root->rchild==(struct node*)0) // one child
                        { 
                        	if(par==(struct node*)0) //one child -  root removal
                        		t=root->lchild==(struct node*)0 ? root->rchild:root->lchild;
                        	else if(data<par->data)
                        		par->lchild=(root->lchild==(struct node*)0 ? root->rchild:root->lchild);
                        	else
                        		par->rchild=(root->lchild==(struct node*)0 ? root->rchild:root->lchild);
                        }
                        else //case 2 child
                        {
                        	suc=root->rchild;
                        	sucpar=root;
                        	while(suc->lchild!=(struct node*)0)
                        	{
                        		sucpar=suc;
                        		sucpar=suc->lchild;
                          	}	
                          
                         	root->data=suc->data; //copy successor item to node to be deleted
                          
                          	//Removal of inorder successor
                          	
                        	if(suc->data<sucpar->data)
                        		sucpar->lchild=suc->rchild;
                        	else
                        		sucpar->rchild=suc->rchild;
                        	root=suc;
                        }
                        free(root);
                        printf("\n\t%d Deleted....",data);
                }   

		return t;
 }
 //funvtion to search an item in BST
   int search(struct node *root,int data)
   {
   	while(root!=(struct node*)0 && root->data!=data)
	{	
		if(data<root->data)
		root=root->lchild;
		else
		root=root->rchild;
		}
		if(root==(struct node*)0)
		return 0;
		else
		return 1;
	}
//function to traverse an item
void inorder(struct node *root)
	{
	if(root!=(struct node*)0)
		{
		inorder(root->lchild);
		printf("%d\t",root->data);
		inorder(root->rchild);
		}
		}	
	
		                   
