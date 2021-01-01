//Pairwise swap elements of a given linked list
#include<iostream>
using namespace std;
class Node
{ public:
	int data;
	Node *next;
};
void push(Node **head,int newdata)
{ Node *newnode=new Node();
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
void pairwiseSwap(Node **head)
{
	Node *pointer=*head;
	while(pointer&&pointer->next)
	{
		int temp=pointer->data;
		pointer->data=pointer->next->data;
		pointer->next->data=temp;
		pointer=pointer->next->next;
	}
}
int main()
{ int ele,choice;
	Node *head=NULL;
	do
	{
		cout<<"enter ele \n";
		cin>>ele;
		push(&head,ele);
		cout<<"press 0 for termination\n";
		cin>>choice;
	}while(choice!=0);
	printList(&head);
	pairwiseSwap(&head);
	printList(&head);
	
}
