//FINDING THE MID OF LINKED LIST USING SLOW AND FAST POINTER
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
{ Node *pointer=*head;
while(pointer!=NULL)
{
	cout<<pointer->data<<" ";
	pointer=pointer->next;
}	
}
void findMiddleUsingPointers(Node **head)
{ Node *pointer=*head;
	Node *slow=*head,*fast=*head;
	while(fast->next&&fast)
	{
		slow=slow->next;
		if(fast->next->next==NULL)
		break;
		fast=fast->next->next;

	}
	cout<<"\nmiddle ele is "<<slow->data;
}
int main()
{ int ele,choice;
	Node *head=NULL;
	do
	{
		cout<<"eneter ele to insert\n";
		cin>>ele;
		push(&head,ele);
		cout<<"press 0 for termination\n";
		cin>>choice;
	}while(choice!=0);
	printList(&head);
	findMiddleUsingPointers(&head);
}
