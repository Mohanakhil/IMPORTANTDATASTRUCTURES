//Swap nodes in a linked list without swapping data
//Given a linked list and two keys in it, swap nodes for two given keys. Nodes should be swapped by changing links. Swapping data of nodes may be expensive in many situations when data contains many fields. 
//It may be assumed that all keys in the linked list are distinct.
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
		cout<<pointer->data;
		pointer=pointer->next;
	}
}
void swapNodes(Node **head)
{ int first,second;
	Node *prev,*current;
	cout<<"enter 2 eles to swap\n";
	cin>>first;
	cin>>second;
	while(pointer!=NULL)
	{
		
	}
	
}
int main()
{
int ele,choice;
do
{
	cout<<"enter ele \n";
	cin>>ele;
	push(&head,ele);
	cout<<"press 0 for termination\n";
	cin>>choice;
	}while(choice!=0);
	printList(&head);
	swapNodes(&head);
	
}
