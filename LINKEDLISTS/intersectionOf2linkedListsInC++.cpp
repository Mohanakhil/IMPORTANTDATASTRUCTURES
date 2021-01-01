//Write a function to get the intersection point of two Linked Lists
//There are two singly linked lists in a system. By some programming error, the end node of one of the linked list got linked to the second list, forming an inverted Y shaped list. Write a program to get the point where two linked list merge. 
#include<iostream>
using namespace std;
class Node
{	public:
	int data;
	Node *next;
};
push(Node **head,int newdata)
{
	Node *newnode=new Node();
	newnode->data=newdata;
	newnode->next=*head;
	*head=newnode;
	
}
void printList(Node **head)
{ cout<<"\nyour list is\n";
	Node *pointer=*head;
	while(pointer!=NULL)
	{ cout<<pointer->data<<" ";
	pointer=pointer->next;	
	}
}
void intersectionPoint(Node **head1,Node **head2)
{ Node *pointer1=*head1;

while(pointer1->next!=NULL)
{ Node *pointer2=*head2;
while(pointer2->next!=NULL)
{ if(pointer1==pointer2)
{
	cout<<"\nintersection is detected at \n"<<pointer1->data<<" \n";
	return;
}
	pointer2=pointer2->next;
}
	pointer1=pointer1->next;
}
	
}

int main()
{ Node *head1=NULL;
Node *head2=NULL;
int ele,choice;
do
{
	cout<<"enter new ele\n";
	cin>>ele;
	push(&head1,ele);
	cout<<"press 0 for termination\n";
	cin>>choice;
}while(choice!=0);
printList(&head1);
do
{
	cout<<"enter new ele for 2nd list\n";
	cin>>ele;
	push(&head2,ele);
	cout<<"press 0 for termination\n";
	cin>>choice;
}while(choice!=0);
printList(&head2);
Node *end=head2;
while(end->next!=NULL)
{
	end=end->next;
}
end->next=  head1->next->next->next;
printList(&head1);
printList(&head2);
intersectionPoint(&head1,&head2);
}
