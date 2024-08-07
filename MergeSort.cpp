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
int main()
{
    int arr[9]  = {8,90,7,6,5,4,3,2,1};
    MergeSort(arr,0,8);
    for (int  i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}