#include <iostream>
using namespace std;
class Queue
{
    private:
    int *queue;
    int front;
    int rear;
    int size;

    public:
    //consturctor to initialize value
    Queue(int size)
    {
        this->size = size;
        this->queue = new int[size];
        front = rear = -1;
    }
    //destructor to free memory 
    ~Queue()
    {
        delete [] queue;
    }

    //insert fuction
    void push()
    {
        //check if queue is full
        if(rear == size-1)
            cout << "Queue is full!";
        else
        {
            int data;
            cout << "Enter the element : ";
            cin >> data;
            queue[++rear] = data;
            if(front == -1)
                front = 0;
        }
    }

    //delete function
    int pop()
    {
        int poped = queue[front++];
            //if queue becomes empty 
            if(front == rear+1)
                front = rear = -1;
            

            return poped;

        
    }

    //front element 
    int getFront()
    {
        return queue[front];
    }

    //display function
    void display()
    {
        if(isEmpty())
            cout << "Queue is empty!";
        else
        {
            cout << "Queue elements : ";
            for(int i = front ; i <= rear ; i++)
            {
                cout << queue[i] << " ";
            }
        }

    }

    bool isEmpty()
    {
        if(front == -1)
            return true;
        return false;
    }
};
int main()
{
    int size;
    cout << "Enter the size of queue : ";
    cin >> size;
    Queue q(size);
    int ch;
    cout <<"Enter the operations : ";
    cout <<"\n1.insert\n2.delete\n3.getFront\n4.display\n5.exit()";
    do
    {
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1: q.push();       break;
        case 2: 
            if(!(q.isEmpty()))
                cout << "Deleted : " << q.pop();
            else
                cout << "Queue is Empty!";
            break;
        case 3: 
            if(!(q.isEmpty()))
                cout << "Front element : " << q.getFront();
            else
                cout << "Queue is Empty!";
            break;
        case 4:
            if(!(q.isEmpty()))
                q.display(); 
            else
                cout << "Queue is empty!";
            break;
        case 5: cout << "Exiting.....";    break;
        default: cout << "Invlid choice!"; break;
        }
    } while (ch != 5);
    
    return 0;
}