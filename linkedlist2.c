#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>

void printlinkedlist(struct *node head)
{
    while(head!=NULL)
    {
        printf("%d ",->data) ;
        head = head->next
    }
}
struct node
{
    int data  ;
    int key  ;
    struct node  *pnext  ; // pointer to point to the next address of teh linked lit 


}node ;
int main()
{
    struct node *node1 = NULL ;
    struct node *node2 = NULL ;
    struct node *node3 = NULL ;
    node1 = (node*)maclloc(sizeof(node1)) ;
    node2 = (node*)maclloc(sizeof(node2)) ;
    node3 = (node*)maclloc(sizeof(node3)) ;
    node1->data=50 ;
    node1->next = node2 ;
    node2 ->data = 2; // assign data to second node
    node2 ->next = node3;
    node3->data = 2; // assign data to second node
    node3->next = NULL;
    printlinkedlist(node1) ;




    
}

struct Node
{
   int data;
   struct Node *next;
};

struct Node *head=NULL,*tail=NULL,*p;

void addFirst(int x)
{
//firt step (Create a node p)
   struct Node *p;
   p=(struct Node *)malloc(sizeof(struct Node)); //dynamic node
   p->data=x;
   p->next=NULL;
   if(head==NULL)
   {
      head=tail=p;
   }
   else
   {
      p->next=head;
      head=p;
   }


}

void addLast(int x)
{
   struct Node *p;
   p=(struct Node *)malloc(sizeof(struct Node)); //dynamic node
   p->data=x;
   p->next=NULL;
   if(tail==NULL)
   {
      head=tail=p;
   }
   else
   {
      tail->next=p;
      tail=p;
   }
}

void traverse()
{

   printf("\nLinked List\n");  
   struct Node *tmp=head;
   while(tmp!=NULL)
   {
      printf("%d ",tmp->data);      
      tmp=tmp->next;
   }

   
}

int main()
{

   int ch;

   
   while(1)
   {

     printf("\nEnter choice\n1.Add at head\n2.Add at tail\n3.display\n4.Exit\nenter your choice\n");
     scanf("%d",&ch);

     if(ch==1)
     {
      int x;
      printf("Enter value to insert");
      scanf("%d",&x);
      addFirst(x);

     }
     else if(ch==2)
     {
      //add last
      int x;
      printf("Enter value to insert");
      scanf("%d",&x);
      addLast(x);

     }
     else if(ch==3)
     {
      //traverse
      traverse();
     }
     else if(ch==4)
     {
      printf("Exting...");
      break;
     }

   } 
   

   return 0;

   //linked list traversal (visiting every node of the linked list)
}

