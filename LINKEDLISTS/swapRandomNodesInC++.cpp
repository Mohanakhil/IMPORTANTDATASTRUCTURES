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
void printList(Node **head)
{
	Node *pointer=*head;
	while(pointer!=NULL)
	{
		cout<<pointer->data<<" ";
		pointer=pointer->next;
	}
	
}
void swapNode(Node **head)
{ int x,y;
	cout<<"enter ele to swap\n";
	cin>>x;
	cin>>y;
if(x==y) 
return;
Node *pointerx=*head;
Node *prevx=NULL;
while(pointerx&&pointerx->data!=x)
{ cout<<pointerx->data<<" ";
prevx=pointerx;
pointerx=pointerx->next;
}
Node *pointery=*head;
Node *prevy=NULL;
while(pointery&&pointery->data!=y)
{
prevy=pointery;
pointery=pointery->next;	
}
if(pointerx==NULL||pointery==NULL)
{
	return;
}
if(prevx!=NULL)
prevx->next=pointery;
else
*head=pointery;
if(prevy!=NULL)
prevy->next=pointerx;
else
*head=pointerx;

Node *temp=pointery->next;
pointery->next=pointerx->next;
pointerx->next=temp;
}	
int main()
{ Node *head=NULL;
	int ele,choice;
	do
	{
		cout<<"enter ele to insert in list\n";
		cin>>ele;
		push(&head,ele);
		cout<<"press 0 for termination\n";
		cin>>choice;	
	}while(choice!=0);
	printList(&head);
	swapNode(&head);
	printList(&head);
}
