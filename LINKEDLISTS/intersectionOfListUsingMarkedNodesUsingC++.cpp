//WAP TO DETECT INTERSECTION OF LINKED LISTS (Mark Visited Nodes) 
//This solution requires modifications to basic linked list data structure.
// Have a visited flag with each node. Traverse the first linked list and keep marking visited nodes. 
// traverse the second linked list, If you see a visited node again then there is an intersection point,
// return the intersecting node  value. This solution works in O(l1+l2) time complexity 
//but requires additional information with each node.
#include<iostream>
using namespace std;
class Node
{	public:
	int data;
	int flag;
	Node *next;
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
{cout<<"\nnew list is\n";
	Node *pointer=*head;
	while(pointer!=NULL)
	{
		cout<<pointer->data<<" ";
		pointer=pointer->next;
	}
}	
void intersectionOfLists(Node **head1,Node **head2)
{
	Node *pointer1=*head1;
	while(pointer1!=NULL)
	{
		pointer1->flag=1;
		pointer1=pointer1->next;
	}
	Node *pointer2=*head2;
	while(pointer2!=NULL)
	{
		if(pointer2->flag==1)
		{
		cout<<"\nintersection of lists is present at\n"<<pointer2->data;
		return;
		}
		pointer2=pointer2->next;
	}
	
}
int main()
{ int ele,choice;
	Node *head1=NULL,*head2=NULL;
	do
	{
		cout<<"enter ele\n";
		cin>>ele;
		push(&head1,ele);
		cout<<"press 0 for term\n";
		cin>>choice;
	}while(choice!=0);
	cout<<"\nfirst list is\n";
	printList(&head1);
	do
	{
		cout<<"enter ele\n";
		cin>>ele;
		push(&head2,ele);
		cout<<"press 0 for term\n";
		cin>>choice;	
	}while(choice!=0);
	cout<<"\nsecond list is\n";
	printList(&head2);
	Node *end=head2;
	while(end->next!=NULL)
	{ 
		end=end->next;
	}
	end->next= head1->next->next->next;
	printList(&head2);
	intersectionOfLists(&head1,&head2);
}
