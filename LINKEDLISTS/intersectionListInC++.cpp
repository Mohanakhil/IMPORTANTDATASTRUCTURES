//Intersection of two Sorted Linked Lists
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
{ cout<<"\nlist is\n";
	Node *pointer=*head;
	while(pointer!=NULL)
	{
		cout<<pointer->data<<" ";
		pointer=pointer->next;
	}
}
void intersectionList(Node **head1,Node **head2)
{
	Node *p1=*head1;
bool flag=false;
Node *newhead=NULL;
	while(p1!=NULL)
	{Node *p2=*head2;
		while(p2!=NULL)
		{	
		if(p1->data==p2->data)
		{ cout<<"entered if\n";
			push(&newhead,p2->data);
		
			while(p1->next->data==p1->data&&p1->next)
			{p1=p1->next;
			}
		
			flag=true;
		}
		p2=p2->next;	
		}
		if(flag==false)
		{p1=p1->next;
		}
		flag=false;
	}
	printList(&newhead);
}
int main()
{ int ele,choice;
	Node *head1=NULL;
	Node *head2=NULL;
	do
	{
		cout<<"enter ele\n";
		cin>>ele;
		push(&head1,ele);
		cout<<"press 0 for term\n";
		cin>>choice;
	}while(choice!=0);
	printList(&head1);
	do
	{
		cout<<"enter ele\n";
		cin>>ele;
		push(&head2,ele);
		cout<<"press 0 for termination\n";
		cin>>choice;
	}while(choice!=0);
	printList(&head2);
	intersectionList(&head1,&head2);
	
		
}
