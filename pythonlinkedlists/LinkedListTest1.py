#simple program for creation and  traversal of linkedlists
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
class LinkedList:
    def  __init__(self):
        self.head=None
    def printList(self):
        temp=self.head
        while(temp!=None):
            print(temp.data)
            temp=temp.next
if __name__=='__main__':
    mylist=LinkedList()
    mylist.head=Node(1)
    second=Node(2)
    third=Node(3)
    mylist.head.next=second
    second.next=third
    mylist.printList()
    
        
    
 

 
 