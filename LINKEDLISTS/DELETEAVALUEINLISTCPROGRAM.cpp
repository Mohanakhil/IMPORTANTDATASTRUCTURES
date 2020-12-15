//WAP TO DELETE A GIVEN ELEMENT IN LINKED LIST
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
	struct node *temp=*head;
	if(temp==NULL)
	{
		printf("\nlist is empty\n");
	
	}
	else{
	
	printf("list of ele are \n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
}
void deleteElement(struct node **head,int element)
{ struct node *prev=*head;
bool flag=false;
struct node *current=(*head)->next;
if(prev->data==element)
{ *head=prev->next;
	printf("ele is found and it will be deleted\n and ele =%d ",prev->data);
	return ;
}
if(current!=NULL)
{
	while(current!=NULL)
	{
		if(current->data==element)
		{   flag=true;
			printf("hello ele is found and it is deleted\n and ele =%d \n",current->data);
			prev->next=current->next;
			
			delete(current);
			break;
			
		}
	

		current=current->next;
		prev=prev->next;	
	}
	
}
if(flag==false)
printf("ele is not found in this linked list\n");
	
}
int main()
{ struct node *head=NULL;
	int element,choice;
	do
	{
	printf("enter ele to insert \n");
	scanf("%d",&element);
	push(&head,element);
	printf("press 0 for termination\n");
	scanf("%d",&choice);
}while(choice!=0);
printList(&head);
do
{
	printf("enter ele value to delete\n");
	scanf("%d",&element);
	deleteElement(&head,element);
	printList(&head);
	printf("press 0 for termination\n");
	scanf("%d",&choice);
		
}while(choice!=0);
}

