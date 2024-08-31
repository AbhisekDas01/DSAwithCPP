#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int> &arr)
{
    int size = arr.size();
     
    for(int i = 0 ; i < size-1 ; i++)
    {
        //if the array is already sorted 
        bool isSorted = true;
        for(int j = 0 ; j < size-i-1 ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                //swap arr[j] , arr[j+1]
                arr[j] = (arr[j] + arr[j+1]) - (arr[j+1] = arr[j]);
                //sort(arr[j] , arr[j+1]);
                isSorted = false;
            }
        }
        if(isSorted)
            break;
    }
}

void printArray(vector<int>&);

int main()
{
    int size ; 
    cout << "Enter the size of the array : ";
    cin >> size;

    //vector creation 
    vector<int> arr(size);

    cout << "Enter " << size << " elements in array : ";
    for(int i = 0 ; i < size ; i++)
    {
        cin >> arr[i];
    }

    cout << "Before Sorting : ";
    printArray(arr);

    BubbleSort(arr);

    cout << "After Sorting : ";
    printArray(arr);
    

    return 0;
}

//print array
void printArray(vector<int> &arr)
{
    for(int i = 0 ; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}