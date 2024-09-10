#include <iostream>
#include <map>
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

    //approach 1
    Node * detectLoop(Node *ptr)
    {
        map <Node * , bool> visited; //to mark true for already visited node

        while (ptr != NULL)
        {
            if(visited[ptr]) //if visited is already marked true then loop is present 
                return ptr;

            visited[ptr] = true;
            ptr = ptr->link;
        }
        
        return NULL; // if it exit the loop then no cycle present
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

    if(list.detectLoop(list.head) == NULL)
    {
        cout << "No loop present..";
    }
    else
    {
        cout << "Loop present at " << list.detectLoop(list.head)->value << endl;
    }

    // list.display();
    return 0;
}