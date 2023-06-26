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
     printnode(num) ;
  }
  else if(query==2)
  {
   
    length() ;
    
  }
  
  else if(query==3)
  {
    int k ;
    printf("KthNode ") ;
    scanf("%d",&k) ;
    kthNode(k) ;
    
  }
  else if(query==4)
  {
    int k ;
    printf("KthNode ") ;
    scanf("%d",&k) ; 
    delete(num , k) ;
  
  }
  return 0 ;
}


// code --->2 
#include <stdio.h>
#include<stdlib.h>
void checker(int num , int target , int array[])
{
  int counter ;
  for(int i = 0 ; i<num ; i++)
    {
      for(int j = 0 ;  j<num  ; j++)
        {
          if((array[i] + array[j]) == target)
          {
            printf("\n%d %d ",array[i] , array[j]) ;
            counter ++ ;
          }
          else
            {
              printf("\nnot possible ") ;
              break ;
            }
          }
        
    }
  printf("\n%d",counter);
}


int main()
{
  int num ;
  int target ;
  printf("enter the size") ;
  scanf("%d",&num) ;
  printf("enter target : ") ;
  scanf("%d",&target) ;
  int array[num] ;
  for(int i = 0 ; i<num  ; i++)
    {
      printf("enter data : ");
      scanf("%d",&array[i]) ;
    }
  printf("the array is : ") ;
  for(int i =  0 ; i<num ;  i++)
    {
      printf("%d-->",array[i]) ;
    }
  checker(num ,target, array) ;
}

// code -->3 wrong 
#include <stdio.h>
#include <stdlib.h>
void checkindex(int array , int query)
{
  
}
int main()
{
int size  ;
  int query ;
  printf("enter the array size") ;
  scanf("%d",&size) ;
  printf("enter the querey ")  ;
  scanf("%d",&query) ;
  int array[size] ;
  for(int i = 0 ; i<size ; i++)
    {
      printf("enter data :") ;
      scanf("%d",&array[i]) ;
    }
  for(int i  = 0 ; i<size ; i++)
    {
       printf("%d ",array[i]) ;
    }
  int array_query[size];
for(int i  = 0 ; i<size ; i++)
  {
    printf("enter query :") ;
    scanf("%d ",array_query[i]) ;
  }
  for(int i = 0 ; i<size ; i++)
    {
      printf("%d-->",query) ;
    }
checkindex(array , query) ;
}

// xor operation 
// conversion of int to binaery 

while (temp != NULL) {
        result ^= (temp->data ^ x);
        temp = temp->next;
    }
  


// code 5 

#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <string.h>
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



void delete(int num )
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
void  kthNode()
{
    int k ;
    printf("KthNode ") ;
    scanf("%d",&k) ;
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
  for(int i = 0 ; i<query ; i++)
    {
      char array[20] ; 
      int w ; 
      printf("enter : ") ;
      scanf("%s",array) ;
      scanf("%d",&w) ;
      if(strcmp(array, "Delete")== 0)
      {
        int k ;
    printf("KthNode ") ;
    scanf("%d",&k) ;
        delete(k ) ;
      }
    }
}
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <string.h>
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



void delete(int num , int k )
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
void  kthNode()
{
    int k ;
    printf("KthNode ") ;
    scanf("%d",&k) ;
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
  for(int i = 0 ; i<query ; i++)
    {
      char array[20] ; 
      int w ; 
      printf("enter : ") ;
      scanf("%s",array) ;
      scanf("%d",&w) ;
      if(strcmp(array, "Delete")== 0)
      {
        int k ;
      printf("KthNode ") ;
       scanf("%d",&k) ;
        delete(num , k) ;
      }
    }
}



