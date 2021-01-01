//Linked List | Set 3 (Deleting a node)
/*
To delete a node from the linked list, we need to do the following steps. 
1) Find the previous node of the node to be deleted. 
2) Change the next of the previous node. 
3) Free memory for the node to be deleted.
 
*/
//INPUT IS ONLY POSITION OF NODE AND THAT NODE AT THAT POSTION SHOULD BE  DELETED(INDEX STARTS WITH 1)
#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
};
void printList(Node **head)
{
	Node *pointer=*head;
	while(pointer!=NULL)
	{
		cout<<" "<<pointer->data<<" ";
		pointer=pointer->next;
	}
}
void push(Node **head,int newdata)
{
	Node *newnode=new Node();
	newnode->data=newdata;
	newnode->next=*head;
	*head=newnode;
}
void deleteNode(Node **head,int position,int count)
{ Node *pointer=*head;
if(position==1)
{ Node *temp=pointer;
pointer=pointer->next;
*head=pointer;
printList(head);
return ;
}
else if(position==count)
{
	cout<<"last ele is deleted\n";
	Node *pointer=*head;
	while(pointer->next->next!=NULL)
	{pointer=pointer->next;
		
	}
	pointer->next=NULL;
	return ;
}
else if(position>count||position<1)
{
	cout<<"NO SUCH INDEX EXISTS\n";
}
else 
{
while(pointer->next!=NULL&&position>2)
{ pointer=pointer->next;
	position--;
}
pointer->next=pointer->next->next;

printList(head);
}

}
int main()
{ Node *head=NULL;
int choice,ele,position,count=0;
do
{
	cout<<"enter ele to insert in list\n";
	cin>>ele;
	push(&head,ele);
	count++;
	cout<<"press 0 for termination\n";
	cin>>choice;
}while(choice!=0);

do
{ printList(&head);
	cout<<"enter position of node to be  deleted\n";
	cin>>position;
	deleteNode(&head,position,count);
	cout<<"press 0 for termination\n";
	cin>>choice;
}while(choice!=0);

	
}
