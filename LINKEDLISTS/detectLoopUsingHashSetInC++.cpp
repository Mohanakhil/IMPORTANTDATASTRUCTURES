/*
Hashing Approach:
Traverse the list one by one and keep putting the node addresses in a Hash Table. At any point, if NULL is reached then return false and 
if next of current node points to any of the previously stored nodes in Hash then return true. 
filter_none
*/
#include <bits/stdc++.h> 
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
void detectLoopUsingHashing(Node **head)
{
	Node *pointer=*head;
	 unordered_set<Node*> s;
	 while(pointer!=NULL)
	 {
	 	if(s.find(pointer) !=s.end())
	 	{
	 		cout<<"loop is present in linkedlist\n";
	 		return;
		}
		s.insert(pointer);
		pointer=pointer->next;
	 }
	 cout<<"\nloop is not present\n";
}

int main()
{Node *head=NULL;
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
head->next->next->next->next->next=head->next;
detectLoopUsingHashing(&head);
}
