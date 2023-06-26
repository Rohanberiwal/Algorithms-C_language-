
#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *left;
   struct node *right;
};
typedef struct node node ;
struct node *root=NULL;
struct node *createTree(struct node *root)
{
   int data;
   printf("enter data:");
   scanf("%d",&data);
   if(data==-1)
   {
      return NULL;
   }
   root=malloc(sizeof(struct node));
   root->data=data;
   printf("\nEnter the data for left of %d",root->data);

   root->left=createTree(root->left);
   printf("\nEnter the data for right of %d",root->data);
   root->right=createTree(root->right);
   return root;
}
void preorder(struct node *root)
{
   if(root==NULL)
   {
      return;
   }
   printf("%d ",root->data); //root node
   preorder(root->left); //left
   preorder(root->right); //rigth


}

void inorder(struct node *root)
{
   if(root==NULL)
   {
      return;
   }
   inorder(root->left);
   printf("%d ",root->data);
   inorder(root->right);

}

void postorder(struct node *root)
{
   if(root==NULL)
   {
      return;
   }
   postorder(root->left);
   postorder(root->right);
   printf("%d ",root->data);
}

int main()
{
   root=createTree(root);
   printf("\nPreorder Traversal\n");
   preorder(root);
   printf("\nInorder Traversal\n");
   inorder(root);
   printf("\nPostorder Traversal\n");
   postorder(root);
   
   return 0;
}