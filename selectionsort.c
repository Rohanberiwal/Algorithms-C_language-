#include<stdio.h>
void swap(int *p,int *q)
{
   int t=*p;
   *p=*q;
   *q=t;
}

void selectionsort(int ar[],int n)
{

int c=0;
int i,j,pos;
int min,t;

//number of passes
for(i=0;i<n-1;i++)
{
   //to find the minimum and its position
   min=ar[i];
   pos=i;

   for(j=i+1;j<n;j++)
   {
      if(ar[j]<min)
      {
         min=ar[j];
         pos=j;

      }
      c++;
   }
   //swap smallest elements with first(ith element)
   /*t=ar[i];
   ar[i]=ar[pos];
   ar[pos]=t;
*/
swap(&ar[i],&ar[pos]);

}

printf("\ntotal number of comparisons Required %d",c);
}


int main()
{
   int ar[10];

   printf("Enter 10 elements\n");
   for(int i=0;i<10;i++)
   {
      scanf("%d",&ar[i]);


   }

   printf("\nOriginal Array\n");
   for(int i=0;i<10;i++)
   {
      printf("%d ",ar[i]);
   }

   selectionsort(ar,10);

   printf("\nSorted Array\n");
   for(int i=0;i<10;i++)
   {
      printf("%d ",ar[i]);
   }


   return 0;
}
