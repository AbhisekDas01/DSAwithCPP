#include <iostream>
using namespace std;
int BinarySearch(int *arr , int start , int end , int key)
{
    int mid = start + (end - start)/2;
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
    int arr[10] = {1,2,3,4,5,6,7,8,9,90};
    cout<< BinarySearch(arr,0,9,90);
    return 0;
}