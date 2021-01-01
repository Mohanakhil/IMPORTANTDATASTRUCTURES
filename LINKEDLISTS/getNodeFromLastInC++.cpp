//Program for n’th node from the end of a Linked List
//Given a Linked List and a number n, write a function that returns the value at the n’th node from the end of the Linked List.
//USING LENGTH OF LIST
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
void getNodeFromLast(Node **head,int count)
{ Node *pointer=*head;
int n;
cout<<"\nenter index of ele you require starting from last assuming index starts with  1\n";
cin>>n;
int last =count-n+1;
if(last>count) cout<<"\nsorry No ele with this huge index\n";
else 
{
	while(last>1&&pointer!=NULL)
	{
		last--;
		pointer=pointer->next;
	}
	cout<<"\nele at index = "<<n<<" from last is "<<pointer->data;
}
	
}
int main()
{ int choice,ele,count=0;
	Node *head=NULL;
	do
	{
		cout<<"enter ele to insert\n";
		cin>>ele;
		push(&head,ele);
		count++;
		cout<<"press 0 for termination\n";
		cin>>choice;
	}while(choice!=0);
	printList(&head);
	do
	{ 
	getNodeFromLast(&head,count);
	cout<<"\npress 0 for termination\n";
	cin>>choice;
	printList(&head);
	}while(choice!=0);
}
