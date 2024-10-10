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






//search function recursive;
bool searchInBST(Node *root , int key)
{
    //base case
    if(root == NULL)
    {
        return false;
    }
    if(root->data == key)
    {
        return true;
    }

    if(root->data > key)
    {
        return searchInBST(root->left , key);
    }
    else
    {
        return searchInBST(root->right , key);
    }
}


//search function non recursive
bool searchINBST(Node *root , int key)
{
    Node *curr = root;
    while(curr)
    {
        if(curr->data == key)
            return true;
        if(curr->data > key)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return false;
}

int main()
{
    Node *root = NULL;
    cout << "Enter the elements (-1 to stop): ";
    inputData(root);

    //print the bst 
    cout << "The inorder traversal : ";
    inorderTraversal(root);

    int key;
    cout << "\nEnter the search element : ";
    cin >> key;

    if(searchINBST(root , key))
    {
        cout << "\nElement present";
    }
    else
    {
        cout << "\nElement not present";
    }
    return 0;
}