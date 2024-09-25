//inorder travesal follows left - root - right
#include <iostream>
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


//inorder traversal 
void inorderTravesal(Node *root){

    //base case 
    if(root == NULL)
        return;
    
    //to print left;
    inorderTravesal(root->left);

    //print root 
    cout << root->data << " ";

    //call for rightside
    inorderTravesal(root->right);
    
}

int main()
{
    Node *root = NULL;
    cout << "Enter the data for root node : ";
    root = createBinaryTree(root);

    cout << "Inorder travesal : ";
    inorderTravesal(root);
    return 0;
}