#include <stdio.h>

void quickSort(int * , int , int);
int partition(int * , int , int);

//print array
void printArray(int *arr , int size)
{
    int i ;
    for(i = 0 ; i < size ; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    int arr[50] , size ,i;
    printf("Enter the size of the array : ");
    scanf("%d",&size);

    printf("Enter %d elements : ",size);
    for(i = 0 ; i < size ; i++)
        scanf("%d" , &arr[i]);

    printf("Before sorting : ");
    printArray(arr , size);

    quickSort(arr , 0 , size-1);

    printf("After sorting : ");
    printArray(arr , size);

    return 0;
}

void quickSort(int *arr ,int start , int end)
{
    //base case
    if(start >= end)
        return;

    //step -> 1 find pivot
    int pivot = partition(arr , start , end);

    //step -> go to left sub array
    quickSort(arr , start , pivot-1);

    //step -> 2 go to right sub array
    quickSort(arr , pivot+1 ,end);
}

int partition(int *arr ,int start , int end)
{
    int pivot = arr[end];
    int i = start;

    for(int j = start ; j < end ; j++)
    {
        if(arr[j] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    //swap
    int temp = arr[end];
    arr[end] = arr[i];
    arr[i] = temp;
    return i;
}

