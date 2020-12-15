//WAP TO SEARCH FOR ELE IN LINKEDLIST
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
	printf("list is \n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void searchInListByIteration(struct node **head,int ele)
{struct node *temp=*head;int count=0;
if(temp==NULL) {
printf("list is empty");
return ;
}
bool flag=false;
while(temp!=NULL)
{
if(temp->data==ele)
{
  printf("\nele %d is present in list and present at index= %d(index starts with 0)\n",temp->data,count);
  flag=true;
break;
}
temp=temp->next;
count++;
}
if(flag==false)
printf("ele %d is not present\n",ele);	
}
int searchInListByRecursion(struct node *head,int ele,int count)
{ struct node *temp=head;

if(temp==NULL)
{
	return -1;
}

else if(temp!=NULL)
{ 

if(temp->data==ele) return count;
count=count+1;
return searchInListByRecursion(head->next,ele,count);

}
	
}
int main()
{ struct node *head=NULL;
	int choice=1,ele;
	
	do
	{
		printf("enter ele to insert in linked list\n");
		scanf("%d",&ele);
		push(&head,ele);
		printf("press 0 for termination\n");
		scanf("%d",&choice);
	}while(choice!=0);
	printList(&head);
	do
	{
		printf("\nenter ele to search\n");
		scanf("%d",&ele);
		searchInListByIteration(&head,ele);
	int c=0;
		int index= searchInListByRecursion(head,ele,c);
		if(index>=0)
		printf("\n ele is present at index= %d\n",index);
		else printf("ele is not present\n");
		printList(&head);
		printf("\npress 0 for termination\n");
		scanf("%d",&choice);
	}while(choice!=0);
}
