//Move last element to front of a given Linked List
#include<iostream>
using namespace std;
class Node
{ public:
	int data;
	Node *next;
};
void push(Node **head,int newdata)
{
	Node *newnode=new Node();
	newnode->data=newdata;
	newnode->next=*head;
	*head=newnode;
}
void printList(Node **head)
{ cout<<"\nlist is\n";
	Node *pointer=*head;
	while(pointer!=NULL)
	{
		cout<<pointer->data<<" ";
		pointer=pointer->next;
	}
}
void 	lastToFirst(Node **head)
{
	Node *pointer=*head,*prev=NULL;
	if(pointer->next==NULL||pointer==NULL)
	return;
	while(pointer->next!=NULL)
	{ prev=pointer;
	pointer=pointer->next;
	}
	prev->next=NULL;
	pointer->next=*head;
	*head=pointer;
	
}
int main()
{ int ele,choice;
do
{
	Node *head=NULL;
	do
	{
		cout<<"enter ele \n";
		cin>>ele;
		push(&head,ele);
		cout<<"press 0 for termination\n";
		cin>>choice;
	}while(choice!=0);
	printList(&head);
	lastToFirst(&head);
		printList(&head);
		cout<<"press 0 for termination\n";
		cin>>choice;	
	}while(choice!=0);
	
}
