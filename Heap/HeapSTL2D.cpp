#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node
{
    public:
    int data;
    int row;
    int col;
};


//user defined comparator
class compare
{
    public:
    bool operator() (Node *a , Node *b)
    {
        //min heap
        return a->data > b->data;

        //max heap
        //return a->data < b->data;
    }
};
int main()
{
    priority_queue<Node* , vector<Node*> , compare> minHeap;
    vector<vector<int>> arr(3,vector<int>(5));

    arr = {{56,34,55,4,7},{45,32,90,6,0},{89,78,322,900,9}};

    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 5 ;j++)
        {
            Node *temp = new Node();
            temp->data = arr[i][j];
            temp->row = i ;
            temp->col = j;
            minHeap.push(temp);
        }
    }


    cout<<minHeap.top()->data;
    minHeap.pop();
    cout<<minHeap.top()->data;
    return 0;
}