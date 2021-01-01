 /*
 Solution 4: Marking visited nodes without modifying the linked list data structure 
In this method, a temporary node is created. The next pointer of each node that is traversed is made to point to this temporary node. This way we are using the next pointer of a node as a flag to indicate whether the node has been traversed or not. Every node is checked to see 
if the next is pointing to a temporary node or not. In the case of the first node of the loop, the second time we traverse it this condition will be true, hence we find that loop exists. If we come across a node that points to null then loop doesn’t exist.
 */
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
 int len(Node **pointer)
 {Node *p=*pointer;
 int count=0;
 	while(p!=NULL)
 	{ count++;
 		p=p->next;
	 }
	 return count;
 }
 void detectLoopUsingNext(Node **head)
 {
 	Node *current=*head;
 	Node *prev=NULL;
 	while(current!=NULL)
 	{prev=current;
 	current=current->next;
 	Node *temp1=prev->next;
	 prev->next=NULL;
	 Node *pointer=current;
	 while(pointer!=NULL)
	 { pointer=pointer->next;
	 	if(pointer->data==prev->data)
	 	{
	 		cout<<"loop is detected inside list\n";
	 		cout<<"prev= "<<prev->data<<"\npointer->data= "<<pointer->data<<" \n";
	 		pointer->next=temp1;
	 		int length=len(&pointer);
	 		cout<<"len is\n"<<++length;
			 return;
		}	 
	 }
	current=current->next; 	
	}
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
	 printList(&head);
	 head->next->next->next->next=head;
	 detectLoopUsingNext(&head);
 }
 
 
 
 
