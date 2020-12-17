	//Print the middle of a given linked list using length concept
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
int  printList(struct node **head)
{ int len=0;
	struct node *temp=*head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
		len++;
	}
	return  len;
	
}
void middleOfLinkedListUsingLength(struct node **head,int len)
{ struct node *temp=*head;
if(temp==NULL)
{ printf("list is empty\n");
	return;
}
	if(len%2==0) 
	{
		printf("length is even\n");
		len=len/2;
		while(len>1&&temp->next!=NULL)
		{ temp=temp->next;
			len--;
		}
		printf("mid ele is %d\n",temp->next->data);
	}
	else
	{ printf("length is odd\n");
	len=len/2;
	
	while(len>0&&temp->next!=NULL)
	{temp=temp->next;
		len--;
	}
	printf("mid ele is %d\n",temp->data);
	}
}
int main()
{ int ele,choice,len;
struct node *head=NULL;
do
{
	printf("enter ele to insert\n");
	scanf("%d",&ele);
	push(&head,ele);
	printf("press 0 for termination\n");
	scanf("%d",&choice);
}while(choice!=0);
len=printList(&head);
middleOfLinkedListUsingLength(&head,len);
printf("\nlength of list = %d\n",len);

}
