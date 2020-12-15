#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
};
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
        cout<<pointer->data;
        pointer=pointer->next;
    }
}
int main()
{ Node *head=NULL;int choice=0;
cout<<"enter 1 for delete at start\n2-for delete at random postion\n3-delete at last\n";
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
{

}
case 3:
{

}

}

}
