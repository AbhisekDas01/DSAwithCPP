#include <iostream>
using namespace std;

//for printing the array 
void PrintArray(int arr[] , int n )
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void InsertionSort(int arr[] , int n)
{
    //first we take that 1st element of the array is sorted so we start the comparision form 1 
    
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i -1; //we will compare the previos elements form the i if we find any greater value then we will shift the value 

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j--];

        }
        // arr[j] < key the the key will placed at j+1;
        arr[j+1] = key;
    }
    
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
    InsertionSort(arr,n);
    
    cout << "After Sorting : ";
    PrintArray(arr,n);
    //delete the heap space used for array
    delete []arr;
    return 0 ;
}