#include<stdio.h>
#include<stdlib.h>
#define size 10
int que[size];
int front=0,rear=0;
int main()
{
void enque(int);
int deque();
int search();
int ans;
int option,item;
	do
	{
	printf("\n 1.insert\n");
	printf("\n 2.delete\n");
	printf("\n 3.search\n");
	printf("\n 4.EXIT\n");
	printf("SELECT OPTION:=\n");
	scanf("%d",&option);
	switch(option)
	{
	case 1:printf("ITEMTI TO INSERT=");
		scanf("%d",&item);
		enque(item);
		break;
	case 2: item=deque();
		printf("ITEM TO DELETE=%d\n",item);
		break;
	case 3:printf("ITEM TO SEARCH=");
	 	scanf("%d",&item);
	 	ans=search(item);
	 	if(ans!=0)
	 	printf("%d found %d \n",item,ans);
	 	else
	 	printf("%d not found\n",item);
	 	break;	
	 case 4:exit(0);
	 }}
	 while(1);
	 }
	 //function for insert item
	 		void enque(int item)
	 		{
	 		int t;
	 		t=(rear+1)%size;
	 		if(t==front)
	 		{
	 		printf("que is full");
	 		exit(1);
	 		}
	 		rear=t;
	 		que[rear]=item;
	 		}
	 //function for delete an item
	 		int deque()
	 		{
	 		if(front==rear)
	 		{
	 		printf("queqe is empty");
	 		exit(2);
	 		}
	 		front=(front+1)%size;
	 		return que[front];
	 		}
	 //function for search an item
	 		int search(int item)
	 		{
	 		int t1,t2;
	 		t1=front,t2=rear;
	                t1=(t1+1)%size;
	 		while(t1!=t2 && que[t1]!=item)
	 	        t1=(t1+1)%size;
	 	        if(front==rear){
	 	                          printf("QUEUE IS EMPTY");
	 	                          return 0;
	 	                   //exit(1);
	 	        }
	 	        if(que[t1]==item)
	 	        return t1;
	 	        else
	 	        
	 		return 0;
	 		//exit(4);
	 		}
	 	        
	 		
