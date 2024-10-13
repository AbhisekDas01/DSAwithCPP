#include <iostream>
#include <vector>
using namespace std;

class Heapify
{
public:
    int* arr;  // Pointer to dynamically allocate memory for the array
    int size;

    // Constructor to allocate memory for the array and initialize the size
    Heapify(int size)
    {
        this->size = size;
        arr = new int[size + 1]; // We use 1-based indexing, so allocate size + 1
        arr[0] = -1; // Placeholder for the 0th index
    }

    ~Heapify()
    {
        delete []arr;
    }

    // Function to heapify the subtree rooted at index 'index'
    void heapify(int* arr, int index, int size)
    {
        int small = index; // Index of the largest element
        int leftIndex = index * 2;     // Left child
        int rightIndex = index * 2 + 1; // Right child

        // Compare left child with the current smallest element
        if (leftIndex <= size && arr[leftIndex] < arr[small])
        {
            small = leftIndex;
        }
        // Compare right child with the current smallest element
        if (rightIndex <= size && arr[rightIndex] < arr[small])
        {
            small = rightIndex;
        }

        // If the largest is not the root, swap and heapify the affected subtree
        if (small != index)
        {
            swap(arr[small], arr[index]);
            heapify(arr, small, size);
        }
    }

    // Function to print the array elements
    void printArray()
    {
        if (size == 0)
        {
            cout << "No elements!" << endl;
            return;
        }

        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    Heapify h(size);  // Create Heapify object with the given size

    // Input the array elements
    cout << "Enter the array elements: ";
    for (int i = 1; i <= size; i++)
    {
        cin >> h.arr[i];
    }

    // Display the array before heapification
    cout << "Before heapified: ";
    h.printArray();

    // Heapify all non-leaf nodes starting from the middle of the array
    for (int i = size / 2; i > 0; i--)
    {
        h.heapify(h.arr, i, size);
    }

    // Display the array after heapification
    cout << "After heapified: ";
    h.printArray();

    return 0;
}
