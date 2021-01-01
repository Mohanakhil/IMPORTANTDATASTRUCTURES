//Write a function that counts the number of times a given int occurs in a Linked List
//Given a singly linked list and a key, count number of occurrences of given key in linked list. For example, if given linked list is 1->2->1->2->1->3->1 and given key is 1, then output should be 4.
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
	Node  *newnode=new Node();
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
void countFrequency(Node **head)
{ int x;
	Node *pointer=*head;
	int count=0;
	cout<<"\nenter ele to search for\n";
	cin>>x;
	while(pointer!=NULL)
	{
		if(pointer->data==x)
		count++;
		pointer=pointer->next;
	}
	cout<<"ele "<<x<<" is present for "<<count<<" times";
}
int main()
{ int choice,ele;
Node *head=NULL;
	do
	{
	cout<<"enter ele to insert\n";
	cin>>ele;
	push(&head,ele);
	cout<<"press 0 for termination\n";
	cin>>choice;
    }while(choice!=0);
    do
    {
    printList(&head);
    countFrequency(&head);
    cout<<"\npress 0 for termination\n";
	cin>>choice;
	}while(choice!=0);
    
}
