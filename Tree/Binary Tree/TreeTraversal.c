#include <stdio.h>
#include <stdlib.h> // Include this for malloc

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

Node *createNode(int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp; // Missing return statement
}

// Function for creating the tree
Node *createBinaryTree(Node *root) {
    int data;
    printf("(-1 for NULL): ");
    scanf("%d", &data);

    // If we don't want to store anything in the node, enter -1 to store NULL
    if (data == -1) {
        return NULL;
    }

    root = createNode(data);

    // Creating the left nodes
    printf("Enter the data for left side of %d ", data);
    root->left = createBinaryTree(root->left);

    // Creating the right nodes
    printf("Enter the data for right side of %d ", data);
    root->right = createBinaryTree(root->right);

    return root;
}

// Inorder Traversal
void inorder(Node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder Traversal
void preorder(Node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(Node *root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    Node *root = NULL;

    // Create the binary tree
    printf("root : ");
    root = createBinaryTree(root);

    // Traversals
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
