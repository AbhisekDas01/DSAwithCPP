#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>&);
void SelectionSort(vector<int> &arr)
{
    for(int i = 0 ; i < arr.size()-1 ; i++)
    {
        int minIndex = i ;
        for(int j = i+1 ; j < arr.size() ; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j ;
            }
        }
        
        //swap the minindex and i
        arr[i] = (arr[i] + arr[minIndex]) - (arr[minIndex] = arr[i]);
        // swap(arr[i] , arr[minIndex]);
    }
}
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

    SelectionSort(arr);

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