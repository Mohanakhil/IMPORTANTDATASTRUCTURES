//Write a function to get Nth node in a Linked List
//USING RECURSION
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
{
	Node *pointer=*head;
	while(pointer!=NULL)
	{
		cout<<pointer->data<<" ";
		pointer=pointer->next;
	}
}
int getNode(Node *head,int index,int count,int current)
{ 
if(index>count) return -1;
if(current==index) 
{return (head)->data;
}
else 
{
return getNode((head)->next,index,count,++current);
}
}
int main()
{ Node *head=NULL;
int ele,choice,n,index,count=0;
	
	do
	{
	cout<<" enter ele to insert\n";
	cin>>ele;
	push(&head,ele);
	count++;
	cout<<"\npress 0 for termination\n";
	cin>>choice;
	}while(choice!=0);
	do
	{
	printList(&head);
	cout<<"enter index of Node to get\n";
	cin>>index;
	int current=0;
	int number= getNode(head,index,count,current);
	if(number==-1) cout<<" no node with that index\n";
	else cout<<"ele in given index is "<<number<<" ";
	cout<<"\npress 0 for termination\n";
	cin>>choice;
	}while(choice!=0);
	
}
