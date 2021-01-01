//Program for n’th node from the end of a Linked List
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
void getNodeFromLastUsing2Pointers(Node **head,int count)
{ int index;
	Node *first=*head,*second=*head;
	cout<<"\nenter index of node you req  from last and count as 1 to n \n";
	cin>>index;
	int t=index;
	if(index>count) 
	{cout<<"\nindex out of bound\n";
	return;
	}
	while(index>0)
	{
		index--;
		second=second->next;
	}
	while(second!=NULL)
	{	first=first->next;
		second=second->next;
	}
	cout<<"ele at index= "<<t<<" from last is "<<first->data<<"\n";
	
}
int main()
{
	Node *head=NULL;
	int ele,choice,count=0;
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
		getNodeFromLastUsing2Pointers(&head,count);
		cout<<"press 0 for termination\n";
		cin>>choice;
	}while(choice!=0);

}
