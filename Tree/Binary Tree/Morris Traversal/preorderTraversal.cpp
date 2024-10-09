#include <iostream>
#include <vector>
using namespace std;

// Node creation
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function for creating the tree 
Node* createBinaryTree() {
    int data;
    cin >> data;
    
    // Return NULL if -1 is encountered (no node)
    if (data == -1) return NULL;
    
    Node *root = new Node(data);
    cout << "Enter the data for left side of " << data << ": ";
    root->left = createBinaryTree();
    
    cout << "Enter the data for right side of " << data << ": ";
    root->right = createBinaryTree();
    
    return root;
}

vector<int> morrisTraversal(Node *root) {
    vector<int> preorder;
    Node *curr = root;
    
    while (curr) {
        if (curr->left == NULL) {
            preorder.push_back(curr->data);
            curr = curr->right;
        } 
        else {
            Node *temp = curr->left;
            while (temp->right && temp->right != curr) {
                temp = temp->right;
            }
            
            if (temp->right == NULL) {
                preorder.push_back(curr->data);
                temp->right = curr;  // Create a temporary link
                curr = curr->left;
            } 
            else {
                temp->right = NULL;  // Remove the temporary link
                curr = curr->right;
            }
        }
    }
    
    return preorder;
}

void printArray(const vector<int> &arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    Node *root = NULL;
    cout << "Enter the data for root node: ";
    root = createBinaryTree();

    vector<int> ans = morrisTraversal(root);
    cout << "Preorder traversal: ";
    printArray(ans);

    return 0;
}
