//avl tree implementation
// codeforces not working : 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
   int data;
   struct node *left;
   struct node *right;
   int height;
};

typedef struct node node;
int max(int a,int b)
{
   if(a>b)
   return  a;
   else
   return b;

}

int height(node *root)
{
   if(root==NULL)
   {
      return 0;
   }
   return root->height;
   //return max(height(root->left),height(root->right))+1;
}

node *newNode(int val)
{
   node *temp=(node *)malloc(sizeof(node));
   temp->data=val;
   temp->left=NULL;
   temp->right=NULL;
   temp->height=1;
   return temp;


}

node *rightRotate(node *y)
{
   node *x=y->left;
   node *t2=x->right;
   x->right=y;
   y->left=t2;
   y->height=max(height(y->left),height(y->right))+1;
   x->height=max(height(x->left),height(x->right))+1;
   return x;
}

node *leftRotate(node *x)
{
   node *y=x->right;
   node *t2=y->left;
   y->left=x;
   x->right=t2;
   x->height=max(height(x->left),height(x->right))+1;
   y->height=max(height(y->left),height(y->right))+1;
   return y;
}


node *insertnode(node *root,int key)
{
   if(root==NULL)
   {
      return newNode(key);
   }
   
   if(key<root->data)
   {
      root->left=insertnode(root->left,key);
   }
   else if(key>root->data)
   {
      root->right=insertnode(root->right,key);
   }
   else
   {
      return root;
   }

   root->height=max(height(root->left),height(root->right))+1;
   int balance=height(root->left)-height(root->right);
   
   if(balance>1 && key< root->left->data)
   {
    return rightRotate(root);   //RR rotation
   }
   if(balance<-1 && key> root->right->data)
   {
    return leftRotate(root); //ll rotation

   }

   if(balance>1 && key>root->left->data)
   {//LR rotation
      root->left=leftRotate(root->left);
      return rightRotate(root);
      return rightRotate(root) ;
     // printf("%d",leftRotate(root) ;
   }

   if(balance<-1 && key<root->right->data)
   {//RL Rotation
      root->right=rightRotate(root->right);
      return leftRotate(root);
      return leftRotate(root) ;
     // printf("%d",rightRotate)  
     
   }
  
   return root;
}



void preorder(node *root)
{
   if(root!=NULL)
   {
      printf("%d ",root->data);
      preorder(root->left);
      preorder(root->right); 
   }
}
void subtree(node *root)
{
  if(root == NULL &&  root->left== NULL  || root->right == NULL)
  {
    printf("NA") ;
    
  }
  else
  {
    preorder(root) ;
  }
}

int main()
{
   node *root=NULL;
  int query = 0 ;
  int i = 0 ;
  printf("enter query : ");
  scanf("%d", &query) ;
  char array[10] ;
  while(i!=query)
    {
      int data  ;
      scanf("%s %d",&array[i],&data) ;
      if(strcmp(array,"insert")==0)
      {
        root = insertnode(root,data) ;
        
      }
      else if(strcmp(array , "subtree") ==0)
      {
        subtree(root) ; 
      }
      else 
      {
        printf("\ninvalid instruction") ;
      }
     i++ ; 
      
    }
  
   return 0;
}
