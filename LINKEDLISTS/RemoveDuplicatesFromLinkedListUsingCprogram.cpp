//Remove duplicates from a sorted linked list
/*
Write a function which takes a list sorted in non-decreasing order and deletes any duplicate nodes from the list. The list should only be traversed once. 
*/
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
{ 	printf("\n list is\n ");
	struct node *pointer=*head;
	while(pointer!=NULL)
	{
		printf("%d ",pointer->data);
		pointer=pointer->next;
	}
}
void removeDuplicates(struct node **head)
{ struct node *pointer=*head,*current;
while(pointer->next!=NULL)
{
	if(pointer->data==pointer->next->data)
	{
		current=pointer->next->next;
		delete(pointer->next);
		pointer->next=current;
	}
	else
	pointer=pointer->next;
}
	
}
int main()
{
	struct node *head=NULL;
	int ele,choice;
	
	do
	{
		printf("enter ele \n");
		scanf("%d",&ele);
		push(&head,ele);
		printf("press 0 for termination\n");
		scanf("%d",&choice);
	}while(choice!=0);

	printList(&head);
	removeDuplicates(&head);
	printList(&head);
}
