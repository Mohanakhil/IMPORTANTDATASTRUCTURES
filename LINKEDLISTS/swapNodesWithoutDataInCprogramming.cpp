//Swap nodes in a linked list without swapping data
/*
Given a linked list and two keys in it, swap nodes for two given keys. Nodes should be swapped by changing links. Swapping data of nodes may be expensive in many situations when data contains many fields. 
It may be assumed that all keys in the linked list are distinct.
Examples: 

Input:  10->15->12->13->20->14,  x = 12, y = 20
Output: 10->15->20->13->12->14

Input:  10->15->12->13->20->14,  x = 10, y = 20
Output: 20->15->12->13->10->14

Input:  10->15->12->13->20->14,  x = 12, y = 13
Output: 10->15->13->12->20->14

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
void swapNodesWithoutSwappingData(struct node **head,int x,int y)
{ 
if(x==y) return;
struct node *previousx=NULL,*currentx=*head;
while(currentx&&currentx->data!=x)
{
	previousx=currentx;
	currentx=currentx->next;
}
struct node *previousy=NULL,*currenty=*head;
while(currenty&&currenty->data!=y)
{
	previousy=currenty;
	currenty=currenty->next;
}
if(currentx==NULL||currenty==NULL) return;
if(previousx!=NULL)
previousx->next=currenty;
else 
*head=currenty;
if(previousy!=NULL)
previousy->next=currentx;
else 
*head=currentx;
struct node *temp=currenty->next;
currenty->next=currentx->next;
currentx->next=temp;


}
int main()
{ int value1=0,value2=0;
	struct node *head=NULL;
	int ele,choice=1;
	do
	{if(choice==1)
	{
	do
	{   
	
		printf("enter ele to insert in list\n");
		scanf("%d",&ele);
		push(&head,ele);
		printf("press 0 for termination of insertion\n");
		scanf("%d",&choice);
	}while(choice!=0);
	printList(&head);
	}
	printf("\nenter 2 values which needs to be swapped\n");
	scanf("%d %d",&value1,&value2);
	swapNodesWithoutSwappingData(&head,value1,value2);
	printf("\nafter swapping nodes in linkedlist\n");
	printList(&head);
	printf("press 0 for termination for swapping nodes and 1 for insertion of nodes\n");
	scanf("%d",&choice);
}while(choice!=0);
}
