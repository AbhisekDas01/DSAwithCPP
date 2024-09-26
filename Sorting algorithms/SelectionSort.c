#include <stdio.h>


//selection sort
void selectionSort(int *arr , int size)
{
    for (int i = 0; i < size-1; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < size ; j++)
        {
            if(arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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