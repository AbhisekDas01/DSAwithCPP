//Doubly linked list implementation
#include <iostream>
using namespace std;

//Node class
class Node
{
    public:
    int value;
    Node *prev;
    Node *next;

    //constructor to set values 
    Node(int value)
    {
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }

    //destructor to delete a node 
    ~Node()
    {
        this->prev = NULL;
        this->next = NULL;
        cout << "\nDeleted : " << this->value ;
    }
};


//linked list operations 
class LinkedList
{
    private: 
    Node *head;
    int size ; //to store the size 

    public:
    //constructor to initialise the values 
    LinkedList()
    {
        head = NULL;
        size = 0 ;
    }
    // Destuctor to delete all nodes after completion of the program
    ~LinkedList()
    {
        cout << "\nClearing memory...";
        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        cout << "\nCleared..\nExited Successfully >> Thank You...";
    }

    private:
    Node * createNode()
    {
        int data ; 
        cout << "Enter the element : ";
        cin >> data ; 
        Node *ptr = new Node(data);
        return ptr;
    }

    

    public:
    //insert at begin 
    void insertBegin()
    {
        Node *ptr = createNode();
        if(head == NULL)
            head = ptr ;
        else 
        {
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        this->size++;
        cout <<"Inserted at begin..";
    }

    //insert at end 
    void insertEnd()
    {
        Node *ptr = createNode();
        if(head == NULL)
            head = ptr; 
        else
        {
            Node *temp = head;
            while(temp ->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
        }
        this->size++;
        cout << "Inserted at end..";
    }

    //insert at specific position 
    void insertAtpos()
    {
        int pos;
        cout << "Enter the position between 1 to " << size + 1 << " : ";
        cin >> pos;

        if (pos < 1 || pos > size + 1)
            cout << "Invalid position! ";
        else
        {
            if(pos == 1)
                insertBegin();
            else if(pos == size+1)
                insertEnd();
            else
            {
                Node *ptr = createNode(),*temp = head;
                for(int i = 1; i < pos-1 ; i++ , temp = temp->next);
                ptr->next = temp->next;
                ptr->prev = temp;
                ptr->next->prev = ptr;
                temp->next = ptr;
                
                
                this->size++;
                printf("Inserted at %dth postion..",pos);
            }
        }
    }

    //delete from Begin 
    void deleteBegin()
    {
        if(head == NULL)
            cout << "List empty!";
        else
        {
            Node *temp = head ;
            head = head->next;
            if(head != NULL)
                head->prev = NULL;
            delete temp;
            this->size--;
        }
    }

    //delete from end 
    void deleteEnd()
    {
        if(head == NULL)
            cout << "List empty!";
        else
        {
            if(head->next == NULL)
                deleteBegin();
            else
            {
                Node *temp = head;
                while(temp ->next->next != NULL)
                {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = NULL;
                this->size--;
            }
        }
    }

    //delete from position 
    void deleteFromPos()
    {
        if(head == NULL)
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
                if(pos == 1)
                    deleteBegin();
                else if(pos == size)
                    deleteEnd();
                else
                {
                    Node *temp = head , *ptr;
                    for(int i = 1 ; i < pos-1 ; i++ , temp = temp->next);
                    ptr = temp->next;

                    temp->next = ptr->next;
                    ptr->next->prev = temp;
                    delete ptr;
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
            Node *ptr = head ,*temp = head;
            cout << "List elements : ";
            while (ptr != NULL)
            {
                cout << ptr->value << " ";
                ptr = ptr->next;

                //to move to the last node 
                if(temp->next != NULL)
                    temp = temp->next;
            }
            char op;
            cout << "\n\nPrint List in reverse order (y/n) : ";
            cin >>op;

            if(op == 'y') displayReverse(temp);
        }
    }

    //reverse print
    private:
    void displayReverse(Node *tail)
    {
        cout << "List elements in reverse order : ";
        while(tail != NULL)
        {
            cout << tail->value << " ";
            tail=tail->prev;
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
