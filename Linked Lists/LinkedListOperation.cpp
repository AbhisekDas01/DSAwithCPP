//linked list operation 
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

// to perform linked list operations
class LinkedList
{
private:
    Node *head;
    int size; // to store the size of the linked list

public:
    // constructor
    LinkedList()
    {
        head = NULL; // to initialise the head to nuLL
        size = 0;
    }

    // Destuctor to delete all nodes after completion of the program
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

    // insert fuction
    private:
    Node *createNode()
    {
        int value;
        cout << "Enter the Element : ";
        cin >> value;
        Node *ptr = new Node(value); // constructor calling with value
        return ptr;
    }

    // Insert Begin function
    public:
    void insertBegin()
    {
        Node *ptr = createNode(); // to store the address of the allocated memory
        if (head == NULL)
            head = ptr; // if list is empty
        else
        {
            ptr->link = head;
            head = ptr;
        }
        this->size++;
        cout << "Inserted At Begin..";
    }

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
        this->size++;
        cout << "Inserted At End..";
    }

    // insert At specific position
    void insertAtpos()
    {
        int pos;
        cout << "Enter the position between 1 to " << size + 1 << " : ";
        cin >> pos;

        if (pos < 1 || pos > size + 1)
            cout << "Invalid position! ";
        else
        {
            if (pos == 1)
                insertBegin();
            else if (pos == size + 1)
                insertEnd();
            else
            {

                Node *temp = head, *ptr = createNode();
                for (int i = 1; i < pos - 1; i++, temp = temp->link); // to go to the position
                ptr->link = temp->link;
                temp->link = ptr;
                this->size++;
                printf("Inserted at %dth postion..",pos);
            }
        }
    }

    // delete at Begining
    void deleteBegin()
    {
        if (head == NULL)
            cout << "List empty! " << endl;
        else
        {
            Node *ptr = head;
            head = head->link;
            delete ptr;
            cout << " from begin..";
            this->size--;
        }
    }

    // delete from end
    void deleteEnd()
    {
        if (head == NULL)
            cout << "List empty!" << endl;
        else if (head->link == NULL)
            deleteBegin();
        else
        {
            Node *ptr = head;
            while (ptr->link->link != NULL){
                ptr = ptr->link;
            }
            delete ptr->link; 
            ptr->link = NULL;
            cout << " from end..";
            this->size--;
        }
    }

    // delete at position

    void deleteFromPos()
    {
        if (head == NULL)
            cout << "List empty!";
        else
        {
            int pos;
            cout << "Enter the position between 1 to " << size << " : ";
            cin >> pos;

            if (pos < 1 || pos > size)
                cout << "Invalid position! ";
            else
            {
                if (pos == 1)
                    deleteBegin();
                else if (pos == size)
                    deleteEnd();
                else
                {
                    Node *ptr = head, *temp;
                    for (int i = 1; i < pos - 1; i++, ptr = ptr->link);
                    temp = ptr->link;
                    ptr->link = temp->link;
                    // temp->link = NULL;
                    delete temp;
                    printf(" from %d position",pos);
                    this->size--;
                }
            }
        }
    }
    // display function
    void display()
    {
        if (head == NULL)
            cout << "No elements!" << endl;
        else
        {
            Node *ptr = head;
            cout << "List elements : ";
            while (ptr != NULL)
            {
                cout << ptr->value << " ";
                ptr = ptr->link;
            }
        }
    }
};

int main()
{
    LinkedList list;
    cout << "Enter the operation : ";
    cout << "\n1.Insert At Begin\n2.Insert At End\n3.Insert At Specific Position\n4.Display";
    cout << "\n5.Delete From Begin\n6.Delete From End\n7.Delete From Specific Position\n8.exit()";
    int op;
    do
    {
        cout << "\nEnter your choice : ";
        cin >> op;
        switch (op)
        {
        case 1:  list.insertBegin();      break;
        case 2:  list.insertEnd();        break;
        case 3:  list.insertAtpos();      break;
        case 4:  list.display();          break;
        case 5:  list.deleteBegin();      break;
        case 6:  list.deleteEnd();        break;
        case 7:  list.deleteFromPos();    break;
        case 8:  cout << "Exiting....... :)" << endl;  break;
        default: cout << "Invalid choice!";            break;
        }
    } while (op != 8);

    return 0;
}
