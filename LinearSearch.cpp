//linear Search Using Recursion
#include <iostream>
using namespace std;
bool linearSearch(int *arr,int size,int key)
{
    if(arr[0] == key)
        return true;
    if(size == 0 )
        return false;
        
    return linearSearch(arr+1,size-1,key);
}
int main()
{
    int arr[5] = {1,2,4,6,7};
    cout << linearSearch(arr,5,0);
    return 0;
}