#include <iostream>
#include <queue>
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
void levelOrderTraversal(Node *root)
{
    if(root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL); // after completetion of the root node it will store NULL the indecate the level

    int level = 0 ; // to count the level number 

    cout << "Level " << level <<" : ";
    while(!q.empty())
    {
        Node *temp = q.front();
        
        q.pop();

        //if temp == NULL then the level is over and create a new node
        if(temp == NULL)
        {
            cout << endl;
            level++;
            if(!q.empty())
            {
                cout << "Level " << level <<" : ";
                q.push(NULL); //store null for next level
            }
        }
        else
        {
            cout << temp->data << " ";
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
    
}



int main()
{
    Node *root = NULL;
    cout << "Enter the data for root node : ";
    root = createBinaryTree(root);
    cout << endl << endl << "Level order display : " << endl;
    levelOrderTraversal(root);
    return 0;
}