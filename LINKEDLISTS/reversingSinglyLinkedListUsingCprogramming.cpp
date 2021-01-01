//Reverse a linked list
//Given pointer to the head node of a linked list, the task is to reverse the linked list. We need to reverse the list by changing the links between nodes.
//ITERATIVE METHOD 
//TIME COMPLEXITY O(N)
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int   data;
	struct node *next;
};
void push(struct node **head,int newdata)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data =newdata;
	newnode->next =*head;
	*head=newnode;
}
void printList(struct node **head)
{ printf("\nnew list is \n");
	struct node *pointer=*head;
	while(pointer!=NULL)
	{
		printf("%d ",pointer->data);
		pointer=pointer->next;
	}
}
void reverseSinglyLinkedList(struct node **head)
{
	struct node *prev=NULL,*current=*head,*next=NULL;
	while(current!=NULL)
	{ next=current->next;
	current->next=prev;	
 	prev=current;
	current=next; 	
	}
	*head=prev;
}
int main()
{ struct node *head=NULL;	
int ele,choice;
do
{
	printf("enter ele to insert into list\n");
	scanf("%d",&ele);
	push(&head,ele);
	printf("enter 0 for termination\n");
	scanf("%d",&choice);
}while(choice!=0);
printList(&head);
reverseSinglyLinkedList(&head);
printList(&head);
}
