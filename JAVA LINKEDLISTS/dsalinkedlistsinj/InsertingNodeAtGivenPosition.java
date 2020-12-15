//WAP TO INSERT A NODE AT GIVEN POSITION
package dsalinkedlistsinj;
import java.util.Scanner;
class Node
{ 
	int data;
	Node next;
	Node(int d)
	{
		data=d;
		next=null;
	}
	static Node pushAtBegin(Node head,int newdata)
	{
		Node newnode=new Node(newdata);
		newnode.data=newdata;
		newnode.next=head;
		head=newnode;
		return head;
		
	}
	static Node pushAtRandom(Node head,int position)
	{ Scanner scan=new Scanner(System.in);
		Node pointer=head;
	if(head==null)
	{head.next=null;
	System.out.println("enter element to be inserted\n");
	int  newdata=scan.nextInt();
	head.data=newdata;
	return head;	
	}
		
		System.out.println("enter element to be inserted\n");
		int  newdata=scan.nextInt();
		while(position>1)
		{
			position--;
			pointer=pointer.next;
			
		}
		Node newnode=new Node(newdata);
		newnode.data=newdata;
		newnode.next=pointer.next;
		pointer.next=newnode;
		
		return head;
	}
	static Node pushAtEnd(Node head,int newdata)
	{ 	Scanner scan=new Scanner(System.in);
		if(head==null)
	{head.next=null;
	System.out.println("enter element to be inserted\n");
	 newdata= scan.nextInt();
	head.data=newdata;
	return head;	
	}
		
		Node newnode=new Node(newdata);
		newnode.data=newdata;
		newnode.next=null;
		Node pointer=head;
		while(pointer.next!=null)
		{
			pointer=pointer.next;
		}
		pointer.next=newnode;
	
		return head;
	}
	static void printList(Node head)
	{ Node pointer=head;
	if(head==null)
	{
	System.out.println("head is null\n");
	return ;
	}
		while(pointer!=null)
		{
			System.out.println(pointer.data);
			pointer=pointer.next;
		}
		System.out.println("list is printed");
	}
	
}
public class InsertingNodeAtGivenPosition {	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
Node head=null;		int choice=0;
		Scanner scan=new Scanner(System.in);
		System.out.println("press 1-for insert at begin\n2-for inserting at random\n3-for insert at end\n0-for exit\n");
		choice=scan.nextInt();
		do
		{
		switch(choice)
		{
		case 1->
		{ System.out.println("enter value to insert\n");
		 choice=scan.nextInt();
		head= Node.pushAtBegin(head,choice);
		Node.printList(head);
		}
		case 2->
		{
			System.out.println("eneter node index after which element  will be inserted\n");
			choice=scan.nextInt();
			head= Node.pushAtRandom(head,choice);
			Node.printList(head);
		}
		case 3->
		{ System.out.println("enter new element\n");
		choice=scan.nextInt();
		head=Node.pushAtEnd(head,choice);
		Node.printList(head);
		}
		
		}
		System.out.println("press 1-for insert at begin\n2-for inserting at random\n3-for insert at end\n0-for exit\n");
		choice=scan.nextInt();
		}while(choice!=0);
		Node.printList(head);
	}

}
