#include <iostream>
using namespace std;

class Heap
{
    public:
    int arr[100];
    int size;

    Heap()
    {
        size = 0;
        arr[0] = -1;
    }


    void insert(int data)
    {
        int index = ++size;

        arr[index] = data;

        while(index > 1)
        {
            int parent = index/2;
            if(arr[parent] > arr[index])
            {
                swap(arr[parent] , arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }


    void deleteHeap()
    {
        if(size == 0)
        {
            cout << "No elements!";
            return;
        }

        //step-1 ->> put the last element in first index
        arr[1] = arr[size];

        //step-2 ->> delete the last node
        size--;

        //step-3 ->> heapify the root

        int index = 1;
        while (index < size)
        {
            int small = index; //it will hold the small value
            int leftIndex = index*2;
            int rightIndex = index*2 +1;

            if(leftIndex <= size && arr[small] > arr[leftIndex] )
            {
                small = leftIndex;
            }
            if(rightIndex <= size && arr[small] > arr[rightIndex])
            {
                small = rightIndex;
            }

            //swap if root is not large
            if(small != index)
            {
                swap(arr[small] , arr[index]);
                index = small;
            }
            else
            {
                return;
            }
        }
        
    }
    void printArray()
    {
        cout << "Heap elements : ";
        for(int i = 1; i <= size ; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    Heap h;
    h.insert(10);
    h.insert(30);
    h.insert(50);
    h.insert(20);
    h.printArray();
    h.deleteHeap();
    h.printArray();
    h.insert(7);
    h.insert(89);
    h.insert(79);
    h.printArray();
    h.deleteHeap();
    h.printArray();
    h.deleteHeap();
    h.printArray();
    return 0;
}