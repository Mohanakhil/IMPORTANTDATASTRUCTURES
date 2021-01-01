//Pairwise swap elements of a given linked list
/*

Input : 1->2->3->4->5->6->NULL
Output : 2->1->4->3->6->5->NULL

Input : 1->2->3->4->5->NULL
Output : 2->1->4->3->5->NULL

Input : 1->NULL
Output : 1->NULL
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
	printf("\nlist is \n");
	struct node *pointer=*head;
	while(pointer!=NULL)
	{
		printf("%d ",pointer->data);
		pointer=pointer->next;
	}
	printf("\nprinting over\n");
}
void swapAdjacentElements(struct node **head)
{
struct node *pointer=*head;
while(pointer&&pointer->next)
{
	int temp=pointer->data;
	pointer->data=pointer->next->data;
	pointer->next->data=temp;
	pointer=pointer->next->next;
}
}
int main()
{ struct node *head=NULL;
 int ele,choice;
	do
	{
		printf("enter ele to enter in list\n");
		scanf("%d",&ele);
		push(&head,ele);
		printf("press 0 for termination\n");
		scanf("%d",&choice);
	}while(choice!=0);
	printList(&head);
	swapAdjacentElements(&head);
	printf("\nafter swapping\n");
	printList(&head);
}
