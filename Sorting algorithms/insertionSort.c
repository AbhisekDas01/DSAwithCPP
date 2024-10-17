#include <stdio.h>

void insertionSort(int *arr , int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i-1; 
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j--];
        }
        arr[j+1] = key;
    }
    
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
    printf("Enter the size of the array : ");
    scanf("%d" , &size);
    printf("Enter %d elements : ",size);
    for(int i = 0 ; i < size ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    printf("Before sorting : ");
    printArray(arr,size);

    insertionSort(arr,size);

    printf("After sorting : ");
    printArray(arr,size);
    return 0;
}