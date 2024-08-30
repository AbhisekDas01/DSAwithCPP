#include <iostream>
using namespace std;


void Merge(int arr[] , int start,int end)
{
    int mid = start + (end - start)/2;
    int size1 = mid - start + 1;
    int size2 = end - mid;

    //create 2 temporary array
    int *leftArray = new int[size1];
    int *rightArray= new int[size2];

    // copying the values from main array to the two new arrays 
    
    int mainIndex = start; 
    // main array index starts from start because we passed a part of array form start to end
    
    for (int i = 0; i < size1; i++)
    {
        leftArray[i] = arr[mainIndex++]; //copying the values of left subarray in new array
    }
    // mainIndex = mid+1;
    for (int j = 0; j < size2; j++)
    {
        rightArray[j] = arr[mainIndex++]; //copying the values of right subarray in new array 
    }

    //merge these two sorted array 
    int index1 = 0 , index2 = 0 ;
    mainIndex =  start ;

    while (index1 < size1 && index2 < size2)
    {
        if(leftArray[index1] < rightArray[index2])
            arr[mainIndex++] = leftArray[index1++];

        else
            arr[mainIndex++] = rightArray[index2++];

    }

    //storing the remaining parts 
    while (index1 < size1)
    {
        arr[mainIndex++] = leftArray[index1++]; 
    }
    while(index2 < size2)
    {
        arr[mainIndex++] = rightArray[index2++];
    }
    
    //Deleting the space used by dynamic array (always delete it manually )
    delete [] leftArray;
    delete [] rightArray;
}
void MergeSort(int arr[] , int start, int end)
{
    if(start >= end)
        return;
    int mid = start + (end - start)/2;

    //left subarray sort
    MergeSort(arr,start,mid);
    //right subarray sort 
    MergeSort(arr,mid+1,end);

    //merge the devided parts 
    Merge(arr,start,end);
}

void printArray(int *arr , int size);
int main()
{
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    //array creation 
    int *arr  = new int[size];

    cout << "Enter " << size << " elements : ";
    for(int i = 0 ; i < size ; i++)
    {
        cin >> arr[i];
    }

    cout << "Before sorting  : ";
    printArray(arr,size);

    MergeSort(arr,0,size-1);

    cout << "After sorting : ";
    printArray(arr,size);

    return 0;
}

void printArray(int *arr , int size )
{
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}