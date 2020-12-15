//Print the middle of a given linked list usign 2 pointers
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void push(struct node **head,int newdata)
{struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=newdata;
newnode->next=*head;
*head=newnode;
}
void printList(struct node **head)
{ printf("list is \n");
	struct node *temp=*head;
	while(temp!=NULL)
	{ 
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void middleOfLinkedList(struct node **head)
{ int index=1;
	struct node *first=*head,*second=*head;
	if(first==NULL||first->next==NULL||first->next->next==NULL) 
	{printf("\nlist is not correct for mid ele\n");
	return ;
    }
	while(first->next!=NULL&&second->next!=NULL)
	{
	first=first->next;
	index++;
	if(second->next->next!=NULL)
	second=second->next->next;
    else
	second=second->next;
	
	}
	printf("\nmid ele of this list = %d and index of mid ele= %d\n",first->data,index);
	
	
}
int main()
{ int ele=0,choice;
	struct node *head=NULL;
	do
	{
		printf("enter ele to insert\n");
		scanf("%d",&ele);
		push(&head,ele);
		printf("press 0 for termination\n");
		scanf("%d",&choice);
	}while(choice!=0);
	printList(&head);
	printf("assume index starts with 1");
	middleOfLinkedList(&head);
	
}

