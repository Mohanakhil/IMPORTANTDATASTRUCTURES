//DETECT LOOP IN LINKEDLIST USING  2 POINTERS
/*
In this method, two pointers are created, first (always points to head) and last. Each time last pointer moves we calculate no of nodes in between first and last and check whether current no of nodes > previous no of nodes, if yes we proceed by moving last pointer else it means we’ve reached the end of the loop, so we return output accordingly.
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
int calculateLength(Node *first,Node *second)
{ int count=1;
while(first!=second)
{
	count++;
	first=first->next;
}
	return count;
}
void detectLoopUsingLength(Node **head)
{
	Node *second=*head,*first=*head;
	int current=0,prev=0;
	while(second&&second->next)
	{ 
		second=second->next;
		current= calculateLength(first,second);
		cout<<"prev= "<<prev<<"current= "<<current<<"\n";
		if(prev>current)
		{ cout<<"\nTHERE IS A LOOP DETECTED IN LINKED LIST\n";
	
		cout<<"length= "<<++prev;
		return;
		}
		prev=current;
	
	}
}
int main()
{ Node *head=NULL;
int ele,choice;
do
{
	cout<<"enter ele to insert\n";
	cin>>ele;
	push(&head,ele);
	cout<<"press 0 for termination\n";
	cin>>choice;
}while(choice!=0);
printList(&head);
head->next->next->next=head;
detectLoopUsingLength(&head);
	
}

