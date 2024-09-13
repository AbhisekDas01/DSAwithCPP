#include <iostream>
using namespace std;
class Stack
{
    private:
    int top;
    int *arr;
    int size;

    public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr  = new int[size];
    }

    ~Stack()
    {
        delete []arr;
    }

    //stack operations 
    void push()
    {
        if(top == size-1)
        {
            cout  << "Stack overflow!" << endl;
            return;
        }
        cout << "Enter the value : ";
        cin >> arr[++top];
    }
    //pop operation
    void pop()
    {
        if(top == -1)
            cout << "Stack underflow!" << endl;
        else
            cout << "Deleted " << arr[top--] << endl;
    
    }
    void peek()
    {
        if(top == -1)
            cout << "Stack underflow!" << endl;
        else
            cout << "Top element :  " << arr[top] << endl;
    }

    void display()
    {
        if(top == -1)
            cout << "Stack underflow!" << endl;
        else
        {
            cout << "Stack elements : ";
            for(int i = top ; i >= 0 ; i--)
                cout << arr[i] << " ";
        }
    }
};
int main()
{
    int size;
    cout << "Enter the size of the Stack : ";
    cin >> size;
    Stack S(size);
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
            case 5: cout << "Exiting..." ;break;
            
            default: cout << "\nInvalid choice" << endl; break;
        }
    }while(op != 5);
    return 0;
}