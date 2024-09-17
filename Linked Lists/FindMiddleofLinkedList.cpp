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

    cout << "\nList elements : ";
    printList(head);

    // Sorting the linked list
    

    
    int ans = findMid(head)->data;
    cout << "\nMiddle element : " << ans;
    
    return 0;
}