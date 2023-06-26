#include <stdio.h>
void binarysearch(int array[],int mid , int nums, int left, int right)
{
    if(array[mid]==nums)
    {
        printf("the number is at %d",mid) ;

    }
    else 
    {
        mid = (left+right)/2 ;
        
        if(array[mid]<nums)
        {
            
            binarysearch(array,mid+1,nums,left , right) ;
    
        }
        else if(array[mid]>nums)
        {
            
            binarysearch(array,mid-1, nums,left,right) ;

        }
        else 
        {
            return 0 ;
        }
    }
    return 0 ; 
}
int main()
{
    int x  ;
    printf("enter  the size for the array ");
    scanf("%d",&x);
    int array[x];
    for(int i = 0 ; i<x ; i++)
    {
        printf("enter the input ");
        scanf("%d",&array[i]);
    }
    int mid , left , right  ;
    left = 0 ; 
    right  = x-1  ;
    mid = (left+right)/2 ;
    int nums; 
    printf("enter the number u wish to find in the array ");
    scanf("%d",&nums);
    binarysearch(array,mid,nums,left,right);
    return 0 ;
}