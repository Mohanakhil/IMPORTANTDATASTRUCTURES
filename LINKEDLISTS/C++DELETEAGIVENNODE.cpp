//wap to delete nodes in a linkedlist taking index from user
#include<bits/stdc++.h>
using namespace std;
class Node{
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
void deleteFirstNode(Node **head)
{ cout<<"first node is deleted\n";

    Node *pointer=*head;
    if(pointer==NULL&&pointer->next==NULL)
    {
        cout<<"empty list\n";
    }
    else 
    {
      pointer=pointer->next;
      
      *head=pointer;
        
    }
}
void printList(Node **head)
{
    Node *pointer=*head;
    while(pointer!=NULL)
    {
        cout<<pointer->data<<" ";
        pointer=pointer->next;
    }
    cout<<"\n";
}
void deleteRandomNode(Node **head,int position)
{
 Node *pointer=*head;
if(pointer==NULL)
{
    cout<<"list is empty\n";
    return ;
}
if(position==0)
{ cout<<"invalid index";
 return ;
}
if(position==1)
{
    cout<<"please press 1 for start node\n";
    return;
}

if(pointer!=NULL&&pointer->next!=NULL)
{
    while(position>2)
{
    pointer=pointer->next;
    position--;
}
if(pointer->next->next==NULL)
{
    cout<<"please press 3 for last node\n";
    return ;
}
if(pointer!=NULL&&pointer->next!=NULL)
{  cout<<position<<" node is deleted\n";
   pointer->next=pointer->next->next;
    free(pointer->next);
    cout<<"freed garbage value\n";
}
}

}
void deleteLastNode(Node **head)
{ cout<<"last node is deleted\n";

    if((*head)->next==NULL)
    {
    cout<<"list is empty\n";
    *head=NULL;
    return ;
    }
    else 
    { Node *pointer=*head;
    
	 while(pointer->next->next!=NULL)
    {
        pointer=pointer->next;
    }
    
    pointer->next=NULL;

    }
}
int main()
{ Node *head=NULL;int choice=0,element;
do
{
cout<<"enter elements for linked list\n";
cin>>element;
push(&head,element);
cout<<"enter 0 for termination\n";
cin>>choice;
}while(choice!=0);
printList(&head);
do
{
cout<<"enter 1 for delete at start\n2-for delete at random postion\n3-delete at last\n0-for exit\n";
cin>>choice;
switch(choice)
{ case 1:
{
cout<<"first element will be deleted\n";
deleteFirstNode(&head);
printList(&head);
break;
}
case 2:
{ cout<<"enter node index to delete\n";
cin>>choice;
deleteRandomNode(&head,choice);
printList(&head);
break;
}
case 3:
{ deleteLastNode(&head);
printList(&head);
break;
}
cout<<"enter 0 for termination\n";
cin>>choice;
}
}while(choice!=0);
return 0;
}
