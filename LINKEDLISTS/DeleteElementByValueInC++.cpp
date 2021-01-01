//WAP  TO DELETE A NODE BY ENTERING VALUE 
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
void deleteValue(Node **head,int value)
{ Node *pointer=*head;
if(pointer->data==value)
{
	cout<<" \n this is first ele and it gets deleted\n";
	pointer=pointer->next;
	*head=pointer;
	return;
}
while(pointer->next->next!=NULL&&pointer->next->data!=value)
{ pointer=pointer->next;
}


if(pointer->next->next==NULL)
{ cout<<"\n this is last ele and it gets deleted\n";
pointer->next=NULL;
return ;
}
Node *temp=pointer->next->next;
pointer->next=temp;

}
void printList(Node **head)
{ 	if(*head==NULL) return;
	Node *pointer=*head;
	while(pointer!=NULL)
	{
		cout<<" "<<pointer->data<<" ";
		pointer=pointer->next;
	}
}
int main()
{ int ele,choice;
	Node *head=NULL;
	do
	{
		cout<<"enter ele to insert\n";
		cin>>ele;
		push(&head,ele);
		cout<<"\npress 0 for termination\n";
		cin>>choice;
	}while(choice!=0);
		printList(&head);
	do
	{
	
		cout<<"\nenter ele to delete\n";
		cin>>ele;
		deleteValue(&head,ele);
			printList(&head);
		cout<<"\npress 0 for termination\n";
		cin>>choice;
	}while(choice!=0);
}
