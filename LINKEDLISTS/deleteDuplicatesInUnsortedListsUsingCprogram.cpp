//Remove duplicates from an unsorted linked list
//METHOD 1 (Using two loops) 
//This is the simple way where two loops are used. Outer loop is used to pick the elements one by one and inner loop compares the picked element with rest of the elements. 
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void push(struct node **head,int newdata)
{ struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=newdata;
newnode->next=*head;
*head=newnode;

}
void printList(struct node **head)
{
		struct node *pointer=*head;
	printf("\nlist is \n");
	while(pointer!=NULL)
	{
		printf("%d ",pointer->data);
		pointer=pointer->next;
	}
}
void deleteDuplicatesInUnsortedLists(struct node **head)
{
	struct node *outer=*head;
	while(outer->next!=NULL&&outer!=NULL)
	{ struct node *inner=*head,*temp;
		while(inner->next!=NULL&&inner!=NULL)
		{
			if(outer->data==inner->next->data)
			{ temp=inner->next;
		 inner->next=outer->next->next;
		delete(temp);
				
			}
			else
			inner=inner->next;
		}
		outer=outer->next;
	}
	printList(head);
}
int main()
{ int ele,choice;
	struct node *head=NULL;
	do
	{
	printf("enter ele\n");
	scanf("%d",&ele);
	push(&head,ele);
	printf("enter 0 for termination\n");
	scanf("%d",&choice);
	}while(choice!=0);
	printList(&head);
	deleteDuplicatesInUnsortedLists(&head);
	
}

