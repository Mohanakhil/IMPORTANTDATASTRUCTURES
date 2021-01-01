//Given a Linked List and a number n, write a function that returns the value at the n’th node from the end of the Linked List.
//USING 2POINTERS CONCEPT
#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
};
void push(Node **head,int newdata)
{Node *newnode=new Node();
newnode->data=newdata;
newnode->next=*head;
*head=newnode;
}
void printList(Node **head)
{cout<<"\nlist is\n";
	Node *pointer=*head;
	while(pointer!=NULL)
	{
		cout<<pointer->data<<" ";
		pointer=pointer->next;
	}
}
void getNodeFromLastUsingPointers(Node **head)
{ int index;
	Node *first=*head,*second=*head;
	cout<<"enter index of node from last\n";
	cin>>index;
	int t=index;
	while(index>0)
	{
		index--;
		second=second->next;
	}
	while(second!=NULL)
	{ second=second->next;
	first=first->next;
		
	}
	cout<<"\nele at index= "<<t<<" from last is "<<first->data<<"\n";
	
}
int main()
{ int ele,choice;
	Node *head=NULL;
	do
	{
	cout<<"enter ele to insert\n";
	cin>>ele;
	push(&head,ele);
	cout<<"press 0 for termination\n";
	cin>>choice;
	}while(choice!=0);
	printList(&head);
	do
	{	
		getNodeFromLastUsingPointers(&head);
		printList(&head);
		cout<<"press 0 for termination\n";
	cin>>choice;
	}while(choice!=0);
	
}
