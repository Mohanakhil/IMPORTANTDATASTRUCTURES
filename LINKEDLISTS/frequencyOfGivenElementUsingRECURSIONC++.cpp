//COUNT THE FREQUENCY OF ELE IN LINKED LIST USING RECURSION
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
int countFrequencyRecursively(Node *head,int ele,int count)
{  
if(head==NULL) return count;
if(head->data==ele)
{
	count++;
}
return countFrequencyRecursively(head->next,ele,count);
	

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
	do
	{ 
	printList(&head);
	int ele,count=0;
cout<<"\nenter ele for which freq will be obtained\n";
cin>>ele;
	count=countFrequencyRecursively(head,ele,count);
	cout<<"count of ele  "<<ele<<" is "<<count<<"\n";
		cout<<"press 0 for termination\n";
	cin>>choice;
	}while(choice!=0);
	
}
