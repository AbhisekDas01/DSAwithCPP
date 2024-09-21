#include <iostream>
using namespace std;
class cQueue
{
    private:
    int *cqueue;
    int front,rear,size;
    public:
    //constructor to initialize value
    cQueue(int size)
    {
        this->size = size;
        cqueue = new int[size];
        front = rear = -1;
    }
    ~cQueue()
    {
        delete [] cqueue;
    }

    //operations 
    void push()
    {
        if((rear+1)%size == front)
            cout << "Queue is full!" << endl;
        else
        {
            rear = (rear+1) %size;
            cout << "Enter the value : ";
            cin >> cqueue[rear];
            if(front == -1)
                front = 0;
        }
    }

    void pop()
    {
        //if queue is empty 
        if(front == -1)
            cout << "Queue is empty!";
        else
        {
            
            cout << "Deleted : " << cqueue[front];
            if (front == rear)
            {
                // If only one element was present
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % size;
            }
        }
        
    }

    void display()
    {
        if(front == -1)
            cout << "Queue is empty!";
        else
        {
            int i = front;
            cout << "Queue elements : ";
            do
            {
                cout << cqueue[i] << " ";
                i = (i+1)%size;
            } while (i != rear);
            cout << cqueue[rear];
            
        }
    }
};
int main()
{
    int size , ch;
    cout << "Enter the size of the queue : ";
    cin >> size;
    cQueue q(size);
    cout << "Enter the operations : ";
    cout << "\n1.insert()\n2.delete()\n3.display()\n4.exit()";
    do
    {
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            q.push();
            break;
        case 2:
            q.pop();
            break;
        case 3: 
            q.display();
            break;
        case 4:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice!";
            break;
        }
    } while (ch != 4);
    
    return 0;
}