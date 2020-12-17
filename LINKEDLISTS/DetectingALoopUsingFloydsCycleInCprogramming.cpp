//Detect loop in a linked list using floyds cycle algo AND COUNTING LENGTH OF LOOP
//ASSUMING MORE  4 ELEMENTS IN LOOP AND TOTAL ONLY  5 ELE 
	
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void push(struct node **head,int newdata)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=newdata;
	newnode->next=*head;
	*head=newnode;
}
void printList(struct node **head)
{
	struct node *pointer=*head;
	while(pointer!=NULL)
	{
		printf("%d ",pointer->data);
		pointer=pointer->next;
	}
}
void lengthOfCycle(struct node *slow)
{ int len=1;
	struct node *pointer=slow;
	while(pointer->next!=slow)
	{
		pointer=pointer->next;
		len++;
	}
	printf("\nlength of cycle is %d\n",len);
}
void loopDetection(struct node **head)
{ bool flag=false;
	struct node *slow=*head;
	struct node *fast=*head;
	while(fast&&slow&&fast->next&&slow->next)
	{ 	printf("slow= %d and fast= %d\n",slow->data,fast->data);
		slow=slow->next;
		fast=fast->next->next;
		if(slow->data==fast->data)
		{ flag=true;
			printf("\nloop is detected\n");
			lengthOfCycle(slow);
			break;
		}
	}
	if(flag==false)
	printf("no loop detected\n");

	
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
//CREATE A LOOP FOR TESTING
head->next->next->next->next->next=head->next;
loopDetection(&head);	
}
