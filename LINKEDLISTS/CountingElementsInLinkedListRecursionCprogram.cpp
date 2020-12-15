//WAPT TO OBTAIN LENGTH OF LIST USING RECURSION
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void push(struct node **head,int newdata)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=newdata;
	newnode->next=*head;
	*head=newnode;
}
void printList(struct node **head)
{ struct node *temp=*head;
printf("ele are \n");
while(temp!=NULL)
{
	printf("%d ",temp->data);
	temp=temp->next;
}
printf("\n");
}
int countList(struct node *head)
{
	
	if(head==NULL) return 0;
	else return 1+countList(head->next);
}
int main()
{ struct node *head=NULL;
	int choice,ele,count=0;
	do
	{
	printf("enter ele to insert\n");
	scanf("%d",&ele);
	push(&head,ele);
	printf("press 0 for termination\n");
	scanf("%d",&choice);
	
}while(choice!=0);
struct node *temp=head;
printList(&temp);
count= countList(head);
printf("count of ele is %d\n",count);
}
