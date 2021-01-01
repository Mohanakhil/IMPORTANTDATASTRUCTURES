//Write a function to get Nth node in a Linked List
//ASSUME THAT INDEX STARTS WITH 0
//o(n)
#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
};
void push(Node **head,int newdata)
{ Node *newnode=new Node();
newnode->data=newdata;
newnode->next=*head;
*head=newnode;	
}
void getNode(Node **head,int n,int count)
{ Node *pointer=*head;
bool flag=false;
if(n>count) 
{ cout<<" this node exceeds count \n";
	return;
}
while(n>0&&pointer!=NULL)
{ pointer=pointer->next;
	n--;
	flag=true;
}
if(n==0) flag=true;
if(flag==false)
{
	cout<<"\nyour required Node is not present\n";
	return ;
}
cout<<"ele at req position= "<<pointer->data<<" ";	
}
void printList(Node **head)
{ Node *pointer=*head;
while(pointer!=NULL)
{
	cout<<" "<<pointer->data<<" ";
	pointer=pointer->next;
}
}
int main()
{
 Node *head=NULL;
 int choice,ele,n,count=0;
 do
 {
 cout<<"enter ele to insert\n";
 cin>>ele;
 push(&head,ele);
 count++;
 cout<<"enter 0 for termination\n";
 cin>>choice;
}while(choice!=0);

do
{ printList(&head);
 cout<<"enter value of index\n";
 cin>>n;
 getNode(&head,n,count);
cout<<"enter 0 for termination\n";
 cin>>choice;
}while(choice!=0);
 
}
