//linear Search Using Recursion
#include <iostream>
using namespace std;
int linearSearch(int *arr,int size,int key , int index)
{
    //if size = 0
    if(size == 0 )
        return -1;
    //if element found 
    if(arr[0] == key)
        return index;

    

    //recursive call  
    return linearSearch(arr+1,size-1,key,index+1);
}
int main()
{
        int size, key;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size]; // Dynamic array creation 

    // Array input
    cout << "Enter the array elements: ";
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
    int ans = linearSearch(arr,size ,key,0);

    if (ans == -1)
        cout << "Element not found!";
    else
        cout << "Element found at index " << ans;

    // Clearing memory
    delete[] arr;
    return 0;
}