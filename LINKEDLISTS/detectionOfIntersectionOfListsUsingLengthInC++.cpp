//WAP TO DETECT INTERSECTION OF 2 LINKED LISTS USING LENGTH CONCEPT
//COUNT THE FIRST LINKED LIST LET COUNT BE n1
//COUNT THE SECOND LINKED LIST AND LET COUNT BE n2
//MODULUS difference of n1 and n2==>n
//NOW TRAVERSE THE BIGGER LIST TILL n and start comparing element addresses
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
{cout<<"new list is\n";
	Node *pointer=*head;
	while(pointer!=NULL)
	{
		cout<<pointer->data<<" ";
		pointer=pointer->next;
	}
}
void detectIntersectionOfListsUsingLength(Node **head1,Node **head2)
{Node *pointer1=*head1,*pointer2=*head2;
int n,n1=0,n2=0;
while(pointer1!=NULL)
{
n1++;
	pointer1=pointer1->next;
}
while(pointer2)
{ n2++;
	pointer2=pointer2->next;
}
cout<<"\ncount of first list is "<<n1;
cout<<"\ncount of second list is"<<n2;
pointer1=*head1;
pointer2=*head2;
if(n1>n2)
{ cout<<"\nfirst list is larger\n";
n=n1-n2;
while(n>0&&pointer1!=NULL)
{
	n--;
	pointer1=pointer1->next;
}
}
cout<<"\npointer1= "<<pointer1->data<<"\n";
if(n2>n1)
{ cout<<"\nsecond list is larger\n";
n=n2-n1;
while(n>0&&pointer2!=NULL)
{
	n--;
	pointer2=pointer2->next;
}

}
cout<<"\npointer2= "<<pointer2->data<<"\n";
while(pointer1&&pointer2)
{
	if(pointer1==pointer2)
	{
		cout<<"\nyes intersection of lists is detected at \n"<<pointer1->data<<"\n";
		return;
	}
	pointer1=pointer1->next;
	pointer2=pointer2->next;
}


}

int main()
{ int ele,choice;
	Node *head1=NULL,*head2=NULL;
do
{
	cout<<"enter ele to insert\n";
	cin>>ele;
	push(&head1,ele);

	cout<<"press 0 for termination\n";
	cin>>choice;
}while(choice!=0);
printList(&head1);
do
{
	cout<<"enter ele to insert\n";
	cin>>ele;
	push(&head2,ele);
	
	cout<<"press 0 for termination\n";
	cin>>choice;
}while(choice!=0);
printList(&head2);

Node *end=head2;
while(end->next!=NULL)
{
	end=end->next;
}
end->next= head1->next->next->next->next;
detectIntersectionOfListsUsingLength(&head1,&head2);
}

