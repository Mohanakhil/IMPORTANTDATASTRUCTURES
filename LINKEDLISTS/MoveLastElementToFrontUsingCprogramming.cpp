//Move last NODE to front of a given Linked List
/*Write a function that moves the last NODE to the front in a given Singly Linked List. For example, if the given Linked List is 1->2->3->4->5, then the function should change the list to 5->1->2->3->4.
Algorithm:
Traverse the list till last node. Use two pointers: one to store the address of last node and other for address of second last node. After the end of loop do following operations.
i) Make second last as last (secLast->next = NULL).
ii) Set next of last as head (last->next = *head_ref).
iii) Make last as head ( *head_ref = last)
TIME COMPLEXITY -O(n)
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
{
	struct node *pointer=*head;
	while(pointer!=NULL)
	{
		printf("%d ",pointer->data);
		pointer=pointer->next;
	}
}
void moveLastNodeToFront(struct node **head)
{	struct node *prev=NULL,*current=*head;
while(current->next!=NULL)
{	prev=current;
	current=current->next;
}
printf("\nprev and current are %d %d\n",prev->data,current->data);	
prev->next=NULL;
current->next=(*head);
*head=current;
}
int main()
{ int choice,ele;
	struct node *head=NULL;
	do
	{
		printf("enter ele in list\n");
		scanf("%d",&ele);
		push(&head,ele);
		printf("press 0 for termination\n");
		scanf("%d",&choice);
	}while(choice!=0);
	printList(&head);	
	moveLastNodeToFront(&head);
	printList(&head);

}
