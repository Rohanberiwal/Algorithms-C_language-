#include<stdio.h>
int compare(int ar, int copy, int n )
{
    int counter = 0 ;
    for(int i=0 ; i<n ;i++)
    {
        if(ar[i]!=copy[i])
        {
            counter = counter + 1 ;
            
        }
    }
    return counter  ;
    
}
void merge(int numbers[], int temp[], int left, int mid, int right, int* num_swaps) {
  int i, left_end, num_elements, tmp_pos;
  left_end = mid - 1;
  tmp_pos = left;
  num_elements = right - left + 1;

  while ((left <= left_end) && (mid <= right)) {
    if (numbers[left] <= numbers[mid]) {
      temp[tmp_pos] = numbers[left];
      tmp_pos = tmp_pos + 1;
      left = left +1;
    } else {
      temp[tmp_pos] = numbers[mid];
      tmp_pos = tmp_pos + 1;
      mid = mid + 1;
     
    }
  }

  while (left <= left_end) {
    temp[tmp_pos] = numbers[left];
    left = left + 1;
    tmp_pos = tmp_pos + 1;
  }
  while (mid <= right) {
    temp[tmp_pos] = numbers[mid];
    mid = mid + 1;
    tmp_pos = tmp_pos + 1;
  }

}

void m_sort(int numbers[], int temp[], int left, int right, int* num_swaps) {
  int mid;
  if (right > left)
   {
    mid = (right + left) / 2;
    m_sort(numbers, temp, left, mid, num_swaps);
    m_sort(numbers, temp, mid+1, right, num_swaps);
    merge(numbers, temp, left, mid+1, right, num_swaps);
  }
}

int main() {
  int
  int ar[1000], i, n, ch, t[10], num_swaps = 0;
  printf("\nEnter the number of elements: ");
  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d",&ar[i]);
  }
  int copy[1000]  ;
    for(int i  =0 ; i<n ;  i++)
    {
        copy[i]= ar[i] ;

    }
    for(i=0;i<n;i++) {
    printf("%d\n",copy[i]);
  }
  m_sort(ar,t,0,n-1,&num_swaps);
    int counter  ;

  printf("\nSorted array:\n");
  for(i=0;i<n;i++) {
    printf("%d ",ar[i]);
  }
  compare(ar , copy , n);
  printf("\nNumber of swaps: %d\n",counter);
  return 0;
}
