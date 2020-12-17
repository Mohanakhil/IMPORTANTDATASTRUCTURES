//Detect loop in a linked list using address of next node address
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void push(struct node **head,int newdata)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
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
void findLengthOfCycle(struct node *pointer)
{ int count=1;
	struct node *p=pointer;
	while(p->next!=pointer)
	{ count++;
		p=p->next;
	}
	printf("\nlength of loop is %d\n",count);
}
bool detectingLoopUsingTempNode(struct node **head)
{

	struct node *pointer=*head;
	struct node *prev=pointer;
	while(prev->next->next->next!=NULL)
	{ 
	pointer=prev->next;
	while(pointer->next!=NULL)
	{ 
	if(pointer->next==prev) 
	{	
	findLengthOfCycle(pointer);
	return true;
	}
	pointer=pointer->next;
	}
	prev=prev->next;
	}
return false;
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
	if(head->next->next->next->next!=NULL)
{
		head->next->next->next->next=head;
		bool loop= detectingLoopUsingTempNode(&head);
	if(loop==true) printf("there is a loop\n");
	else printf("no loop is detected\n");
}
	else printf("\n cannnot forn a loop with this few elements\n");
}
