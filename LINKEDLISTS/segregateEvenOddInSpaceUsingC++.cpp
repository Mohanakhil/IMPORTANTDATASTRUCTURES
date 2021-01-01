//WAP TO SEGREGATE EVEN AND ODD ELEMENTS IN LINKED LIST
#include<iostream>
using namespace std;
class Node
{	public:
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
{ Node *pointer=*head;
	cout<<"\nlist is\n";
	while(pointer!=NULL)
	{
		cout<<pointer->data<<" ";
		pointer=pointer->next;
	}
}
void reverse(Node **head)
{ Node *prev=NULL,*current=*head,*next;
while(current!=NULL)
{
	next=current->next;
	current->next=prev;
	prev=current;
	current=next;
}
*head=prev;
}
void segrgateEvenOdd(Node **head)
{
Node *pointer1=*head;

Node *oddhead=NULL;
Node *evenhead=NULL;
while(pointer1!=NULL)
{
if(pointer1->data%2==0)
{
	push(&evenhead,pointer1->data);
	
}
else 
{
	push(&oddhead,pointer1->data);
}
pointer1=pointer1->next;	
}
reverse(&evenhead);
reverse(&oddhead);	
printList(&evenhead);
printList(&oddhead);
Node *p=evenhead;
while(p->next!=NULL)
{
	p=p->next;
}
while(oddhead!=NULL)
{
	p->next=oddhead;
	oddhead=oddhead->next;
	p=p->next;
}

printList(&evenhead);
}

int main()
{
Node *head=NULL;
int ele,choice;
do
{
	cout<<"enter any ele\n";
	cin>>ele;
	push(&head,ele);
	cout<<"press 0 for termination\n";
	cin>>choice;
}while(choice!=0);
printList(&head);
segrgateEvenOdd(&head);

}
