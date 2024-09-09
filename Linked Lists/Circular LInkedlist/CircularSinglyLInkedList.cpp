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
        //destructor
        ~Node()
        {
            link = NULL;
            cout << "\nDeleted : "<< value;
        }
};

//operations
class CircularLinkedList
{
    private:
        Node *head;
        int size;
    
    public:
    //constructor
    CircularLinkedList()
    {
        head = NULL;
        size = 0;
    }

    // Destructor
    ~CircularLinkedList() {
        if (head != NULL) {
            Node *current = head;
            Node *next;
            cout << "Clearing memory..";
            do {
                next = current->link;
                delete current;
                current = next;
            } while (current != head);
            cout << "\ncleared " << endl;
        }
        
    }

    //create node
    private:
    Node* createNode()
    {
        int data;
        cout << "Enter the value : ";
        cin >> data;
        Node *ptr = new Node(data);
        return ptr;
    }

    public:
    //insert at begin
    void insertBegin()
    {
        Node *ptr = createNode();

        //inserting first node
        if(head == NULL)
        {
            head = ptr;
            head->link = head; //points to it self
        }
        else
        {
            Node *temp = head; //move to the last node to point the last node link to head
            while(temp->link != head)
                temp = temp->link;
            
            ptr->link = head;
            head = ptr;
            temp->link = head;
        }
        cout << "Inserted at Begin.." << endl;
        size++;
    }

    //insert at end
    void insertEnd()
    {
        Node *ptr = createNode();

        //if list is empty
        if(head == NULL)
        {
            head = ptr;
            head->link = head;
        }
        else
        {
            Node *temp = head; // to move to the last node

            while(temp->link != head)
                temp = temp->link;
            
            temp->link = ptr;
            ptr->link = head;
        }
        size++;
        cout << "Inserted at end.."<<endl;
    }

    //insert at specific position
    void insertAtpos()
    {
        int pos;
        cout << "Enter the postion between 1 to " << size+1 << " : ";
        cin >> pos;

        if(pos < 1 || pos > size +1)
        {
            cout << "Invalid position";
            return;
        }

        //if pos = 1 
        if(pos == 1)
        {
            insertBegin();
            return;
        }

        if(pos == size+1)
        {
            insertEnd();
            return;
        }

        Node *ptr = createNode();
        Node *temp = head;
        for(int i = 1 ; i < pos-1 ; i++)
            temp = temp->link;

        ptr->link = temp->link;
        temp->link = ptr;
        size++;
        cout << "Inserted at " << pos << "th position.." << endl;
    }

    //delete from begin
    void deleteBegin()
    {
        if(head == NULL){
            cout << "List empty!";
            return;
        }
        if(head->link == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            //to move to the last node 
            Node *temp = head ;
            while(temp ->link != head)
                temp = temp->link;
            
            Node *ptr = head;
            head = head->link;
            temp->link = head;

            delete ptr;
        }
        size--;
        cout << " from begin" << endl;
    }

    //delete end function
    void deleteEnd()
    {
        if(head == NULL)
        {
            cout << "List empty!";
            return;
        }
        if(head -> link == head)
        {
            deleteBegin();
            return;
        }

        Node *ptr = head;

        while (ptr->link->link != head)
        {
            ptr = ptr->link;
        }

        delete ptr->link; //delete last node
        ptr->link = head;
        size--;
        cout << " from end.." << endl;
    }

    //delete from specific position
    void deleteFromPos()
    {
        if(head == NULL)
        {
            cout << "Empty list!";
            return;
        }


        int pos;
        cout << "Enter the postion between 1 to " << size << " : ";
        cin >> pos;

        if(pos < 1 || pos > size)
        {
            cout << "Invalid position";
            return;
        }

        if(pos == 1)
        {
            deleteBegin();
            return;
        }
        if(pos == size)
        {
            deleteEnd();
            return;
        }

        Node *temp = head;
        for(int i = 1 ; i < pos-1; i++)
        {
            temp = temp->link;
        }

        Node *ptr = temp->link;

        temp->link = ptr->link;
        delete ptr;
        size--;
        cout << " from " << pos << "th postion.." <<endl;

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


};

int main()
{
    CircularLinkedList list;
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