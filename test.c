#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node 
{
int data ;
struct node *next ;
} ;
typedef struct node node ;
node *head = NULL ;
node *tail = NULL ;

void printfunc(int num)
{
  node *temp = head;
  int j= 0;
  while(j!=num)
    {
      printf("%d ",temp->data) ;
      temp = temp->next ;
      j++ ;
    }
  
}
void printout(int num)
{
  node *o  = head ;
  int y = 0 ;
  while(y!=num)
    {
      printf("%d ",o->data) ;
      o = o->next ;
      y++ ;
    }
  
}

static void reverse(struct node** head_ref , int num )
{
	struct node *prev = NULL;
	struct node *current = *head_ref;
	struct node *next = NULL;
	while (current != NULL) {
		// Store next
		next = current->next;

		// Reverse current node's pointer
		current->next = prev;

		// Move pointers one position ahead.
		prev = current;
		current = next;
	}
	*head_ref = prev;
  printout(num) ;
}



void delete(int num , int k)
  {
    int c= 0 ;
  node *f = head  ;
  node *t = tail  ;
  while (f!=NULL)
    {
      c++ ;
      f= f->next ;
    }
 // printf("length : %d",c) ;
  if(k>c)
  {
    printf("-1") ;
  }
  else 
  {
    if(k==0)
    {
      node *front = head ;
      node *del = head ;
      head = front->next ;
      free(del) ;
    }
    else if(k==num)
    {
      node *ls = head  ;
      int kl = 0 ;
      while(kl!=(num-1))
        {
          ls = ls->next ;
          kl++ ;
        }
      node *o = tail  ;
      tail = ls ;
      free(o) ;
      ls->next = NULL ;
    }
    else 
    {
      node *p  = head ;
      int mn =1 ;
      while(mn!=(k-1))
        {
          p=p->next ;
          mn++ ;
        }
      node *nex =  p->next ;
      node *op = nex->next ;
      free(nex) ;
      p->next = op  ;
    }
  }
  printfunc(num-1) ;
    
  }
void  kthNode(int k)
{
  int c= 0 ;
  node *f = head  ;
  node *t = tail  ;
  while (f!=NULL)
    {
      c++ ;
      f= f->next ;
    }

  if(k>c)
  {
    printf("-1") ;
  }
  else 
  {
    node *max = head ;
    int m  = 1;
    while(m!=k)
      {
        max = max->next ;
        m++ ;
      }
    printf("%d ",max->data) ;
    
  }
}
int length()
{
  int count = 0 ;
  node *f = head  ;
  node *t = tail  ;
  while (f!=NULL)
    {
      count = count +1  ;
      f= f->next ;
    }
  printf("%d",count) ;
}

void printnode(int num)
{
  node *temp = head;
  int j= 0;
  if(num==0||head == NULL)
      {
        printf("EMPTY") ;
      }
  else
  {
  while(j!=num)
    {
      printf("%d ",temp->data) ;
      temp = temp->next ;
      j++ ;
    }
  }
}
void create()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  //printf("enter data for node ") ;
  scanf("%d",&ptr->data) ;
  if(head==NULL)
  {
    head = ptr ;
    tail  = ptr ;
  }
  else if (head == tail)
  {
    node *y = tail  ;
    y->next = ptr  ;
   tail = ptr  ;
   // ptr ->next = NULL  ;
  }
  else 
  {
    node *mx = tail  ;
    mx ->next = ptr  ;
    tail = ptr   ;
   // mx ->next=NULL ;
      
  }
}
int main()
{
  int num , query ;
  //printf("enter the length :") ;
  scanf("%d  %d",&num,&query) ;
  //printf("enter the query :") ;
  //scanf("%d",&query) ;
  int i = 0 ;
  while(i!=num)
    {
      create() ;
      i++ ;
    }

  if(query==1)
  {
    node *hj = NULL;
    reverse( &hj, num) ;
  }
  else if(query==2)
  {
     printnode(num) ;
  }
  else if(query==3)
  {
   
    length() ;
    
  }
  
  else if(query==4)
  {
    int k ;
    //printf("enter the k value :") ;
    scanf("%d",&k) ;
    kthNode(k) ;
    
  }
  else if(query==5)
  {
    int k ;
    //printf("enter the k value :") ;
    scanf("%d",&k) ; 
    delete(num , k) ;
  
  }
  return 0 ;
}