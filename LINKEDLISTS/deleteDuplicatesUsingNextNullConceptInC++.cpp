/*
 Marking visited nodes without modifying the linked list data structure 
In this method, a temporary node is created. The next pointer of each node that is traversed is made to point to this temporary node. This way we are using the next pointer of a node as a flag to indicate whether the node has been traversed or not. Every node is checked to see if the next is pointing to a temporary node or not. In the case of the first node of the loop, the second time we traverse it this condition will be true, hence we find that loop exists. If we come across a node that points to null then loop doesn’t exist.


*/
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
	while(pointer!=NULL)
	{
		cout<<pointer->data<<" ";
		pointer=pointer->next;
	}
}

void detectLoopUsingNext(Node **head)
{ Node *pointer=*head;
Node *temp=new Node();
int count=0;
while(pointer!=NULL)
{
	if(pointer->next==NULL) cout<<"\nlist is empty\n";
	if(pointer->next==temp) 
	{ 
		cout<<" loop is detected\n";
	
		return;
	}
	Node *t=pointer->next;
	pointer->next=temp;
	pointer=t;

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
	cout<<"press 0 for termination\n";
	cin>>choice;
}while(choice!=0);
printList(&head);
head->next->next->next->next=head->next;
detectLoopUsingNext(&head);

}
