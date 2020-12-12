//wap to add node as required by user
#include<bits/stdc++.h>
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
void insertAfterNode(Node *pointer,int newdata,Node **head)
{ 
Node *newnode=new Node();
newnode->data=newdata;
newnode->next=pointer->next;
pointer->next=newnode;
	
}
void insertAtEnd(Node *pointer,int newdata)
{
	Node *newnode=new Node();
	newnode->data=newdata;
	newnode->next=NULL;
	pointer->next=newnode;
}
void printList(Node *pointer)
{ 
while(pointer!=NULL)
{cout<<pointer->data<<" ";
pointer=pointer->next;
}
	
}
int main()
{ int menu,newelement,choice;
Node *head=NULL;
do
{
	cout<<"enter 1-INSERT AT START\n2-INSERT AFTER GIVEN NODE\n3-INSERT AT END\n";
	cin>>menu;
	switch(menu)
	{ 
		case 1: 
		{ do
		{
		
			cout<<"enter ele you want to enter at begin of list\n";
			cin>>newelement;
			push(&head,newelement);
			cout<<"enter 0 to come out of 1st choice\n";
			cin>>choice;
		
		}while(choice!=0);
		printList(head);
			break;
		}
		case 2:
			{ Node *pointer=head;int node;
			cout<<"enter ele you want to enter after given node \n";
			cin>>newelement;
			 if(pointer==NULL)
				{ cout<<"this is the first element\n";
			
				push(&head,newelement);	
				}
			 else if(pointer!=NULL)
			{ 
			
				do{ cout<<"enter after which node you want to enter assuming node starts with 1\n";
				    cin>>node;
				    if(node!=0)
				    {
					while(node>1)
					{ pointer=pointer->next;
						node--;
					}
					insertAfterNode(pointer,newelement,&head);
				   }
				   else if(node==0)
				   {
				   	push(&head,newelement);
				   }
					cout<<"enter 0 to come out of 2nd choice\n";
					cin>>choice;
				}while(choice!=0);
				
				}
				
			
				printList(head);
				break;
			}
		case 3:
			{
				Node *pointer=head;
				do
				{
					cout<<"enter new ele to insert at end\n";
					cin>>newelement;
					while(pointer->next!=NULL)
					{
						pointer=pointer->next;
						
					}
					insertAtEnd(pointer,newelement);
					cout<<"enter 0 to come out of 2nd choice\n";
					cin>>choice;
				}while(choice!=0);
				printList(head);
				break;
			}
	}
	cout<<"enter 0 to come out of menu  \n";
	cin>>choice;
}while(choice!=0);
}
