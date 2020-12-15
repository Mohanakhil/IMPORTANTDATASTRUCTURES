//CODE FOR DELETING A NODE AS REQUIRED BY USER
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;

};
void push(struct node **head,int newdata)
{
 struct node *newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=newdata;
 newnode->next=*head;
 *head=newnode;
}
void printList(struct node **head)
{
    struct node *pointer=*head;
    printf("\n");
    while(pointer!=NULL)
    {
        printf("%d ",pointer->data);
        pointer=pointer->next;
    }
    printf("\n");
}
void deleteANode(struct node **head,int position)
{ struct node *pointer=*head;
if(position==0)
{
    printf("invalid index\n");
    return ;
}
if(pointer==NULL)
{ printf("list is empty");
    return ;
}
else if(position==1)
{
    printf("press 1 at outer choice because it is first ele\n");
    return ;
}

 if(pointer->next!=NULL)
{
    while(position>1)
{ pointer=pointer->next;
position--;
}}
printf("pointer= %d\n",pointer->data);
if(pointer->next==NULL)
{  printf("\npress 3 at outer choice because it is last element\n");
    return ;
}
printf("pointer= %d",pointer->data);
if(pointer->next!=NULL)
{
pointer->next=pointer->next->next;
free(pointer->next);
}}

void deleteFirstNode(struct node **head)
{struct node *pointer=*head;
     if(pointer==NULL&&pointer->next==NULL) 
{
printf(" list is empty\n");
 
}
else
{
    
    pointer=pointer->next;
    free(head);
    *head=pointer;
    
}
}
void deleteLastNode(struct node **head)
{ struct node *pointer=*head;
     if(pointer==NULL&&pointer->next==NULL) 
{
printf(" list is empty\n");

return ;
}
else 
{
   
    while(pointer->next->next!=NULL)
    {
        pointer=pointer->next;
    }
    pointer->next=NULL;
}

}
int main()
{ int choice=0,element=0;
    struct node *head=NULL;
    do
    { printf("enter ele to insert\n");
    scanf("%d",&element);
    push(&head,element);
    printf("press 0 for termination\n");
    scanf("%d",&choice);
    } while (choice!=0);
    printList(&head);
    printf("linked list created\n");
    //CODE FOR DELETING A NODE FROM BEGIN OF LIST
    do
    { printf("enter 1 for delete at start\n2- for delete at any point\n3- for delete at end\n0 to end\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
    { printf("first node got deleted\n");
     deleteFirstNode(&head);
     if(head!=NULL)
     printList(&head);
     break;
    }
    case 2:
    {  printf("enter node index to delete\n");
    scanf("%d",&choice);
        deleteANode(&head,choice);
        printList(&head);
        break;
    }
    case 3:
    { printf("last element gets deleted\n");
    deleteLastNode(&head);
    if(head!=NULL)
    printList(&head);
    break;
    }
    case 0: break;
    }
    printf("press 0 for termination\n");
    scanf("%d",&choice);
    } while (choice!=0);
    
}