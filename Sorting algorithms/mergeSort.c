#include <stdio.h>
#include <stdlib.h>
void Merge(int *arr , int start ,int end)
{
    int mid = start + (end-start)/2;
    int leftSize = mid-start + 1;
    int rightSize = end-mid;

 // Dynamically allocate memory for left and right subarrays
    int *leftArr = (int *)malloc(leftSize * sizeof(int));
    int *rightArr = (int *)malloc(rightSize * sizeof(int));

    int mainIndex = start; //main array index;

    //push elements to left and right arrays 
    for(int i = 0 ; i < leftSize ; i++)
    {
        leftArr[i] = arr[mainIndex++];
    }
    for(int i = 0 ; i < rightSize ; i++)
    {
        rightArr[i] = arr[mainIndex++];
    }

    int leftIndex = 0 ; 
    int rightIndex = 0;
    mainIndex = start;

    //merge 2 sorted arrays into one   
    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if(leftArr[leftIndex] < rightArr[rightIndex])
        {
            arr[mainIndex++] = leftArr[leftIndex++];
        }
        else
        {
            arr[mainIndex++] = rightArr[rightIndex++];
        }
    }

    while (leftIndex < leftSize)
    {
        arr[mainIndex++] = leftArr[leftIndex++];
    }
    
    while(rightIndex < rightSize)
    {
        arr[mainIndex++] = rightArr[rightIndex++];
    }
    
    //free the allocated memory
    free(leftArr);
    free(rightArr);
}
void mergeSort(int *arr , int start , int end)
{
    //base case 
    if(start >= end)
    {
        return;
    }

    //find mid 
    int mid = start + (end-start)/2;

    //sort left part
    mergeSort(arr,start,mid);

    //sort right part
    mergeSort(arr,mid+1, end);

    //merge both parts 
    Merge(arr,start,end);

}

void printArray(int *arr ,int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d " , arr[i]);
    }
    printf("\n");
}   
int main()
{
    int size , arr[100];
    printf("Enter size of the array : ");
    scanf("%d" , &size);
    printf("Enter %d elements : ",size);
    for(int i = 0 ; i < size ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    printf("Before sorting : ");
    printArray(arr,size);
    
    int start = 0; 
    int end = size-1;

    mergeSort(arr ,start ,end);
    printf("After sorting : ");
    printArray(arr,size);
    return 0;
}