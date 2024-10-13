#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int kthSmallest(vector<int> &arr, int k) {
        
        
        //create a priority queue
        priority_queue<int> pq;
        
        //step->1 push fist k elements in the max heap
        for(int i = 0 ; i < k ; i++)
        {
            pq.push(arr[i]);
        }
        
        //step -> 2 for remaining elements if the value present in the array is small
        //than the value in the max heap then pop the top ans push arr vlue in max heap 
        for(int i = k ; i < arr.size() ; i++)
        {
            if(pq.top() > arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        //at last the pq will only have the k small numbers and the top will be our ans 
        return pq.top();
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

    int k;

    cout << "Array elements : ";
    printArray(arr);

    cout << "Enter the value of K : ";
    cin >> k;
 
    cout << k << "th smallest number is : " << kthSmallest(arr , k);
    
    
    return 0;
}