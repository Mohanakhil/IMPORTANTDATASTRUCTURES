//Remove duplicates from an sorted linked list by storing next address
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
{ cout<<"\nnew list is\n";
	Node *pointer=*head;
	while(pointer!=NULL)
	{
		cout<<pointer->data<<" ";
		pointer=pointer->next;
	}
}
void removeDuplicateInSortedList(Node **head)
{
	Node *pointer=*head;
	while(pointer->next!=NULL)
	{	 if(pointer==NULL) cout<<"no ele\n";
		if(pointer->data==pointer->next->data)
		{
			Node *temp=pointer->next->next;
			delete(pointer->next);
			pointer->next=temp;
			
		}
		else
		pointer=pointer->next;
	}
}
int main()
{Node *head=NULL;
int ele,choice;
do
{
	cout<<"enter ele to insert in ascending order\n";
	cin>>ele;
	push(&head,ele);
	cout<<"press 0 for termination\n";
	cin>>choice;
}while(choice!=0);
printList(&head);
removeDuplicateInSortedList(&head);
printList(&head);

}
