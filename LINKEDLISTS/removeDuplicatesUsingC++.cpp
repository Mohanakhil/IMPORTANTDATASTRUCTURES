//Remove duplicates from an unsorted linked list
//Write a removeDuplicates() function which takes a list and deletes any duplicate nodes from the list. The list is not sorted. 
//For example if the linked list is 12->11->12->21->41->43->21 then removeDuplicates() should convert the list to 12->11->21->41->43.
//METHOD 1 (Using two loops) 
//This is the simple way where two loops are used. Outer loop is used to pick the elements one by one and inner loop compares the picked element with rest of the elements. 
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
void removeDuplicates(Node **head)
{
	Node *first=*head;
	while(first->next!=NULL&&first	)
	{ Node *second=first;
	while(second->next!=NULL)
	{
		if(first->data==second->next->data)
		{ Node *temp=second->next;
		second->next=second->next->next;
		delete(temp);

		}
		else second=second->next;
	}
	first=first->next;
		
	}
}
int main()
{ int ele,choice;
	Node *head=NULL;
	do
	{
		cout<<"enter ele in any order\n";
		cin>>ele;
		push(&head,ele);
		cout<<"press 0 for termination\n";
		cin>>choice;
	}while(choice!=0);
	printList(&head);
	removeDuplicates(&head);
	printList(&head);
}
