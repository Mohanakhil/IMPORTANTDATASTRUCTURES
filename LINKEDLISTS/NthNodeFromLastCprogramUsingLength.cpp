//WAP TO FIND NTH NODE FROM LAST OF LINKED LIST BY  MAKING USE OF LENGTH CONCEPT
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int push(struct node **head,int newdata)
{ struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=newdata;
newnode->next=*head;
*head=newnode;
static int count=0;
count++;
return count;
}
void printList(struct node **head)
{ printf("\n");
	struct node *temp=*head;
	while(temp!=NULL)
	{ printf("%d ",temp->data);
		temp=temp->next;
	}
}
void searchUsingLength(struct node **head,int index)
{ struct node *temp=*head;
int i=index;
if(temp==NULL) 
{
printf("list is empty\n");
return ;
}
while(temp->next!=NULL&&i>1)
{
temp=temp->next;
i--;
}
printf("ele at index %d is %d",index,temp->data);
	
}
int main()
{ struct node *head=NULL;
int ele,choice,index,length;
do
{
	printf("enter ele to insert\n");
	scanf("%d",&ele);
	length=push(&head,ele);
	printf("enter 0 for termination\n");
	scanf("%d",&choice);
}while(choice!=0);
printList(&head);
printf("\nlength of list is %d \n",length);
do
{
printf("\nenter value of n that you want and it will be calc from last(assume index starts with 1)\n");
scanf("%d",&index);
index=length-index+1;
printf("\nele is %d from first\n",index);
searchUsingLength(&head,index);
printList(&head);
printf("\nenter 0 for termination\n");
scanf("%d",&choice);
}while(choice!=0);

}
