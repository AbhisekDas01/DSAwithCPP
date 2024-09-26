#include <stdio.h>


//selection sort
void selectionSort(int *arr , int size)
{

    //base case
    if (size == 0)
    {
        return;
    }
    
    int minIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if(arr[minIndex] > arr[i])
            minIndex = i;
    }
    
    //swap 
    int temp = arr[minIndex];
    arr[minIndex] = arr[0];
    arr[0] = temp;

    //recursive call
    selectionSort(arr+1 , size-1);
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
    selectionSort(arr,size);
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