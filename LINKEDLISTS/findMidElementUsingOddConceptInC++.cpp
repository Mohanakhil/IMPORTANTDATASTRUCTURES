//METHOD 3 For finding the middle of linked list
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
void findMiddleUsingOdd(Node **head,int len)
{ int i=0;

	Node *pointer=*head;
	while(i<len)
	{
		if(i%2!=0)
		{
		pointer=pointer->next;
		}
		i++;
	}
	cout<<"\nmid ele is \n"<<pointer->data;
}
int main()
{ Node *head=NULL;
int ele,choice,len=0;
do
{
	cout<<"enter ele to insert\n";
	cin>>ele;
	push(&head,ele);
	len++;
	cout<<"press 0 for termination\n";
	cin>>choice;
}while(choice!=0);
printList(&head);
findMiddleUsingOdd(&head,len);

	
}
