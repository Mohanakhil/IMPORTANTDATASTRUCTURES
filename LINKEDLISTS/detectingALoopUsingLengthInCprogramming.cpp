//Detect loop in a linked list using LENGTH BETWEEN FIRST AND SECOND NODE CONCEPT AND COUNTING LENGTH OF LOOP
//ASSUMING MORE  3 ELEMENTS IN LOOP AND TOTAL ONLY  4 ELE 
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void push(struct node **head,int newdata)
{ struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=newdata;
newnode->next=*head;
*head=newnode;
}
void printList(struct node **head)
{
	struct node *pointer=*head;
	printf("list is \n");
	while(pointer!=NULL)
	{
		printf("%d ",pointer->data);
		pointer=pointer->next;
	}
	
}
int findGap(struct node *first,struct node *second)
{ int count=0;
	while(first!=second)
	{
		count++;
		first=first->next;
	}
	return count;
}
int findLengthOfLoop(struct node *second)
{ int len=1;
	struct node *pointer=second;
	while(pointer->next!=second)
	{
		len++;
		pointer=pointer->next;
	}
	printf("length of loop is %d\n",len);
}
void detectLoopUsingLength(struct node **head)
{ int prevgap=0,currentgap=0;
bool flag=false;
		struct node *first=*head;
		struct node *second=*head;
		while(second->next!=NULL)
		{ 
		currentgap=findGap(first,second);
	
		if(currentgap<prevgap)
		{ flag=true;
			printf("\nthere is a loop detected\n");
			findLengthOfLoop(second);
			break;
		 } 
		second=second->next;
		prevgap=currentgap;
		}
		if(flag==false)
		printf("no  loop is detected\n");
}
int main()
{ struct node *head=NULL;
	int ele,choice;
	do
	{
		printf("enter ele to insert\n");
		scanf("%d",&ele);
		push(&head,ele);
		printf("press 0 for termination\n");
		scanf("%d",&choice);
	}while(choice!=0);
	printList(&head);
	head->next->next->next->next=head->next;
	detectLoopUsingLength(&head);
}
