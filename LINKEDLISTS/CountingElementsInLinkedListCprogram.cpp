//WAP TO FIND LENGTH OF LINKED LIST
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
int printList(struct node **head)
{ int count=0;
	struct node *temp=*head;
	if(temp==NULL)
	printf("list is empty\n");
	else 
	{
	printf("\nlist is \n");
	while(temp!=NULL)
	{ count++;
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
	return count;
}
int main()
{
	struct node *head=NULL;
	int choice,element;
do
	{
		printf("enter ele to insert in list\n");
		scanf("%d",&element);
		push(&head,element);
		printf("press 0 for termination\n");
		scanf("%d",&choice);
		
	}while(choice!=0);
	int count= printList(&head);
	printf("\ncount of ele is %d\n",count);
	
	
}

