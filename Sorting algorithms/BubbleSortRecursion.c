#include <stdio.h>


//bubble sort 
void bubbleSort(int *arr , int size)
{
    //base case 
    if(size == 0)
        return;
    
    for (int i = 0; i < size-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    
    bubbleSort(arr , size-1);
    
}

void printArray(int * , int );

int main()
{
    int size ,arr[50];
    printf("Enter the size of array : ");
    scanf("%d",&size);

    //input elements 
    printf("Enter %d elements : ",size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("Before sorting : ");
    printArray(arr,size);
    bubbleSort(arr,size);
    printf("\nAfter sorting : ");
    printArray(arr,size);

    return 0;
}


void printArray(int *arr , int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    
}