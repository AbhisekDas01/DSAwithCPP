#include <iostream>
#include <queue>
using namespace std;
int main()
{
    //syntax 
    //priority_queue<data_type , container , comparision type>
    priority_queue<int , vector<int> , greater<int>> minHeap;
    minHeap.push(90);
    cout << minHeap.top() << endl;
    minHeap.push(60);
    cout << minHeap.top() << endl;
    return 0;
}