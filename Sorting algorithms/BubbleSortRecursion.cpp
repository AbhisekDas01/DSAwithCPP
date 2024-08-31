#include <iostream>
using namespace std;
void BubbleSort(int arr[], int n)
{
    if (n == 0 || n == 1)
        return;
    // solve one case
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
    BubbleSort(arr, n - 1);
}

void PrintArray(int arr[] , int n );

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    // dynamically creating array
    int *arr = new int[n];
    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Before Sorting : ";
    PrintArray(arr, n);
    // function call
    BubbleSort(arr, n);

    cout << "After Sorting : ";
    PrintArray(arr, n);

    
    // delete the heap space used for array
    delete[] arr;
    return 0;
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