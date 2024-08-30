#include <iostream>
using namespace std;
void SelectionSort(int arr[],int n )
{
    if(n == 1 || n == 0)
        return;
    int minIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if(arr[minIndex] > arr[i])
            minIndex = i;
    }
    if(minIndex != 0 )
        swap(arr[0] , arr[minIndex]);
    SelectionSort(arr+1,n-1);
    
}
void printArray(int *, int);
int main()
{
    int size ; 
    cout << "Enter the size of the array : ";
    cin >> size ; 

    int *arr = new int[size];

    cout << "Enter " << size << " elements : ";
    for(int i = 0 ; i < size ; i++)
    {
        cin >> arr[i];
    }
    
    cout << "Before Sorting : ";
    printArray(arr,size);

    SelectionSort(arr,size);

    cout << "After Sorting : ";
    printArray(arr,size);

    //delete memory 
    delete [] arr;
    
    return 0;
}

//print array 
void printArray(int *arr, int size)
{
    for(int i = 0 ; i < size ; i++)
        cout << arr[i] << " ";
    cout << endl;
}