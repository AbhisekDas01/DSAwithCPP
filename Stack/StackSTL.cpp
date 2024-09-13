#include <iostream>
#include <stack> //stack stl

using namespace std;

void display(stack<int> Stack) {
    if (Stack.empty()) {
        cout << "Stack is empty!" << endl;
        return;
    }

    cout << "Stack elements: ";
    while (!Stack.empty()) {
        cout << Stack.top() << " "; // Display the top element
        Stack.pop(); // Remove the top element
    }
    cout << endl;
}


int main()
{
    stack<int> Stack;
    cout << "Select the operation :\n";
    cout << "1. push()\n2. pop()\n3. peep()\n4.display\n5. exit()" << endl;

    int op;

    do{
        cout << "\nChoice : ";
        cin >> op;

        switch (op) {
            case 1: 
                //push operation
                int data;
                cout << "Enter the value : ";
                cin >> data;
                Stack.push(data);  
                break;

            case 2: 
                if(!Stack.empty())
                {
                    cout << "Deleted : " << Stack.top() ;
                    Stack.pop(); 
                }
                else
                    cout << "Stack underflow!";
                break;

            case 3: 
                if(!Stack.empty())
                    cout << "Top element of Stack : " <<Stack.top();
                else
                    cout << "Stack underflow!";
                break;

            case 4:
                display(Stack); break;
            case 5: 
            cout << "Exiting..." << endl ;break;
            
            default: cout << "\nInvalid choice" << endl; break;
        }
    }while(op != 5);
    return 0;
}