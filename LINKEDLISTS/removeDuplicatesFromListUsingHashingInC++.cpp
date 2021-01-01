//METHOD 3 (Use Hashing) 
//We traverse the link list from head to end. For every newly encountered element, we check whether it is in the hash table: if yes, we remove it; otherwise we put it in the hash table.
#include<bits/stdc++.h>
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
void printList(Node **head)
{ cout<<"list is\n";
	Node *pointer=*head;
	while(pointer!=NULL)
	{
		cout<<pointer->data<<" ";
		pointer=pointer->next;
	}
}
void removeDuplicates(Node **head)
{
	Node *pointer=*head,*prev;
	unordered_set<int> s;
	while(pointer!=NULL)
	{
		if(s.find(pointer->data)!=s.end())
		{
			prev->next=pointer->next;
		}
		else
		{
			s.insert(pointer->data);
			prev=pointer;
		}
		pointer=pointer->next;
	}
}
int main()
{  Node *head=NULL;
int ele,choice;

do
{
	cout<<"enter eles in any order\n";
	cin>>ele;
	push(&head,ele);
	cout<<"enter 0 for termination\n";
	cin>>choice;
}while(choice!=0);
printList(&head);
removeDuplicates(&head);
printList(&head);
}
