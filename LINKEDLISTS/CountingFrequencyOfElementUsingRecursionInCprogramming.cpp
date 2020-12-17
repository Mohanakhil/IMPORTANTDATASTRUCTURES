//Write a function that counts the number of times a given int occurs in a Linked List 
//USING RECURSION
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
	printf("list is\n");
	while(pointer!=NULL)
	{ printf("%d ",pointer->data);
		pointer=pointer->next;
	}
}
int countFrequencyUsingRecursion(struct node *head,int ele,int count)
{ 
	struct node *pointer=head;
	if(pointer==NULL) return count;
	if(pointer->data==ele) count++;
	return countFrequencyUsingRecursion(head->next,ele,count);

}
int main()
{ int ele,choice;

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
	do
	{ int count=0;
		printf("enter ele that you want to find frequency\n");
		scanf("%d",&ele);
		count= countFrequencyUsingRecursion(head,ele,count);
		if(count==0)
		printf("ele is not present\n");
		else printf("ele %d has frequency of %d\n",ele,count);
		printf("press 0 for termination\n");
		scanf("%d",&choice);
	}while(choice!=0);
}
