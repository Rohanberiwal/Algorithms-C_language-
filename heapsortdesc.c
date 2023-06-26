//create max heap

#include<stdio.h>


void heapify(int ar[],int n,int i)
{
   int smallest=i;
   int l=2*i+1;
   int r=2*i+2;

   if(l<n && ar[l]<ar[smallest])
      smallest=l;
   if(r<n && ar[r]<ar[smallest])
      smallest=r;
   if(smallest!=i)
   {
      int temp=ar[i];
      ar[i]=ar[smallest];
      ar[smallest]=temp;
      heapify(ar,n,smallest);
   }
}
void buildMinHeap(int ar[],int n)
{
   for(int i=n/2-1;i>=0;i--)
   {
      heapify(ar,n,i);

   }

}

void heapsort(int ar[],int n)
{
int i;
   buildMinHeap(ar,n);
   
   

   
   
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

//printing sorted array
   printf("\nSorted Array");

for(int i=0;i<n;i++)
{
   printf("%d ",ar[i]);
}

   return 0;
}