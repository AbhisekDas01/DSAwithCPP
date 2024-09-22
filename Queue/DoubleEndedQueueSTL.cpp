#include <iostream>
#include <deque>
using namespace std;

void display(deque<int> &q)
{
    deque<int> ::iterator it;
    cout << "Queue elements : ";
    for(it = q.begin() ; it != q.end() ; it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    deque<int> q;
   
    int ch;
    cout << "Enter the operation : ";
    cout << "\n1.push_front()\n2.push_rear()\n3.pop_front()\n4.pop_rear()";
    cout << "\n5.display()\n6.exit()";

    do
    {
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        //push front function
            int data;
            cout << "Enter the element : ";
            cin >>data;
            q.push_front(data);
            break;
        case 2:
        //push rear function 
            cout << "Enter the element : ";
            cin >> data;
            q.push_back(data);
            break;
        case 3:
        //pop front function 
            if(q.empty())
                cout << "Queue is empty!";
            else
            {
                int data = q.front();
                cout << "Deleted : " << data;
                q.pop_front();
            }
            break;
        case 4: 
        //pop rear function 
            if(q.empty())
                cout << "Queue is empty!";
            else
            {
                int data = q.back();
                cout << "Deleted : " << data;
                q.pop_back();
            }
            break;
        case 5: 
        //display
            if(q.empty())
                cout << "Queue is empty!";
            else
            {
                display(q);
            }
            break;
        case 6: cout << "Exiting...."; break;
        default: cout << "Invalid choice";break;
        }
    } while (ch != 6);
    return 0;
}