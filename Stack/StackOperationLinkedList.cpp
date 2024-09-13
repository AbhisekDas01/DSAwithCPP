#include <iostream>
using namespace std;

//stack creation 
class Stack
{
    public:
    int value;
    Stack *link;

    //constructor 
    Stack(int data)
    {
        value = data;
        link = NULL;
    }

    //destructor
    ~Stack()
    {
        cout << "\nDeleted : " << value;
        link = NULL;
    }
};

class StackOperations
{
    private:
    Stack *top;

    public:
    StackOperations()
    {
        top = NULL;
    }

    //destructor 
    ~StackOperations()
    {
        if(top != NULL){
            cout << "Clearing memory..";
            while(top != NULL)
            {
                Stack *temp = top;
                top = top->link;
                delete temp;
            }
            cout << "\nCleared..";
        }
        
    }

    //push operation 
    void push()
    {
        int data;
        cout << "Enter the value : ";
        cin >> data;
        Stack *ptr = new Stack(data);

        if(top == NULL)
            top = ptr;
        else
        {
            ptr->link = top;
            top = ptr;
        }
    }

    void pop()
    {
        if(top == NULL)
            cout << "Stack Underflow!";
        else
        {
            Stack *ptr = top;
            top = top->link;
            delete ptr;
        }

    }

    void peek()
    {
        if(top == NULL)
            cout << "Stack Underflow!";
        else
        {
            cout << "Top element : " << top ->value;
        }
    }

    void display()
    {
        if(top == NULL)
            cout << "Stack Underflow!";
        else
        {
            Stack *ptr = top;
            cout << "Stack elements : ";
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
    StackOperations S;
    cout << "Select the operation :\n";
    cout << "1. push()\n2. pop()\n3. peep()\n4. display()\n5. exit()" << endl;

    int op;

    do{
        cout << "\nChoice : ";
        cin >> op;

        switch (op) {
            case 1: S.push();    break;
            case 2: S.pop();     break;
            case 3: S.peek();    break;
            case 4: S.display(); break;
            case 5: cout << "Exiting..." << endl ;break;
            
            default: cout << "\nInvalid choice" << endl; break;
        }
    }while(op != 5);
    return 0;
}