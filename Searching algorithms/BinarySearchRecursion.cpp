#include <iostream>
#include <vector>
using namespace std;
int BinarySearch(const vector<int> &arr , int start , int end , int key)
{
    int mid = start + (end - start)/2;
    //base case
    if(start > end)
        return -1;
    if(arr[mid] == key)
        return mid;
        
    if(arr[mid] > key)
        return BinarySearch(arr,start,mid-1,key);
    else
        return BinarySearch(arr,mid+1,end,key);
}
int main()
{
    int size, key;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size); 

    cout << "Enter the array elements in increasing order : ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter the element to search: ";
    cin >> key;

    int start = 0 ;
    int end = arr.size() - 1 ;
    int ans = BinarySearch(arr,start,end,key);

    if (ans == -1)
        cout << "Element not found!";
    else
        cout << "Element found at index " << ans;
    return 0;
}