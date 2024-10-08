#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node *link;
        //constructor
        Node(int value)
        {
            this->value = value;
            this->link = NULL;
        }
    
};

class DetectLoop
{
    public:
    Node *head = NULL;

    Node *createNode(int data)
    {
        Node *ptr = new Node(data);
        return ptr;
    }

    //display function
    void display()
    {
        if(head == NULL)
        {
            cout << "No elements!";
            return;
        }

        Node *ptr = head;
        cout << "List elements : ";
        do
        {
            cout << ptr->value << " ";
            ptr = ptr->link;
        } while (ptr != head);
        
    }

    //floyds cycle detection algorithm
    bool floydsCycleDetection(Node *ptr)
    {
        Node *slow = ptr; //slow will move one step at a time
        Node *fast = ptr; //fast will move 2 steps at a time 

        while(slow != NULL && fast != NULL)
        {
            
            
            slow = slow->link;

            fast = fast->link;
            if(fast != NULL)
                fast = fast->link;
                
            if(slow == fast)
                return true; //if fast meets slow 
        }
        return false;
    }
};



int main()
{
    
    DetectLoop list;
    list.head = list.createNode(34);
    list.head->link = list.createNode(56); //inserting second node 
    list.head->link->link = list.createNode(100);
    list.head->link->link->link = list.createNode(90);
    list.head->link->link->link->link = list.createNode(677);
    list.head->link->link->link->link->link = list.head->link->link; //creating a loop at 100

    if(list.floydsCycleDetection(list.head))
        cout << "loop is present..";
    else
        cout << "No loop is present";
    // list.display();
    return 0;
}