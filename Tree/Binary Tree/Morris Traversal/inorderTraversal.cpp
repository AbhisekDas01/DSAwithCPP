//inorder traversal using morris traversal algorithm 

//inorder travesal follows left - root - right
#include <iostream>
#include<vector>
using namespace std;

//Node creation
class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
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

vector<int> morrisTraversal(Node *root)
{
    vector<int> inorder;
    Node *curr = root ;
    //run the loop while curr != NULL
    while(curr)
    {
        //1st case if curr->left == NULL then print curr and move right 
        if(curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        //if curr->left != NULL
        else
        {
            Node *temp = curr->left;
            //move the temp to the right most node
            while(temp->right && temp->right != curr)
            {
                temp = temp->right;
            }

            //case 1 if temp right == NULL then point it to curr 
            if(temp->right == NULL)
            {
                temp->right = curr;
                curr = curr->left; // move the curr to left subtree
            }
            // case 2 if temp->right == curr it means node is already visited ans point temp->right = NULL
            else
            {
                temp->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

void printArray(vector<int> &arr)
{
    for(int i = 0 ; i < arr.size() ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> ans;
    Node *root = NULL;
    cout << "Enter the data for root node : ";
    root = createBinaryTree(root);

    ans = morrisTraversal(root);
    cout << "Inorder travesal : ";
    printArray(ans);
    return 0;
}