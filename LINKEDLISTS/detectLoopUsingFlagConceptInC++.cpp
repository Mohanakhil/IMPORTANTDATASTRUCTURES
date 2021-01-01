/*
 This problem can be solved without hashmap by modifying the linked list data-structure. 
Approach: This solution requires modifications to the basic linked list data structure. 

Have a visited flag with each node.
Traverse the linked list and keep marking visited nodes.
If you see a visited node again then there is a loop. This solution works in O(n) but requires additional information with each node.
*/
#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
		int flag;
};
void push(Node **head,int newdata)
{
	Node *newnode=new Node();
	newnode->data=newdata;
	newnode->flag=0;
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
void countLength(Node *pointer)
{
	Node *p=pointer;
	int count=1;
	while(p->next!=pointer)
	{
		count++;
		p=p->next;
	}
	cout<<"\nlength of loop is\n"<<count;
}
void detectLoopUsingFlag(Node **head)
{
	Node *pointer=*head;
	while(pointer!=NULL)
	{	if(pointer->flag==1)
	{
		cout<<"\nloop is detected\n";
		countLength(pointer);
		return;
	}
		pointer->flag=1;
		pointer=pointer->next;
		
	}
	cout<<"loop is not detected\n";
}
int main()
{ int ele,choice;
	Node *head=NULL;
	do
	{
		cout<<"enter ele\n";
		cin>>ele;
		push(&head,ele);
		cout<<"press 0 for termination\n";
		cin>>choice;
		
	}while(choice!=0);
	printList(&head);
	head->next->next->next->next=head;
	detectLoopUsingFlag(&head);
	
}
