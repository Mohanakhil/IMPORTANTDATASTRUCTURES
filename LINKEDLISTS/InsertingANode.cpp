//wap to add node as required by user
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void createList(struct node **head,int newdata)    /*ADD A NODE AT THE FRONT OF THE LINKED LISTS */
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=newdata;
	newnode->next=*head;
	*head=newnode;
}
void insertAfter(struct node *pointer,int newdata)           /*ADD A NODE AT AFTER CERTAIN NODE*/
{ 
struct node *newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=newdata;
 if(pointer==NULL)
 {
 printf("there is no previous element\n");
 return;
 }
 else
 {
 newnode->next=pointer->next;
 pointer->next=newnode;
}
}
void insertATEnd(struct node *pointer,int newdata,struct node **head) /*ADD NODE AT THE END*/
{ 

	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=newdata;
	newnode->next=NULL;
	if(pointer==NULL)
	{
	pointer=newnode;
	*head=pointer;
		return ;
	}
	else
	pointer->next=newnode;
}

void printList(struct node *pointer)
{ printf("\ncreated list is \n");
	while(pointer!=NULL)
	{
		printf("%d ",pointer->data);
		pointer=pointer->next;
	}
}
int main()
{ struct node *head=NULL;int choice=1,newelement=0,menu=0,node;
do
{
printf("1-for inserting at front\n2-for after certain node\n3-for end\n");
scanf("%d",&menu);
switch(menu)
{
case 1:
{

do
{
	printf("enter new ele \n");
	scanf("%d",&newelement);
	createList(&head,newelement);
	printf("press 0 for termination of first choice\n");
	scanf("%d",&choice);

}while(choice!=0);

printList(head);
break;
}
case 2:
{ 
do{
printf("enter new ele \n");
scanf("%d",&newelement);
if(head!=NULL)
{
printf("enter node after which new element is required \n");
scanf("%d",&node);
struct node *pointer=head;
if(node==0)
{ createList(&head,newelement);	
}
else
{
while(node>1)
{  pointer=pointer->next;
	node--;
}
insertAfter(pointer,newelement);

}
}
else if(head==NULL)
{  printf("this is the first element you are entering\n");
createList(&head,newelement);	
	
}
printf("press 0 for termination of second choice\n");
scanf("%d",&choice);
}while(choice!=0);
printList(head);
break;

}
case 3:
	{ 
	do{
	printf("enter ele to insert at end\n");
	scanf("%d",&newelement);
	struct node *pointer=head;
	while(pointer->next!=NULL)
	{
		pointer=pointer->next;
	}
	insertATEnd(pointer,newelement,&head);
	printf("press 0 for termination of third choice\n");
	scanf("%d",&choice);	
	}while(choice!=0);
	printList(head);
	break;
}
}
printf("press 0 for menu termination\n");
scanf("%d",&choice);
}while(choice!=0);

}

