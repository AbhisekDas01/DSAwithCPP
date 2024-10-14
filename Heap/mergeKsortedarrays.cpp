#include <bits/stdc++.h> 
using namespace std;

//custom data type to store the array data row number and col number
class Node
{
public:
    int data;
    int row;
    int col;

    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data; // Min-heap comparator
    }
};

// Function to merge K sorted arrays
vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k)
{
    //syntax priority_queue<data_type , container , comparator> name;
    priority_queue<Node *, vector<Node *>, compare> q;
    vector<int> ans;

    // Step-1: Insert the first elements of each array into the heap
    for (int i = 0; i < k; i++)
    {
        Node *temp = new Node(arr[i][0], i, 0);
        q.push(temp);
    }

    // Step-2: Process the heap to get the sorted result
    while (!q.empty())
    {
        Node *temp = q.top();
        q.pop();
        ans.push_back(temp->data);

        // If the next element exists in the same array, push it into the heap
        if (temp->col + 1 < arr[temp->row].size())
        {
            Node *next = new Node(arr[temp->row][temp->col + 1], temp->row, temp->col + 1);
            q.push(next);
        }
    }
    return ans;
}

int main()
{
    // Driver code to test the function

    // Define K sorted arrays
    vector<vector<int>> arr = {
        {1, 4, 7, 10},
        {2, 5, 8, 11},
        {3, 6, 9, 12}
    };

    int k = arr.size(); // Number of sorted arrays

    // Call the merge function
    vector<int> result = mergeKSortedArrays(arr, k);

    // Print the merged array
    cout << "Merged array: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
