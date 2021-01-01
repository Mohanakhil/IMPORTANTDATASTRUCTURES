//PROGRAM FOR DELETING A NODE AT GIVEN POSITION/INDEX
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
	if(pointer==NULL) cout<<"list is empty\n";
	while(pointer!=NULL)
	{
		cout<<" "<<pointer->data<<" ";
		pointer=pointer->next;
	}
}
void deleteNode(Node **head,int index)
{
	if(index==0)
	{ cout<<"\nfirst ele gets deleted\n";
	*head=(*head)->next;
		return;
	}
	Node *pointer=*head;
while(index>1&&pointer->next!=NULL)
{
	index--;
	pointer=pointer->next;
}
if(pointer->next->next==NULL)
{
	cout<<" last ele gets deleted\n";
	pointer->next=NULL;
	return;
	
}
Node *temp=pointer->next->next;
pointer->next=temp;


}
int main()
{ Node *head=NULL;
int ele,choice,index;
do
{
	cout<<"\nenter ele to insert\n";
	cin>>ele;
	push(&head,ele);
	cout<<"\npress 0 for termination\n";
	cin>>choice;
}while(choice!=0);
printList(&head);
do
{
	cout<<"\nenter index of ele to delete assuming index starts with 0\n";
	cin>>index;
	deleteNode(&head,index);
	printList(&head);
	cout<<"\npress 0 for termination\n";
	cin>>choice;
	
}while(choice!=0);
	
}
