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
        temp=self.head
        if(temp==None):
            print("list is empty")
            return 
        else:
            while(temp!=None):
                print(temp.data)
                temp=temp.next
    
    def removeElement(self,element):
        prev=self.head
        current=self.head.next
        if(prev.data==element):
            
            print("element is first ele and it is found and deleted\n")
            print(prev.data)
            self.head=prev.next
            return 
        while current.next!=None:
            if(current.data==element):
                print("ele is found and deleted and ele= %d " %(current.data))
                prev.next=current.next
                del(current)
                return
            current=current.next
            prev=prev.next
            
        if(current.next==None):
            print("ele is found and deleted and ele=%d" %(current.data))
            del(current)
            prev.next=None
            return 
            
       
        
  
        
        
        
    
list1=LinkedList()
choice=1


while(choice!=0):
    print("enter ele to insert  \n")
    choice=int(input())
    list1.push(choice)
    print("enter 0 for termination\n")
    choice=int(input("\n"))
    print("\n")
list1.printList()
choice=1
while(choice!=0):
    print("enter ele to remove")
    choice=int(input())
    list1.removeElement(choice)
    print("ele after delting are")
    list1.printList()
    print("press 0 for termination and any other key for continue...")
    choice=int(input("\n"))
    
    print("\n")


    
    
    