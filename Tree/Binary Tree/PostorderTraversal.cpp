//post order -> left -> right -> root 
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
void postorderTraversal(Node *root){

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left != NULL)
            s1.push(curr->left);
        if (curr->right != NULL)
            s1.push(curr->right);
    }

    // The nodes in s2 will be in reverse postorder, so we can print them in the correct postorder sequence
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    
}

int main()
{
    Node *root = NULL;
    cout << "Enter the data for root node : ";
    root = createBinaryTree(root);

    cout << "postorder travesal : ";
    postorderTraversal(root);
    return 0;
}