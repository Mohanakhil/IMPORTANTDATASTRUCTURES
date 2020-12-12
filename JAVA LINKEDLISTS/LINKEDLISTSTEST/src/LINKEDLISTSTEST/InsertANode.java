package LINKEDLISTSTEST;
import java.util.Scanner;
public class InsertANode 
{ 
static class Node
{
	int data;
	Node next;
Node(int d)
{
		data=d;
       	next=null;	
}	
}
public static void  printList(Node head)
{ Node pointer=head;
	while(pointer!=null)
	{ System.out.println(pointer.data);
		pointer=pointer.next;
	}
}
public static Node push(Node head,int newdata)
{Node newnode=new Node(newdata);
newnode.data=newdata;
newnode.next=head;
head=newnode;
return head;
}
public static void insertAfter(Node pointer,int newdata,Node head)
{Node newnode=new Node(newdata);
if(pointer==null)
{
	System.out.println("no previous ele present");
	
}

newnode.data=newdata;
newnode.next=pointer.next;
pointer.next=newnode;


}
public static void insertAtEnd(Node pointer,int newdata)
{ 
	if(pointer==null)
	{ System.out.println("this is first ele to given");
		push(pointer,newdata);
		return;
	}
	Node newnode=new Node(newdata);
	newnode.data=newdata;
	newnode.next=null;
	pointer.next=newnode;
}
public static void main(String[] args) 
{ Scanner scan=new Scanner(System.in);
byte choice=1;
int node=0;Node head=null;
do
{
	System.out.println("enter 1-for insert at start\n2-for insert after certain node\n3-for insert at end");
byte menu= scan.nextByte();
int element;

switch(menu)
{
case 1-> {
	do
	{
	System.out.println("enter ele to enter at begin");
	element=scan.nextInt();
	head= push(head,element);
	System.out.println("eneter 0 for coming out of first choice");
	choice=scan.nextByte();
	
}while(choice!=0);

InsertANode.printList(head);
}
case 2->
{Node pointer=head;
System.out.println("enter ele you want to insert after given node");
element=scan.nextInt();
if(pointer==null)
{ System.out.println("this is first element");

head= push(head,element);
InsertANode.printList(head);
}
else
{
	do
	{
		
		System.out.println("enter node after which ele is to be  inserted");
		node=scan.nextInt();
		if(node!=0)
		{
		while(node>1)
		{ pointer=pointer.next;
			node--;
		}
	insertAfter(pointer,element,head);
		}
		else if(node==0)
		{ 
			head= push(head,element);
		}
	System.out.println("eneter 0 for coming out of first choice");
	choice=scan.nextByte();
	}while(choice!=0);
	InsertANode.printList(head);
}}
case 3->
{ Node pointer=head;
	do
	{
		System.out.println("enter ele you want to insert at last of list");
		element=scan.nextInt();
		while(pointer.next!=null)
		{
			pointer=pointer.next;
		}
		insertAtEnd(pointer,element);
		System.out.println("eneter 0 for coming out of first choice");
		choice=scan.nextByte();
	}while(choice!=0);
	InsertANode.printList(head);
}
}
System.out.println("enter 0 to come out of menu");
choice =scan.nextByte();
}while(choice!=0);

}
}
