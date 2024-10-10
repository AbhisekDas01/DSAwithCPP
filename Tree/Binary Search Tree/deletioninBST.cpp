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


//deletion function 

Node *deleteFromBST(Node *root , int key)
{
    //base case 
    if(root == NULL)
    {
        return NULL;
    }

    //key is root 
    if(root->data == key)
    {
        //case 1-> if root is a leaf node 
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        //case 2-> if root has only one child 
            //if root has only left child 
        if(root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
            //if root has only right child 
        if(root->right != NULL && root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        //case 3 if root has 2 childs 

        if(root->left != NULL && root->right != NULL)
        {
            //2 ways either find the max element from the left subtree
            //of find the min element from the right subtree
            int max = findMax(root->left)->data;
            root->data = max;
            //delete the replaced node 
            root->left = deleteFromBST(root->left,max);
            return root;
        }
        
    }

    else if(root->data > key)
    {
        root->left = deleteFromBST(root->left,key);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right,key);
        return root;
    }
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