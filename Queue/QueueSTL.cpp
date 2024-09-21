#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> Q; //queue declaration;
    int ch;
    cout <<"Enter the operations : ";
    cout <<"\n1.insert\n2.delete\n3.getFront\n4.display\n5.exit()";
    do
    {
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int value;
            cout <<"Enter the value : ";
            cin>>value;
            Q.push(value);
            break;
        case 2: 
            if(Q.empty())
                cout << "Queue is empty!";
            else
            {
                cout << "Deleted : " << Q.front();
                Q.pop();
            }
            break;
        case 3: 
            if(Q.empty())
                cout << "Queue is empty!";
            else
                cout << "Front element : "<< Q.front();
            break;
        case 4:
            //create a copy queue
            if(Q.empty())
                cout << "Queue is empty!";
            else
            {
                queue <int>temp = Q;
                cout << "Queue elements : ";
                while(!(temp.empty()))
                {
                    cout << temp.front() << " ";
                    temp.pop();
                }
            }
                
            break;
        case 5: cout << "Exiting.....";    break;
        default: cout << "Invalid choice!"; break;
        }
    } while (ch != 5);
    
    return 0;
}