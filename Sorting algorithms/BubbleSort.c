#include <stdio.h>
#include <stdbool.h>
//bubble sort 
void bubbleSort(int *arr , int size)
{
    for (int i = 0; i < size-1; i++)
    {
        bool isSorted = true;
        for (int j = 0; j < size-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                //swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = false;
            }
            
        }
        if(isSorted)
            return;
    }
    
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