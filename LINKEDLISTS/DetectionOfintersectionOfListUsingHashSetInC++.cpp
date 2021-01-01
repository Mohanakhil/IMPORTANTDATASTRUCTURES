//WAP TO DETECT INTERSECTION OF LINKED LISTS
//SOLUTION
//TRAVERSE THE FIRST LINKED LISTS AND  STORE THE ADDRESS OF VISITED NODEs IN HASHSET
//NOW TRAVERSE THE SECOND LINKED LIST AND IF YOU FIND ADDRESS THAT ALREADY EXISTS IN HASH THEN RETURN NODE
//TIME COMPLEXITY-O(n)
//SPACE COMPLEXITY-O(n)
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node
{	public:
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
void printList(Node **head2)
{
	Node *pointer1=*head2;
	while(pointer1!=NULL)
	{
		cout<<pointer1->data<<" ";
		pointer1=pointer1->next;
	}
}
void detectUsingHashSet(Node **head1,Node **head2)
{ Node *pointer1=*head1;
Node *pointer2=*head2;
	unordered_set<Node *>set1;
	while(pointer1!=NULL)
	{
	set1.insert(pointer1);
	pointer1=pointer1->next;
	}
	while(pointer2!=NULL)
	{
		if(set1.find(pointer2)!=set1.end())
		{
			cout<<"\nintersection of 2 linked lists is detected at "<<pointer2->data;
			return;
		}
		pointer2=pointer2->next;
	}
	
}
int main()
{int ele,choice;
Node *head1=NULL;Node *head2=NULL;
do
{
	cout<<"enter ele\n";
	cin>>ele;
	push(&head1,ele);
	cout<<"press 0 for termination\n";
	cin>>choice;
}while(choice!=0);
printList(&head1);
do
{
	cout<<"enter ele\n";
	cin>>ele;
	push(&head2,ele);
	cout<<"press 0 for termination\n";
	cin>>choice;
}while(choice!=0);
printList(&head2);
Node *end=head2;
while(end->next!=NULL)
{
	end=end->next;
}
end->next=head1->next->next->next;
detectUsingHashSet(&head1,&head2);
	
}
