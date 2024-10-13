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
            if(arr[parent] < arr[index])
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
            cout << "No elements!" << endl;
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
            int large = index; //it will hold the largest value
            int leftIndex = index*2;
            int rightIndex = index*2 +1;

            if(leftIndex <= size && arr[large] < arr[leftIndex] )
            {
                large = leftIndex;
            }
            if(rightIndex <= size && arr[large] < arr[rightIndex])
            {
                large = rightIndex;
            }

            //swap if root is not large
            if(large != index)
            {
                swap(arr[large] , arr[index]);
                index = large;
            }
            else
            {
                return;
            }
        }
        
    }
    void printArray()
    {
        if(size == 0)
        {
            cout << "No elements!" << endl;
            return;
        }
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
    cout << "Enter the operation : " << endl;
    cout << "\n1.insert()\n2.delete()\n3.display()\n4.exit()" << endl;
    int ch;
    do
    {
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int data;
            cout << "Enter the element : "; 
            cin >> data;
            h.insert(data);
            break;

        case 2:
            h.deleteHeap();
            break;
        case 3:
            h.printArray();
            break;
        case 4:
            cout << "Exiting...";
            break;
        
        default:
            cout << "invalid choice!" << endl;            break;
        }
    } while (ch!=4);
    
    return 0;
}