#include <stdio.h>

void bubblesort(int ar[],int n)
{
  int c=0;
  for(int i=0;i<n-1;i++)
    {
      int flag=0;
      for(int j=0;j<n-1-i;j++)
        {
          c++;
          if(ar[j]>ar[j+1])
          {
            flag=1;
            int t=ar[j];
            ar[j]=ar[j+1];
            ar[j+1]=t;
          }
        }

      if(flag==0)
        break;
    }

  printf("Total Count = %d",c);
}

int main(void) {

  int ar[5];
  printf("Enter 5 elements\n");
  for(int i=0;i<5;i++)
    {
      scanf("%d",&ar[i]);
    }

  bubblesort(ar, 5);

  printf("\nSorted array\n");

  for(int i=0;i<5;i++)
    {
      printf("%d ",ar[i]);
    }
  return 0;
}