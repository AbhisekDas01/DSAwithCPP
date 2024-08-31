/*
Given the head of a linked list, reverse the nodes of the list k at a time,
and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes, in the end,
should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
*/

#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int value;
    Node *link;

    // constructor to store the value
    Node(int value)
    {
        this->value = value;
        this->link = NULL;
    }

    // destructor to delete the elements
    ~Node()
    {
        link = NULL;
        cout << "\nDeleted : " << value;
    }
};

class LinkedList
{
    public:
    Node *head;

    public:
    LinkedList()
    {
        head = NULL;
    }

    ~LinkedList()
    {
        cout << "\nClearing memory...";
        while (head != NULL)
        {
            Node *temp = head;
            head = head->link;
            delete temp;
        }
        cout << "\nCleared..\nExited Successfully >> Thank You...";
    }

    private:
    Node *createNode()
    {
        int value;
        cout << "Enter the Element : ";
        cin >> value;
        Node *ptr = new Node(value); // constructor calling with value
        return ptr;
    }

    public:
    // insert end fuction
    void insertEnd()
    {
        Node *ptr = createNode();
        if (head == NULL)
            head = ptr;
        else
        {
            Node *temp = head;
            while (temp->link != NULL)
                temp = temp->link;
            temp->link = ptr;
        }
    }

    //to count number of groups
    int countGroups(Node *temp , int k )
    {
        int count = 0 ;
        while(temp != NULL)
        {
            temp = temp->link;
            count++;
        }

        return count/k;
    }
    //reverse in k groups 
    Node *reverseKgroups(Node *head , int k , int groups)
    {
        //base case
        if(head == NULL)
            return NULL;
        //remaing element after all groups 
        if(groups == 0 || k == 1)
            return head;

        //reverse k elements
        Node *prev = NULL;
        Node *current = head;
        Node *next = NULL;
        int count = 0 ;

        while(current != NULL && count < k)
        {
            next = current->link;
            current->link = prev;
            prev = current;
            current = next;
            count++;
        }

        //recursion
        if(next != NULL)
            head->link = reverseKgroups(next,k,groups-1);
        
        return prev;
    }

    // display function
    void display(Node *head)
    {
        if (head == NULL)
            cout << "No elements!" << endl;
        else
        {
            Node *ptr = head;
            while (ptr != NULL)
            {
                cout << ptr->value << " ";
                ptr = ptr->link;
            }
            cout << endl;
        }
    }
};

int main()
{
    LinkedList list;
    int size;
    cout << "Enter the size of the linked list : ";
    cin >> size;

    //inserting elements
    cout << "Enter " << size << " elements.. " << endl;
    for(int i = 0 ; i < size; i++)
    {
        list.insertEnd();
    }

    int k;
    cout << "Enter the size of the elements in a group < " << size << " : ";
    cin >> k;

    if (k <= 0) {
        cout << "Invalid group size. It must be a positive integer." << endl;
        return 1; //code exited with errors 
    }

    int groups = list.countGroups(list.head , k);

    cout << "\nBefore reversal : ";
    list.display(list.head);

    list.head = list.reverseKgroups(list.head,k,groups);

    cout << "\nAfter reversal : ";
    list.display(list.head);

    return 0;
}