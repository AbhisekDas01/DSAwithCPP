#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }

     ~Node(){
        // Recursive destructor - deletes next node first
        if(next != NULL) {
            delete next;  // This will call destructor of next node recursively
        }
    }
};


Node *reverseKplaces(Node *head , int k){

    if(head == nullptr || head->next == nullptr || k == 0) return head;

    //count nodes
    int length = 1;
    Node *tail = head;

    while (tail->next)
    {
        length++;
        tail = tail->next;
    }

    //find actual rotation
    k = k%length;

    //link tail to head to make a circular linked list
    tail->next = head;
    tail = head;

    for(int i = 1 ; i < length - k ; i++){
        tail = tail->next;
    }

    // disconnect the links 
    head = tail->next;
    tail->next = nullptr;

    return head;

    
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;

    cout << "Original Linked List: ";
    printList(head);

    cout << "Rotating by " << k << " places..." << endl;
    head = reverseKplaces(head, k);

    cout << "Rotated Linked List: ";
    printList(head);

    // Clean up memory
    delete head;

    return 0;
}