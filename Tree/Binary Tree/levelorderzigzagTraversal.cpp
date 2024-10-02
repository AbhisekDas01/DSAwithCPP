#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//Binary tree node creation
class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    //constructor to initialise values 
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

//function for creating the tree 
Node *createBinaryTree(Node *root)
{
    int data;
    cin >> data;
    root = new Node(data);

    //if we dont want to store anything in the node then enter -1 to store null
    if(data == -1)
    {
        return NULL;
    }

    //creating  the left Nodes
    cout << "Enter the data for left side of " << data << " : ";
    root->left = createBinaryTree(root->left);

    //creating the ringt nodes 
    cout << "Enter the data for right side of " << data << " : ";
    root->right = createBinaryTree(root->right);

    return root;
}

//level order traversal or breath first traversal
vector <int> zigzag(Node *root)
{
    vector <int> result;

    //if root is NULL 
    if(root == NULL)
        return result;

    bool direction = true; //first it is set to left to right direction

    queue <Node*> q;
    q.push(root);

    while(!q.empty())
    {
        //find the number of elements in each level
        int size = q.size();    

        //create a temp vector to store values of each level
        vector <int> temp(size);

        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();

            //find direction of insertion

            int index = direction ? i : size-i-1; //if direction is true then it will store left to right else right to left

            temp[index]  = curr->data;

            //push the left ans right sub tree of curr to queue
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }

        //chaghe the direction
        direction = !direction;

        //store the values from temp to result
        for(auto i : temp)
            result.push_back(i);
        
    }
    return result;
}



int main()
{
    Node *root = NULL;
    cout << "Enter the data for root node : ";
    root = createBinaryTree(root);
    cout << endl << endl << "Level order display : " << endl;
    vector<int> ans = zigzag(root);
    for(int i = 0 ; i < ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}