//Segregate even and odd nodes in a Linked List
/*
Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.

Examples:

Input: 17->15->8->12->10->5->4->1->7->6->NULL
Output: 8->12->10->4->6->17->15->5->1->7->NULL
*/
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
{ printf("\nnow list is\n");
	struct node *pointer=*head;
	while(pointer!=NULL)
	{
		printf("%d ",pointer->data);
		pointer=pointer->next;
	}
}
void segregateEvenOdd(struct node **head)
{ struct node *pointer=*head;
int t;
while(pointer)
{ if(pointer->data%2==0) 
{t=pointer->data;
}
pointer=pointer->next;	
}printf("\nHI HELLO value of t is %d\n",t);
	struct node *prev=NULL,*current=*head;
	
	while(current!=NULL)
	{ struct node *last=*head;
	while(last->next!=NULL)
	{ 
		last=last->next;
	}
	printf("\nlast data=%d ",last->data);
	int temp=current->data;
		if((*head)->data==temp&&temp%2!=0)
		{ 
		 last->next=*head;
		*head=(*head)->next;
		last->next->next=NULL;	
		printList(head);
		printf("\ncurrent= %d \n",current->data);
		
		prev=NULL;
		current=*head;
		if(current->data==t) 
		{ printf("\nreached end\n");
		return;
		}
		}
		else if(temp%2!=0&&current->next!=NULL) 
		{ printf("odd ele found\n");
		struct node *oldprev=prev;
			prev->next=current->next;
			last->next=current;
			last->next->next=NULL;
			prev=oldprev;
			current=prev->next;
			printList(head);
			printf("\ncurrent= %d \n",current->data);
			if(current->data==t) 
		{ printf("\nreached end\n");
			return;	
		}
		}
		else
		{
		prev=current;
		current=current->next;
		}
	}

}
int main()
{ int ele,choice;
	struct node *head=NULL;
	do
	{ printf("enter ele to insert in list\n");
	scanf("%d",&ele);
	push(&head,ele);
	printf("press 0 for termination\n");
	scanf("%d",&choice);
	}while(choice!=0);
	printList(&head);
	
	segregateEvenOdd(&head);
		printList(&head);
}
