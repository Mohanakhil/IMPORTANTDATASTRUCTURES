//Linked List |  (Inserting a node)
//O(n)
#include<iostream>
using namespace std;
class Node
{ public:
	int data;
	Node *next;
	
};
void printList(Node **head)
{ cout<<"list is \n";
	Node *pointer=*head;
	while(pointer!=NULL)
	{ cout<<" "<<pointer->data<<" ";
	pointer=pointer->next;
	}
	cout<<"\nprinting is over\n";
}
void push(Node **head,int newdata)
{ Node *newnode=new Node();
newnode->data=newdata;
newnode->next=*head;
*head=newnode;
printList(head);
}
void pushRandom(Node **head,int newdata)
{ int index;	Node *pointer=*head;
	if(pointer==NULL) 
	{ cout<<"empty list\n";
	return;
	}
	cout<<"enter index of node after which new ele will be inserted\n";
	cin>>index;


	if(index==0)
	{
		cout<<"please press 0 for insertion at front\n";
		return ;
	}
	while(pointer!=NULL&&index>1)
	{
		index--;
		pointer=pointer->next;
		
	}
	Node *newnode=new Node();
	newnode->data=newdata;
	newnode->next=pointer->next;
	pointer->next=newnode;
	printList(head);
	
}

void pushEnd(Node **head,int newdata)
{
	Node *pointer=*head;
	while(pointer->next!=NULL)
	{
		pointer=pointer->next;
	}
	Node *newnode=new Node();
	newnode->data=newdata;
	newnode->next=NULL;
	pointer->next=newnode;
	printList(head);
}
int main()
{ Node *head=NULL;
int ele,choice;
	do
	{
		cout<<"enter ele to insert in list\n";
		cin>>ele;
		push(&
		head,ele);
		cout<<"enter 0 for termination\n";
		cin>>choice;
	}while(choice!=0);

	printList(&head);
	do
	{
	cout<<"enter 0-for insertion at front\n1-for insertion at random position\n2-for insertion at end and\n 3 for overall termination\n";
	cin>>choice;
	switch(choice)
	{
		case 0: 
		{
			cout<<"enter new ele\n";
			cin>>ele;
			push(&head,ele);
			break;
		}
		case 1:
			{
				cout<<"enter new ele to insert at random\n";
				cin>>ele;
				pushRandom(&head,ele);
						break;
			}
		case 2: 
		{
			cout<<"enter new ele to insert at end\n";
			cin>>ele;
			pushEnd(&head,ele);
			break;
		}
	}
	}while(choice!=3);
}
