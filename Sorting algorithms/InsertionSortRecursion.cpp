#include <iostream>
using namespace std;

void InsertionSort(int arr[] , int size)
{
    //base case 
    if(size <= 1)
        return;

    //recursive call
    InsertionSort(arr , size-1);


    int key = arr[size-1];
    int j = size - 2;

    while (j>= 0 && arr[j] > key)
    {
        arr[j+1] = arr[j--];
    }
    arr[j+1] = key;

    
    
}

void PrintArray(int *, int);

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
    InsertionSort(arr,n);
    
    cout << "After Sorting : ";
    PrintArray(arr,n);
    //delete the heap space used for array
    delete []arr;
    return 0 ;
}

//for printing the array 
void PrintArray(int arr[] , int n )
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}