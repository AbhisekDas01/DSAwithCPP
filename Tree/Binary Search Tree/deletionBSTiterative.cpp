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


Node * findMax(Node *root )
{
    Node *max = root;

    while (max->right)
    {
        max = max->right;
    }
    
    return max;
}


//deletion function iterative

Node *deleteFromBST(Node *root , int key)
{
    Node *parent = NULL; //it will hold the parent node of the node we are deleting 
    Node *curr = root;

    //step -1 -> find the node to delete
    while(curr != NULL && curr->data != key)
    {
        parent = curr;
        if(curr->data > key)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }

    //if curr == NULL then element not present
    if(curr == NULL)
    {
        cout << "Node not found!" << endl;
        return root;
    }

    //case -1 -> curr node is a leaf node 
    if(curr->left == NULL && curr->right == NULL)
    {
        if(parent == NULL) //if curr node is the root node
        {
            return NULL;
        }
        
        //if curr is on the left side of the parent
        if(parent->left == curr)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }

        delete curr;
    }


    //case -2 -> if curr node has any one child 
    else if(curr->left == NULL || curr->right == NULL)
    {
        Node *child = NULL; //if will hold the child of the curr

        child = (curr->left != NULL)? curr->left : curr->right ; 

        if(parent == NULL)
        {
            root = child;
        }
        else if(parent->left == curr)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
        
        delete curr;
    }


    //case -3 -> if the curr has two childs 
    else if(curr->left != NULL && curr->right != NULL)
    {
        //find max from the left subtree and replace it 
        int max = findMax(curr->left)->data;

        curr->data = max;

        curr->left = deleteFromBST(curr->left,max);
    }

    return root;
}




int main()
{
    Node *root = NULL;
    cout << "Enter the elements (-1 to stop): ";
    inputData(root);

    //print the bst 
    cout << "The inorder traversal Before deletion : ";
    inorderTraversal(root);

    int key;
    cout << "\n\nEnter the element to delete : ";
    cin >> key;
    root = deleteFromBST(root ,key);
   
     //print the bst 
    cout << "The inorder traversal After deletion : ";
    inorderTraversal(root);
    
    return 0;
}