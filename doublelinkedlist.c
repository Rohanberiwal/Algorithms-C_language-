#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
struct Node
{

   int data;
   struct Node *next;
   struct Node *prev;

};

typedef struct Node NODE;

NODE *head = NULL;
NODE *tail=NULL;

void insertFirst(int data)
{
    NODE *p = (NODE*)malloc(sizeof(NODE));
    p->data = data;
    p->next=NULL;
    p->prev=NULL;

    if(head==NULL)
    {
        head=tail=p;
    }
    else
    {
        p->next=head;
        head->prev=p;
        head=p;
    }
}

   void deleteFirst()
    {
               if(head==NULL)
               {
                  printf("list empty");
               }
               else if(head==tail)
               {
                  printf("\nNode deleted = %d ",head->data);
                  free(head);
                  head=tail=NULL;

               }
               else
               {   NODE *p=head;
                  printf("\nNode deleted = %d ",p->data);
                  head=head->next;
                  head->prev=NULL;
                  free(p);
                  
               }

    }


void insertLast(int data)
{
    NODE *p = (NODE*)malloc(sizeof(NODE));
    p->data = data;
    p->next = NULL;
    p->prev = NULL;
    if(head == NULL)
    {
   head=tail=p;     
    }
    else
    {
        tail->next=p;
        p->prev=tail;
        tail=p;
    }
}
   void deletelast()
    {
               if(head==NULL)
               {
                  printf("list empty");
               }
               else if(head==tail)
               {
                  printf("\nNode deleted = %d ",head->data);
                  free(head);
                  head=tail=NULL;

               }
             
               else
               {
                   NODE *p = tail ;
                   tail = tail->prev ;
                   printf("\nthe deleted node : %d", p->data) ;
                   
                   free(p) ;
                   tail->next= NULL ;   
                   
               }

    }


void ftraverse()
{
    NODE *p = head;
    printf("\nForward Linked List\n");
    while(p!=NULL)
    {
      printf("%d ",p->data);
      p=p->next;
    }
}

void btraverse()
{
   NODE *p=tail;
   printf("\nBackward Linked List\n");
   while(p!=NULL)
   {
       printf("%d ",p->data);
       p=p->prev;
   }

}

void insertatany(int counter)
{
    NODE *ptr = (NODE*)malloc(sizeof(NODE)) ;
    printf("enter the data for the new node :") ;
    scanf("%d",&ptr->data)  ;
    ptr->next = NULL ;
    ptr->prev  = NULL ;
    
    NODE  *p=head  ;
    int x = counter/2 ;
    int i = 0 ; 
    while(i!=(x-1))
    {
        p= p->next ;
         i++ ;
    }
    ptr->next = p->next ;
    p->next->prev = ptr  ;
    p->next = ptr ;
    ptr->prev = p  ;
    ptr = ptr->next ;

    
}
// delete at the mid 
void deleteatmid(int count)
{
    NODE *p=head ;
    int z  = count/2 ;
    int i =1 ;
    while(i!=z)
    {
        
        p = p->next ;
        i++ ;
    }
    printf("\nthe deleted node is %d",p->data) ;
    
    p->prev->next = p->next ;
    
    free(p) ;
}

int nodecounter()
{
    int counter  ;
    counter= 0;
    NODE *p= head;
    while(p!=NULL)
    {
        
        counter = counter +1  ;
        p=p->next ;
        
    }
    return counter  ;
    
}


int main()
{

int ch;

int counter =0 ;
while(ch!=9)
{
printf("\nSelect Doubly operation\n1.Add First\n2.Add Last\n3.forward\n4.backward\n5.Deletion First\n6.deletelast\n7.node coutner\n8.insertion in betwenn\n9.Exit\n10.delete at the mid \nenter your choice");
scanf("%d",&ch);
if(ch==1)
{
    int data;
    printf("Enter data");
    scanf("%d",&data);
    insertFirst(data);
}
else if(ch==2)
{
    int data;
    printf("Enter data");
    scanf("%d",&data);
    insertLast(data);

}
else if(ch==3)
{
    ftraverse();

}
else if(ch==4)
{
    btraverse();
}
else if(ch==5)
{
   deleteFirst();
}
else if(ch==6)
{
    deletelast() ;
    
}

else if(ch==7)
{
     nodecounter() ;
    
}
else if(ch==8)
{
   
    counter = nodecounter() ;
    insertatany(counter) ;
    
}
else if(ch==10)
{
    int count  ;
    
    count = nodecounter() ;
    
    deleteatmid(count) ;
    
}
else if(ch==9)
{
   printf("Exting..");
   break;    
}
}


   return 0;
}