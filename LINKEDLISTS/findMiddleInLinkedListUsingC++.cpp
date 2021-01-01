//Given a singly linked list, find the middle of the linked list. For example, if the given linked list is 1->2->3->4->5 then the output should be 3. 
//If there are even nodes, then there would be two middle nodes, we need to print the second middle element. 
//For example, if given linked list is 1->2->3->4->5->6 then output should be 4. 
//using length of linked list concept
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
void findMiddle(Node **head,int count)
{ int half=count/2;
int t=count;
half++;
	Node *pointer=*head;
	if(pointer==NULL) cout<<"\nlist is empty\n";
	while(count>half&&pointer->next!=NULL)
	{
		pointer=pointer->next;
		count--;
	}
	if(t%2==0) pointer=pointer->next;
	cout<<"\nmiddle ele is "<<pointer->data;
}
void printList(Node **head)
{ Node *pointer=*head;
while(pointer!=NULL)
{
	cout<<pointer->data<<" ";
	pointer=pointer->next;
}
}
int main()
{
	Node *head=NULL;
	int choice,ele,count=0;
	do
	{
		cout<<"enter ele to insert\n";
		cin>>ele;
		push(&head,ele);
		count++;
		cout<<"press 0 for termination\n";
		cin>>choice;
	}while(choice!=0);
	printList(&head);
	findMiddle(&head,count);
	
}
