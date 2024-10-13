//priority queue STL to use max heap
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> pq;
    pq.push(78);
    pq.push(90);
    cout << "Largest : " << pq.top() << endl;
    pq.push(100);
    cout << "Largest : " << pq.top() << endl;
    pq.pop();
    cout << "Largest : " << pq.top() << endl;
    return 0;
}