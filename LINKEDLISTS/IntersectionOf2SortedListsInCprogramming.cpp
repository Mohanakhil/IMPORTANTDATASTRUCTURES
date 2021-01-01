//Given two lists sorted in increasing order, create and return a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.
/*
Input: 
First linked list: 1->2->3->4->5
Second linked list be 2->3->4, 
Output: 2->3->4
The elements 2, 3, 4 are common in 
both the list so they appear in the 
intersection list.
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
	printf("\nlist is\n");
	while(pointer!=NULL)
	{
		printf("%d ",pointer->data);
		pointer=pointer->next;
		
	}
}
void intersectionOfLists(struct node **head1,struct node **head2,int len1,int len2)
{ if(len1>=len2) 
{ struct node *pointer1=*head1;
struct node *mixhead=NULL;
	while(pointer1)
	{ struct node *pointer2=*head2;
	while(pointer2)
	{
		if(pointer1->data==pointer2->data)
	{
		push(&mixhead,pointer2->data);
		if(pointer1->next==NULL) 
	{ 	printf("\nintersection list is\n");
		printList(&mixhead);
		return ;
	}
		pointer1=pointer1->next;
		
		break;
	}
		pointer2=pointer2->next;
	}
	pointer1=pointer1->next;
	}
	printf("\nintersection  \n");
	printList(&mixhead);
}
else 
{ struct node *pointer2=*head2;
struct node *mixhead=NULL;
while(pointer2)
{
	struct node *pointer1=*head1;
	while(pointer1)
	{ printf("\nentered second while\n");
		if(pointer2->data==pointer1->data)
		{
			push(&mixhead,pointer1->data);
			if(pointer2->next==NULL)
			 {	printf("\n list is\n");
			 	printList(&mixhead);
			 	return;
				}	
				pointer2=pointer2->next;
				break;
		}
		pointer1=pointer1->next;
	}
	pointer2=pointer2->next;
	}
	printf("\nintersection  \n");
	printList(&mixhead);	
}	
}
int main()
{ int ele,choice;
struct node *head1=NULL;
struct node *head2=NULL;
int len1=0,len2=0;
	do
	{
	printf("enter ele to insert in first list\n");
	scanf("%d",&ele);
	push(&head1,ele);
	len1++;
	printf("press 0 for termination\n");
	scanf("%d",&choice);
	}while(choice!=0);
	printList(&head1);
	do
	{
	printf("\nenter  eles to insert in second list\n");
	scanf("%d",&ele);
	push(&head2,ele);
	len2++;
	printf("press 0 for termination\n");
	scanf("%d",&choice);
	}while(choice!=0);	
	printList(&head2);
	intersectionOfLists(&head1,&head2,len1,len2);
}
