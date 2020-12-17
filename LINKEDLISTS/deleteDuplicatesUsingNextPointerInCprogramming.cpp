//Remove duplicates from a sorted linked list using next pointer concept by  traversing only once
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
	{
		printf("%d ",pointer->data);
		pointer=pointer->next;
	}
}
bool deleteDuplicates(struct node **head)
{ bool flag=false;
struct node *next;
struct node *pointer=*head;
if(pointer==NULL) 
{
printf("list is empty\n");
return false;
}
while(pointer->next!=NULL)
{ 
if(pointer->data==pointer->next->data)
{ flag=true;
next=pointer->next->next;
free(pointer->next);
pointer->next=next;	
}
else pointer=pointer->next;	
}
return flag;
}
int main()
{ struct node *head=NULL;
int ele,choice;
do
{
	printf("enter ele to insert\n");
	scanf("%d",&ele);
	push(&head,ele);
	printf("press 0 for termination\n");
	scanf("%d",&choice);
}while(choice!=0);
printList(&head);
bool flag=deleteDuplicates(&head);
if(flag==true) printf("duplicates are deleted\n");
else printf("there are no duplicates\n");
printList(&head);
}
