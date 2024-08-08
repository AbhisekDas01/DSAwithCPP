#include <iostream>
using namespace std ;

//for printing the array 
void PrintArray(int arr[] , int n )
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//partion
int Partion(int arr[] , int start , int end )
{
    int pivot  = arr[start]; // taking the first element as pivot 

    int count = 0 ; // it will count the number of elements smaller  than and equal to pivot 

    //place the pivot element in its right place 
    for (int i = start + 1 ; i <= end; i++)
    {
        if(arr[i] <= pivot )
            count++;
    }

    //the correct index of the pivot value 
    int pivotIndex = start + count;

    //swapping the pivot value 
    swap(arr[pivotIndex] , arr[start]);

    /*
    place all the elements smaller than pivot before it and all element greater than pivot after it
    */
    
    int i = start , j = end;
    while (i < pivotIndex &&  pivotIndex < j )
    {
        if(arr[i] <= pivot)
            i++;
        if(arr[j] > pivot)
            j--;
        if(i < pivotIndex &&  pivotIndex < j )
            swap(arr[i] , arr[j]);
    }
    
    return pivotIndex;
}
void QuickSort(int arr[] , int start , int end )
{
    if(start >= end )
        return ;
    
    int p = Partion(arr,start , end);

    //sorting left subarray 
    QuickSort(arr,start,p-1);

    //sorting right subarray
    QuickSort(arr,p+1,end);
}
int main()
{
    int n ;
    cout << "Enter the size of the array : ";
    cin >> n ; 
    //dynamically creating array 
    int *arr = new int[n];
    cout <<"Enter the array elements : " <<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Before Sorting : ";
    PrintArray(arr,n);
    //function call 
    QuickSort(arr,0,n-1);
    
    cout << "After Sorting : ";
    PrintArray(arr,n);
    //delete the heap space used for array
    delete []arr;
    return 0;
}