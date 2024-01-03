//DISJOINT SET OPERATIONS

#include<stdio.h>
#include<stdlib.h>

//Structure to represent an object of a set in linked representation 

typedef struct
{
	int value;
	struct rep *repptr;           //Pointer to header node of the  
	struct node *next;
}node;

//Structure to represent header node of linked representation 

typedef struct
{
	node *head;
	node *tail;
}rep;

//Structure to store key and object node pointer.

typedef struct
{
	int key;
	node *obj_node_ptr;
	struct noaddr *next;
}noaddr;

noaddr *ndr=0;    //List to store keys and object node pointer

//Function to create a set for an object

void makeset(int a)
{
	//Create a object node pointer
	noaddr *t=(noaddr *)malloc(sizeof(noaddr));
	
	//Create a new set
	rep *newset=(rep *)malloc(sizeof(rep));
	node *n=(node *)malloc(sizeof(node));
	
	//Fill values
	n->value=a;
	n->repptr=newset;
	n->next=0;
	
	//Initialize head and tail
	newset->head=newset->tail=n;
	
	//To store object node pointer and key
	t->obj_node_ptr=n;
	t->key=a;
	t->next=ndr;
	ndr=t;
}

//Function to return pointer of the reperesentative(header node) of the containing x

rep *find(int x)
{
	noaddr *t=ndr;
	while(t->key!=x && t!=0)
		t=t->next;
	return t->obj_node_ptr->repptr;
}

//Function to find union of 2 sets corresponding to objects given

void unionset(int key1,int key2)
{
	rep *set1,*set2;
	node *t1;
	set1=find(key1);
	set2=find(key2);
	if(set1==set2)
		printf("\n %d and %d belongs to the same set.\n",key1,key2);
	else
	{
		//Changing the header pointer of objects of set_2 to that of set
		t1=set2->head;
		while(t1!=0)
		{
			t1->repptr=set1;
			t1=t1->next;
		}
		set1->tail->next=set2->head;
		set1->tail=set2->tail;   //Set the tail of set_1 to tail of set_2
	}
	free(set2);
}

//Function to display a set

void display_set(int a)
{
	rep *r;
	node *t;
	r=find(a);
	t=r->head;
	printf("\n Set members containing %d : {",a);
	while(t!=0)
	{
		printf(" %d ,",t->value);
		t=t->next;
	}
	printf("\b}");
}

void main()
{
	makeset(10);
	makeset(20);
	makeset(30);
	makeset(40);
	makeset(50);
	printf("find(10) = %x",find(10));
	printf("\n");
	printf("find(20) = %x",find(20));
	printf("\n");
	printf("find(30) = %x",find(30));
	printf("\n");
	printf("find(40) = %x",find(40));
	printf("\n");	
	printf("find(50) = %x",find(50));
	printf("\n");
	unionset(10,20);
	display_set(10);
	printf("\nAfter union of 10 & 20 find(20) = %x \n",find(20));
	unionset(30,40);
	display_set(30);
	printf("\nAfter union of 30 & 40 find(40) = %x \n",find(40));
	unionset(20,40);
	display_set(40);
	printf("\nAfter union of 20 & 40 find(40) = %x \n",find(40));
	unionset(50,30);
	display_set(30);
	printf("\nAfter union of 50 & 30 find(30) =%x \n",find(30)); 
}
	

	

