//Write a function to get the intersection point of two Linked Lists
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int main()
{
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
	intersectionPoint(&head);
}
