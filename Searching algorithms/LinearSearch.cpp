#include <iostream>
using namespace std;

// Linear search function
int LinearSearch(int *arr, int key, int size) { 
    // Key is the search element 
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found 
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
    int ans = LinearSearch(arr, key, size);

    if (ans == -1)
        cout << "Element not found!";
    else
        cout << "Element found at index " << ans;

    // Clearing memory
    delete[] arr;
    return 0;
}
