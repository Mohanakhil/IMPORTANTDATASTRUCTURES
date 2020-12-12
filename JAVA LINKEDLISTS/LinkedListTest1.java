class LinkedListTest1
{
  static class Node
 { int data;
 Node next;
 Node(int d)
 { data=d;
 next=null;
 }
 }

public static void main(String args[])
{ 

Node head=new Node(1);
Node second=new Node(2);
Node third=new Node(3);
head.next=second;
second.next=third;
third.next=null;
Node pointer=head;
while(pointer!=null)
{ System.out.printf("%d ",pointer.data);
pointer=pointer.next;
}
}
}