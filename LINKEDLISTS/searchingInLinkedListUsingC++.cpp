//SEARCH AN ELEMENT AND FIND THE INDEX OF ELEMENT IN LINKED LIST
#include<iostream>
using namespace std;
class Node
{ public:
	int data;
	Node *next;
};
void printList(Node **head)
{ Node *pointer=*head;
while(pointer!=NULL)
{
	cout<<" "<<pointer->data<<" ";
	pointer=pointer->next;
}
}
void searchElement(Node **head)
{ int x,index=0;
Node *pointer=*head;
	cout<<"\nenter ele to  search\n";
	cin>>x;
	while(pointer!=NULL)
	{ 
		if(pointer->data==x)
		{ cout<<"ele "<<x<<" is present at index= "<<index<<"\n";
			return;
		}
		index++;
		pointer=pointer->next;
	}
	cout<<"\nele "<<x<<" is not present in list\n";
}
void push(Node **head,int newdata)
{
	Node *newnode=new Node();
	newnode->data=newdata;
	newnode->next=*head;
	*head=newnode;
}
int main()
{ int ele,choice;
	Node *head=NULL;
	do
	{
		cout<<"enter ele to insert in list\n";
		cin>>ele;
		push(&head,ele);
		cout<<"enter 0 for termination\n";
		cin>>choice;
		
	}while(choice!=0);
	cout<<"\nlinkedList is created\n";
	printList(&head);
	do
	{
	searchElement(&head);
	cout<<"enter 0 for termination\n";
	cin>>choice;
	}while(choice!=0);
	
}
