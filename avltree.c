//avl tree implementation
#include<stdio.h>
#include<stdlib.h>
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
   }

   if(balance<-1 && key<root->right->data)
   {//RL Rotation
      root->right=rightRotate(root->right);
      return leftRotate(root);
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

int main()
{
   node *root=NULL;
   root=insertnode(root,15);
   root=insertnode(root,10);
   root=insertnode(root,5);

 
   preorder(root);
   return 0;
}