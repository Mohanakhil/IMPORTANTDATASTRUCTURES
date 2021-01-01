//Reverse a linked list
//Given pointer to the head node of a linked list, the task is to reverse the linked list. We need to reverse the list by changing the links between nodes.
//RECURSIVE METHOD
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void printList(struct node **head)
{ printf("\nnew list is\n");
	struct node *pointer=*head;
	while(pointer!=NULL)
	{
		printf("%d ",pointer->data);
		pointer=pointer->next;
	}
}
void push(struct node **head,int newdata)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=newdata;
	newnode->next=*head;
	*head=newnode;
	
}
struct node  reverseSinglyLinkedListUsingRecursion(struct node **head,struct node **prev,struct node **next)
{

 if(*head==NULL) return **head;
 else
 {
 	*next=(*head)->next;
 	(*head)->next=*prev;
 	*prev=*head;
 	*head=*next;
 	return reverseSinglyLinkedListUsingRecursion(head,prev,next);
 }
}
int main()
{ int ele,choice;
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
	struct node *prev=NULL,*next;
	*head= reverseSinglyLinkedListUsingRecursion(&head,&prev,&next);

	printList(&head);
}
