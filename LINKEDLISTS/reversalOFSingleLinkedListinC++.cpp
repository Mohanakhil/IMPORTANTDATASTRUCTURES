//WAP TO REVERSE A SINGLY LINKED LIST
//NULL<-2 <-3 <-4
//
//4->3->2->NULL
#include<iostream>
using namespace std;
class Node
{ 	public:
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
{ cout<<"\nlist is\n";
Node *pointer=*head;
while(pointer!=NULL)
{
	cout<<pointer->data<<" ";
	pointer=pointer->next;
}
}
void reverse(Node **head)
{
	Node *prev=NULL,*current=*head,*next;
	while(current!=NULL)
	{ next=current->next;
	  current->next=prev;
	  prev=current;
	  current=next;
	}
	*head=prev;
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
	reverse(&head);
	printList(&head);
}
