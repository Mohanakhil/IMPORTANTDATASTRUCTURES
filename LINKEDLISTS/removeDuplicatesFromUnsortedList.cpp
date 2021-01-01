//Remove duplicates from an unsorted linked list
//Write a removeDuplicates() function which takes a list and deletes any duplicate nodes from the list. The list is not sorted. 
//For example if the linked list is 12->11->12->21->41->43->21 then removeDuplicates() should convert the list to 12->11->21->41->43. 
//METHOD 1 (Using two loops) 
//This is the simple way where two loops are used. Outer loop is used to pick the elements one by one and inner loop compares the picked element with rest of the elements. 
//Time Complexity: O(n^2)
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
void removeDuplicates(struct node **head)
{
	struct node *outerp=*head;
    struct node *innerp;
	while(outerp!=NULL)
	{ 	innerp=outerp;
	while(innerp->next!=NULL&&innerp!=NULL)
	{ 
	if(outerp->data==innerp->next->data)
	{ 
		struct node *temp=innerp->next;
		innerp->next=innerp->next->next;
		delete(temp);
	}
	else
	innerp=innerp->next;	
	}
	outerp=outerp->next;
    }
}
int main()
{
	int ele,choice;
	struct node *head=NULL;
	do
	{
		printf("enter ele to insert in list\n");
		scanf("%d",&ele);
		push(&head,ele);
		printf("press 0 for termination\n");
		scanf("%d",&choice);
	}while(choice!=0);
	printList(&head);
	printf("\nafter removing duplicates\n");
	removeDuplicates(&head);
	printList(&head);
	
}

