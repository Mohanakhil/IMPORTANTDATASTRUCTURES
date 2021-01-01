//Delete a Linked List node at a given position
//Given a singly linked list and a position, delete a linked list node at the given position.
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
	if(pointer==NULL) cout<<"list is empty\n";
	while(pointer!=NULL)
	{
		cout<<pointer->data<<" ";
		pointer=pointer->next;
	}
}
void deleteAKey(Node **head)
{ int key,index=0;
	Node *pointer=*head;
	cout<<"enter key to delete\n";
	cin>>key;
	while(pointer!=NULL)
	{
	if(key==(*head)->data) 
	{ cout<<"entered first if\n";
	cout<<" ele "<<key<<" is found at index= "<<index<<" and it gets deleted\n";
	*head=(*head)->next;
	return;
	}
	else if(key==pointer->next->data&&pointer->next->next!=NULL)
	{cout<<"entered second if\n";
	index++;
	 cout<<" ele "<<key<<" is found at index= "<<index<<" and it gets deleted\n";
	pointer->next=pointer->next->next;
	return;
	}
	else if(pointer->next->next==NULL)
	{
		cout<<" entered third if\n";
		index++;
		 cout<<" ele "<<key<<" is found at index= "<<index<<" and it gets deleted\n";
		pointer->next=NULL;
		return ;
	}
	index++;
	pointer=pointer->next;
	}
}
int main()
{ Node *head=NULL;
int ele,choice,count=0;
do
{
	cout<<"enter ele to insert\n";
	cin>>ele;
	push(&head,ele);
	count++;
	cout<<"press 0 for termination\n";
	cin>>choice;
}while(choice!=0);
cout<<" count of ele is "<<count<<"\n";
do
{
printList(&head);
deleteAKey(&head);
cout<<"\nlist after deletion is \n";
printList(&head);
	cout<<"press 0 for termination\n";
	cin>>choice;
}while(choice!=0);

}
