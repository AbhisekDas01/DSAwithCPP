#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

//find middle of the linked list 
node* findMid(node *head)
{
    node *slow = head;
    node *fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

    }
    return slow;
}

//insert the nodes in sorted order 
void insert(node * &head , node * &tail , node *ptr)
{
    //if list is empty 
    if(head == NULL)
    {
        head = ptr;
        tail= head;
    }
    else
    {
        tail->next = ptr;
        tail = ptr;
    }
}

node *Merge(node *left , node *right)
{
    //if one of the list is empty 
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    
    node *result = NULL;
    node *tail = result;

    while(left != NULL && right != NULL)
    {
        if (left->data <= right->data) {
            insert(result, tail, left);
            left = left->next;
        }
        else{
            insert(result, tail, right);
            right = right->next;
        }
    }

    //if any node left
    while(left != NULL)
    {
        insert(result, tail, left);
        left = left->next;
    }
    while(right != NULL)
    {
        insert(result, tail, right);
        right = right->next;
    }
    return result;
}
node* mergeSort(node *head) {
    
    //base case 
    if(head == NULL || head->next == NULL)
        return head;

    node *mid = findMid(head);

    node *left = head; //first half 
    node *right = mid->next; //2nd half
    mid->next = NULL;

    //sort and merge
    left = mergeSort(left);
    right = mergeSort(right);

    //merge
    node *result = Merge(left , right);

    return result;

}

// Function to print the linked list
void printList(node* node) {
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    // Example of how to create a linked list and call mergeSort
    node *head = new node(5);
    head->next = new node(3);
    head->next->next = new node(8);
    head->next->next->next = new node(2);
    head->next->next->next->next = new node(10);

    cout << "\nBefore sorting : ";
    printList(head);

    // Sorting the linked list
    head = mergeSort(head);

    cout << "\nAfter sorting : ";
    printList(head);

    
    return 0;
}