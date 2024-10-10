#include <iostream>
using namespace std;

//Node creation 
class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};


//tree creation 

Node *createBST(Node *root , int data)
{
    //base case
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    //conditions 
    if(root->data > data)
        root->left = createBST(root->left , data);
    else
        root->right = createBST(root->right , data);

    return root;
}

void inorderTraversal(Node *root)
{
    //base case
    if(root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);

    cout << root->data << " ";

    inorderTraversal(root->right);
}

void inputData(Node *&root)
{   

    int data;
    do
    {
        cin >> data;
        if(data != -1)
        {
            root = createBST(root , data);
        }
    } while (data != -1);
    
    
}
int main()
{
    Node *root = NULL;
    cout << "Enter the elements (-1 to stop): ";
    inputData(root);

    //print the bst 
    cout << "The inorder traversal : ";
    inorderTraversal(root);
    return 0;
}