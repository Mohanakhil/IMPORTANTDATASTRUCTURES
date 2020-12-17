//Detect loop in a linked list using additional ELEMENT IN  Node called flag for each node in linkedlist
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	int flag;
};
void push(struct node **head,int newdata)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=newdata;
	newnode->flag=0;
	newnode->next=*head;
	*head=newnode;
}
void printList(struct node **head)
{
	struct node *pointer=*head;
	while(pointer!=NULL)
	{ printf("%d ",pointer->data);
		pointer=pointer->next;
	}
}
void findLengthOfCycle(struct node *pointer)
{ struct node *p=pointer;
int count=1;
while(p->next!=pointer)
{
	count++;
	p=p->next;
}
printf("\ncount of loop  is %d\n",count);
}
bool detectLoopUsingExtraSpace(struct node **head)
{ 
	struct node *pointer=*head;

	while(pointer!=NULL)
	{ 
	if(pointer->flag==1) 
	{	findLengthOfCycle(pointer);
		return true;
	}

	pointer->flag=1;
	pointer=pointer->next;
	}
	return false;
}
int main()
{ struct node *head=NULL;

	int ele,count,choice;
	do
	{
		printf("enter ele to insert\n");
		scanf("%d",&ele);
		push(&head,ele);
		printf("press 0 for termination\n");
		scanf("%d",&choice);
	}while(choice!=0);
	printList(&head);
	if(head->next->next->next->next!=NULL)
	{
	head->next->next->next->next=head;
	bool signal=detectLoopUsingExtraSpace(&head);
	if(signal==true ) printf("\nloop is detected\n");
	else printf("\nloop is not detected\n");
 	}
 else printf("\nloop cannot be formed with few elements\n");
	
}

