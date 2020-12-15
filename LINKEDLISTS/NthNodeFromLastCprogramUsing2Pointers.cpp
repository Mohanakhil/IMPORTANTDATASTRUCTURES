//Program for n’th node from the end of a Linked List using 2 pointers
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
	struct node *temp=*head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void usingTwoPointers(struct node **head,int index)
{
	struct node *first=*head,*second=*head;
	while(index>1&&second->next!=NULL)
	{ second=second->next;
		index--;
	}
	printf("%d %d \n",first->data,second->data);
	while(second->next!=NULL)
	{ 
		first=first->next;
		second=second->next;
	}
	printf("\n ele at req index from last is %d\n",first->data);
	
}

int main()
{ int ele,choice,index;
struct node *head=NULL;
do
{
	printf("enter ele to insert\n");
	scanf("%d",&ele);
	push(&head,ele);
	printf("press 0 for termination\n");
	scanf("%d",&choice);
}while(choice!=0);
printList(&head);
do
{
	printf("enter index of nth node from the end of a Linked List\n ");
	scanf("%d",&index);
	usingTwoPointers(&head,index);
	printList(&head);
	printf("press 0 for termination\n");
	scanf("%d",&choice);
}while(choice!=0);

}

