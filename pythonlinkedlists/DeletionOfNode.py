#DELETE A NODE IN THE LINKED LIST
class Node:
	def __init__(self,data):
		self.data=data
		self.next=None
class LinkedList:
    def __init__(self):
        self.head=None
    def push(self,newdata):
        newnode=Node(newdata)
        newnode.data=newdata
        newnode.next=self.head
        self.head=newnode
    def printList(self):
        temp=self.head
        if(temp==None):
            print("list is empty")
            return 
        print("list is ")
        temp=self.head
        while(temp):
            print("%d" %(temp.data))
            temp=temp.next
    def deleteFirstNode(self):
        temp=self.head
        if(temp==None):
            print("no ele in list")
            return 
        else :
            temp=temp.next
            del(self.head)
            self.head=temp
    def deleteRandomNode(self,position):
        temp=self.head
        if(temp==None ):
            print("NO elements present in list")
            return 
        elif(temp!=None):
            while temp.next!=None and position>2:
                
                temp=temp.next
                position=position-1
            if(temp.next.next==None):
                print("press 1 for last ele")
                return 
            if(temp.next.next!=None):
                temp.next=temp.next.next
                
            
        
        
        
    def deleteLastNode(self):
        temp=self.head
        print("temp= %d" %(temp.data))
        if(temp==None):
            print("list is empty")
        elif(temp.next==None):
            print("press 1 for deletion of first ele")
        else:
            
            while temp.next.next!=None:
                print("now temp is %d" %(temp.data))
                temp=temp.next
            temp.next=None
        
        
        
            
            
            
                
            
            
        
        
list1= LinkedList()
choice=1
while( choice>0):
    print("enter ele to insert")
    element=int(input())
    list1.push(element)
    
    print("press 0 to terminate")
    choice=int(input())
list1.printList()
choice=1
while(choice>0):
    print("press 1 for delete first node\n2- for delete at random node\n3-delete last node\n4-for terminate\n")
    choice=int(input())
    if(choice==1):
        list1.deleteFirstNode()
        list1.printList()
    if(choice==2):
        print("enter index of ele to delete")
        index=int(input())
        if(index==1):
            print("press 1 at starting of menu")
        else:
            list1.deleteRandomNode(index)
        
        list1.printList()
    if(choice==3):
        list1.deleteLastNode()
        list1.printList()
    
    

        
    