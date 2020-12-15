//WAP TO GET NTH NODE IN LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void push(struct node **head,int newdata)
{struct node *newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=newdata;
newnode->next=*head;
*head=newnode;
}
void getNodeValue(struct node **head,int index)
{ struct node *temp=*head;
int i=index;
	while(index>0&&temp->next!=NULL)
	{   
		temp=temp->next;
		index--;
	}
	printf("ele at %d index is %d\n",i,temp->data);
	
}
void printList(struct node **head)
{ printf("list is \n");
	struct node *temp=*head;
	while(temp!=NULL)
	{ printf("%d ",temp->data);
		temp=temp->next;
		
	}
}
int main()
{ struct node *head=NULL;
	int index,ele,choice;
	do
	{ printf("enter ele to insert into list\n");
	scanf("%d",&ele);
	push(&head,ele);
	printf("press 0 for  termination\n");
	scanf("%d",&choice);
	}while(choice!=0);
	printList(&head);
	do
	{
	printf("enter  index you want and assume that index starts with 0\n");
	scanf("%d",&index);
	getNodeValue(&head,index);
	printList(&head);
	printf("press 0 for  termination\n");
	scanf("%d",&choice);
}while(choice!=0);
	
}
