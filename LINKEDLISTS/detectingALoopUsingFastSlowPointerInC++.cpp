//Detect loop in a linked list using  2pointers
#include<iostream>
using namespace std;
class Node
{
	public:
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
{
	Node *pointer=*head;
	while(pointer!=NULL)
	{
		cout<<pointer->data<<" ";
		pointer=pointer->next;
	}
}
void countLength(Node *begin)
{ int len=0;

Node *pointer=begin;
cout<<pointer->next->data;
while(pointer->next!=begin)
{
	len++;
	pointer=pointer->next;
}	
len++;
cout<<"\nlen of loop is "<<len<<" ";
}
void detectLoopUsing2Pointers(Node **head)
{
	Node *slow=*head;
	Node *fast=*head;
	while(fast&&fast->next)
	{ 	slow=slow->next;
		fast=fast->next->next;
	if(slow==fast)
	{
		cout<<"\nA loop is detected\n";
		
		countLength(fast);
	 	return;
	}
	
	}
}
int main()
{ int ele,choice;
	Node *head=NULL;
	do
	{
		cout<<"\nenter ele to insert\n";
		cin>>ele;
		push(&head,ele);
		cout<<"press 0 for termination\n";
		cin>>choice;
	}while(choice!=0);
	printList(&head);
	head->next->next->next->next->next=head->next;
detectLoopUsing2Pointers(&head);
	
}

