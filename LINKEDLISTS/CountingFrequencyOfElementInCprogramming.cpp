//Write a function that counts the number of times a given int occurs in a Linked List
//WITHOUT RECURSION
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
{
	struct node *temp=*head;
	printf("list is\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int countFrequency(struct node **head,int ele)
{ struct node *temp=*head;int count=0;
while(temp!=NULL)
{
	if(temp->data==ele) count++;
	temp=temp->next;
}
return count;
}
int main()
{ struct node *head=NULL;
	int ele,choice,count=0;
	do
	{
	printf("enter ele to insert\n");
	scanf("%d",&ele);
	push(&head,ele);
	printf("press  0 for termination\n");
	scanf("%d",&choice);
}while(choice!=0);
printList(&head);
do
{printf("enter ele to count for frequency\n");
scanf("%d",&ele);
count= countFrequency(&head,ele);
if(count==0) printf("ele is not present\n");
else 	
printf("count of ele %d is %d\n",ele,count);
printf("press  0 for termination\n");
	scanf("%d",&choice);
}while(choice!=0);

}
