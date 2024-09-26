//inorder travesal follows left - root - right
#include <iostream>
#include <stack>
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

    stack<Node*> s;

    Node *curr = root;

    while(curr!= NULL || !s.empty())
    {
        //the order is = left -> root -> right 
        //for left call
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        //step 2 print 
        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        //call for right
        curr = curr->right;
        
    }
    
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