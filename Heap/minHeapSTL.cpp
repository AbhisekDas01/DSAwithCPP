#include <iostream>
#include <queue>
using namespace std;
int main()
{
    //syntax 
    //priority_queue<data_type , container , greater<int>>
    priority_queue<int , vector<int> , greater<int>> pq;
    pq.push(90);
    cout << pq.top() << endl;
    pq.push(60);
    cout << pq.top() << endl;
    return 0;
}