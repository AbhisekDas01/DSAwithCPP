#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> & arr ,int index ,int size)
{
    int large = index;
    int leftIndex = index*2 + 1;
    int rightIndex = index*2 + 2;

    if(leftIndex < size && arr[leftIndex] > arr[large])
    {
        large = leftIndex;
    }
    if(rightIndex < size && arr[rightIndex] > arr[large])
    {
        large = rightIndex;
    }

    if(large != index)
    {
        swap(arr[large] , arr[index]);
        heapify(arr , large , size);
    }
}

void heapSort(vector<int> &arr)
{
    int size = arr.size();

    //build max heap

    for(int i = size/2 -1 ; i >= 0 ; i--)
    {
        heapify(arr,i,size);
    }

    //run a loop form last index to the 0 and swap 0 index with the last and heapify
    for(int i = size-1 ; i > 0 ; i--)
    {
        //swap root with the last index
        swap(arr[0] , arr[i]);

        //heapify rest elements 
        heapify(arr , 0 , i);
    }
}

void printArray(vector <int> & arr)
{
    for(int i = 0 ; i < arr.size() ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr;

    cout << "Enter elements in the array (-1 to stop ) : ";

    while (true)
    {
        int data;
        cin >>data;
        if(data == -1)
        {
            break;
        }
        arr.push_back(data);    
    }

    cout << "Before sorting : ";
    printArray(arr);

    heapSort(arr);

    cout << "After sorting : ";
    printArray(arr);
    
    return 0;
}