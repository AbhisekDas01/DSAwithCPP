//this sorting algorithm is applicable when the given numbers in the array of range 1-n
#include <iostream>
#include <vector>
using namespace std;

void cycleSort(vector<int> &arr)
{
    int n = arr.size();

    int index = 0;

    while(index < n)
    {
        if(arr[index] != index+1)
        {
            swap(arr[index] , arr[arr[index]-1]);
        }
        else
            index++;
    }
}

//print array
void printArray(const vector<int> &arr)
{
    for(int i = 0 ; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    vector<int> arr;
    cout << "Enter elements of array (-1 to stop) : ";
    while (true)
    {
        int data;
        cin >> data;
        
        if(data == -1) 
            break;
        arr.push_back(data);
    }

    cout << "Before sorting : ";
    printArray(arr);

    cycleSort(arr);

    cout << "After sorting : ";
    printArray(arr);    
    return 0;
}