/*
Problem statement
You are given two sorted linked lists. You have to merge them to produce a combined sorted linked list. You need to return the head of the final linked list.

Note:

The given linked lists may or may not be null.
For example:

If the first list is: 1 -> 4 -> 5 -> NULL and the second list is: 2 -> 3 -> 5 -> NULL

The final list would be: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> NULL
*/
#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data  = data;
        this->next = NULL;
    }
};


Node* Merge(Node* first, Node* second)
{
    //if(the first node only havae one element)
    if(first->next == NULL)
    {
        first->next = second;
        return first;
    }
    //other cases
    Node *curr1 = first;
    Node *next1 = first->next;

    Node *curr2 = second;
    Node *next2;

    while(next1 != NULL && curr2 != NULL)
    {
        //if the curr2 fits within the window
        if((curr2->data >= curr1->data) && (curr2->data < next1->data))
        {
            //linking values
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            //new assignment 
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;
        }

        
        
    }
    //if the first linked list gets overd 
    if(next1 == NULL)
    {
        curr1->next = curr2;
    }
    return first;

}
Node* sortTwoLists(Node* first, Node* second)
{
    Node *ans;
    //if one of the ll is null
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;
    
    if(first->data <= second->data)
        ans =  Merge(first,second);
    else
        ans =Merge(second , first);
    
    return ans;
}


// Function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    // Create first sorted linked list: 1 -> 4 -> 5 -> NULL
    Node* first = new Node(1);
    first->next = new Node(4);
    first->next->next = new Node(5);

    // Create second sorted linked list: 2 -> 3 -> 5 -> NULL
    Node* second = new Node(2);
    second->next = new Node(3);
    second->next->next = new Node(5);

    cout << "\nList 1  : ";
    printList(first);
    cout << "\nList 2  : ";
    printList(second);


    // Merge the lists
    Node* mergedList = sortTwoLists(first, second);

    // Print the merged list
    cout << "\nMerged List : ";   
    printList(mergedList);

    return 0;
}

    