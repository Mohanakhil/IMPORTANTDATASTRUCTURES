//Reverse a linked list
/*
Given pointer to the head node of a linked list, the task is to reverse the linked list. We need to reverse the list by changing the links between nodes.

Examples: 

Input: Head of following linked list 
1->2->3->4->NULL 
Output: Linked list should be changed to, 
4->3->2->1->NULL
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void push(struct node **head,int newddat)
{
	struct node *ew
}
int main()
{ int ele,choice;
	struct node *head=NULL;
	do
	{
		printf("enter ele in list");
		scanf("%d",&ele);
		push(&head,ele);
		printf("press 0 for termination");
		scanf("%d",&choice);
	}while(choice!=0);
	printList(&head);
}
