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
    int pivot = arr[end];
    int i = start;

    for(int j = start ; j < end ; j++){

        if(arr[j] < pivot){
            swap(arr[j] , arr[i++]);
        }
    }
    swap(arr[i]  , arr[end]);

    return i;
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
    cout <<"Enter the array elements : ";
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