#include <iostream>
using namespace std;
void SelectionSort(int arr[],int n )
{
    if(n == 1 || n == 0)
        return;
    int minIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if(arr[minIndex] > arr[i])
            minIndex = i;
    }
    if(minIndex != 0 )
        swap(arr[0] , arr[minIndex]);
    SelectionSort(arr+1,n-1);
    
}
int main()
{
    int arr[5] = {5,4,3,2,1};
    SelectionSort(arr,5);
    for(int i = 0 ; i < 5 ; i++)
        cout << arr[i] << " ";
    return 0;
}