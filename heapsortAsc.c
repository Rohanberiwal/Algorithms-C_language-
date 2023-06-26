//create max heap

#include<stdio.h>


void heapify(int ar[],int n,int i)
{
   int largest=i;
   int l=2*i+1;
   int r=2*i+2;

   if(l<n && ar[l]>ar[largest])
      largest=l;
   if(r<n && ar[r]>ar[largest])
      largest=r;
   if(largest!=i)
   {
      int temp=ar[i];
      ar[i]=ar[largest];
      ar[largest]=temp;
      heapify(ar,n,largest);
   }
}
void buildMaxHeap(int ar[],int n)
{
   for(int i=n/2-1;i>=0;i--)
   {
      heapify(ar,n,i);

   }

}


void heapsort(int ar[],int n)
{
int i;
   buildMaxHeap(ar,n);
   
   //for ascending sort 

   
   
   for(i=n-1;i>0;i--)
   {
      int temp=ar[0];
      ar[0]=ar[i];
      ar[i]=temp;
      heapify(ar,i,0);
   }


}

int main()
{
   int ar[]={12,11,5,8,7,6};
   int n=sizeof(ar)/sizeof(ar[0]);
   printf("\nOriginal Array");
   for(int i=0;i<n;i++)
   {
      printf("%d ",ar[i]);
   }

heapsort(ar,n);

printf("\nArray After Sorting\n");
for(int i=0;i<n;i++)
{
   printf("%d ",ar[i]);
}

   return 0;
}