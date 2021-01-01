//Pairwise swap elements of a given linked list using recursion
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
{ cout<<"list is\n";
Node *pointer=*head;
while(pointer!=NULL)
{
	cout<<pointer->data<<" ";
	pointer=pointer->next;
}
	
}
void pairwiseRecursiveSwap(Node *head)
{ if(head&&head->next)
	{
		int temp=head->data;
		head->data=head->next->data;
		head->next->data=temp;
		pairwiseRecursiveSwap(head->next->next);
	}
	
}
int main()
{ int ele,choice;
	Node *head=NULL;
	do
	{
		cout<<"enter ele\n";
		cin>>ele;
		push(&head,ele);
		cout<<"press 0 for term\n";
		cin>>choice;
	}while(choice!=0);
	printList(&head);
	pairwiseRecursiveSwap(head);
	printList(&head);
	
}
