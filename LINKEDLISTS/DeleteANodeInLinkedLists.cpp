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
{
    Node *pointer=*head;
    if(pointer==NULL&&pointer->next==NULL)
    {
        cout<<"empty list\n";
    }
    else 
    {
      pointer=pointer->next;
      free(head);
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
{  Node *pointer=*head;
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
{
cout<<"after while poiter= "<<pointer->data<<"\n";
    pointer->next=pointer->next->next;
    free(pointer->next);
}
}

}
void deleteLastNode(Node **head)
{ Node *pointer=*head;
cout<<"last ele deleted\n";
    if(*head==NULL)
    cout<<"list is empty\n";
    else 
    { while(pointer->next->next!=NULL)
    {
        pointer=pointer->next;
    }
    cout<<"pointer= "<<pointer->data<<"\n";
    free(pointer->next);
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