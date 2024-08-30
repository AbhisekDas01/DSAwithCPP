#include <iostream>
#include <vector>
using namespace std;

//binary search 
int BinarySearch(const vector<int> &arr , int key) // const key word is used to prevent array modification 
{
    int start = 0 ; 
    int end = arr.size()-1 ;
    int mid = start +(end - start)/2;

    while (start <= end)
    {
        if(arr[mid] == key )
            return mid ; 
        if(arr[mid] < key)
            start = mid + 1; 
        else
            end = mid - 1; 
        mid = start + (end - start)/2;
    }

    //if element not found 
    return -1;
    
}
int main()
{
    int size, key;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size); // Dynamic array creation 

    // Array input
    cout << "Enter the array elements in increasing order : ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Print array 
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter the element to search: ";
    cin >> key;

    // Function call
    int ans = BinarySearch(arr, key);

    if (ans == -1)
        cout << "Element not found!";
    else
        cout << "Element found at index " << ans;

   
    return 0;
}