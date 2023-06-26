#include<stdio.h>
#include<malloc.h>

struct Node
{
   int data;
   struct Node *next;
};


struct Node * addFirst(struct Node *head)
{

//firt step (Create a node p)
   struct Node *p;

   p=(struct Node *)malloc(sizeof(struct Node)); //dynamic node

   printf("\nEnter the data\n");
   scanf("%d",&p->data);

   p->next=head;

   head=p;

   return head;



}

void traverse(struct Node *tmp)
{

   printf("\nLinked List\n");  

   while(tmp!=NULL)
   {
      printf("%d ",tmp->data);      
      tmp=tmp->next;
   }

   
}

int main()
{
   struct Node N1,N2,N3,N4,*head,*tmp;

   printf("Enter data for node1     :");
   scanf("%d",&N1.data);

   printf("Enter data for node2     :");
   scanf("%d",&N2.data);
   
   printf("Enter data for node3     :");
   scanf("%d",&N3.data);
   
   printf("Enter data for node4     :");
   scanf("%d",&N4.data);
   
   head=&N1;
   N1.next=&N2;
   N2.next=&N3;

   N3.next=&N4;
   N4.next=NULL;

   //-> operator is always used when we are accessing structure members using structure pointer



   traverse(head);

   for(int i=1;i<=10;i++)
   {
   head=addFirst(head);
   }


   traverse(head);


   return 0;

   //linked list traversal (visiting every node of the linked list)
}
