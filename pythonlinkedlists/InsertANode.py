#insert a node in linkedlist
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
class LinkedList:
    def __init__(self):
        self.head=None
    def push(self,newdata):
        newnode=Node(newdata)
        newnode.next=self.head
        self.head=newnode
    def printList(self):
        pointer=self.head
        print()
        while(pointer!=None):
            
            print(pointer.data)
            print()
            pointer=pointer.next
    def insertAfter(self,pointer,newdata):
        if pointer is None:
            print("it is null pointer in insertaafter")
            return 
        newnode=Node(newdata)
        newnode.next=pointer.next
        pointer.next=newnode
    def insertAtEnd(self,pointer,newdata):
        if pointer is None:
            print("it is null pointer")
            return 
        newnode=Node(newdata)
        newnode.next=pointer.next
        pointer.next=newnode
    
        
if __name__=='__main__':
    list1=LinkedList()
    menu=1
    choice=1
    
    while(menu!=0):
        if(menu==1):
            choice=1
            while(choice!=0):
                print("enter ele to insert at starting\n")
                element=int(input())
                list1.push(element)
                print("enter 0 for termination of first choice\n")
                choice=int(input())
            list1.printList()
        elif(menu==2):
            choice=1
            while(choice!=0):
                print("enter ele to insert after certain node\n")
                element=int(input())
                print("enter node after which you  want\n")
                n=int(input())
                pointer=list1.head
                while(n>1):
                    n=n-1
                    pointer=pointer.next
                list1.insertAfter(pointer,element)
                print("enter 0 for termination of second choice\n")
                choice=int(input())
            list1.printList()
        elif(menu==3):
            choice=1
            while(choice!=0):
                print("enter ele to insert at last")
                element=int(input())
                pointer=list1.head
                while(pointer.next!=None):
                    pointer=pointer.next
                list1.insertAtEnd(pointer,element)
                print("enter 0 for termination of third choice\n")
                choice=int(input())
            list1.printList()
                
        
        print("enter 1for insert at start\n2-for insert after node\n3-for insert at end\n0-for termination of menu")
        menu=int(input())
    