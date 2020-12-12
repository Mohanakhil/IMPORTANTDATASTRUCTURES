//WAP TO CREATE LINKED LIST AND SHOW THE ELEMENTS IN LINKEDLIST
#include<iostream>
using namespace std;
class node
{ public:
	int data;
	node *next;
	
};
int main()
{ node *head=NULL;
node *second=NULL;
node *third=NULL;
head =new node();
second =new node();
third =new node();
head->data=1;
head->next=second;
second->data=2;
second->next=third;
third->data=3;
third->next=NULL;
node *pointer=head;
while(pointer!=NULL)
{
	printf("%d ",pointer->data);
pointer=pointer->next;
}
	
}
