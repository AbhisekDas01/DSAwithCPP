#include <iostream>
using namespace std;
class DEque
{
    private:
    int *arr;
    int front , rear;
    int size;
    public:
    DEque(int size)
    {
        this->size = size;
        front = rear = -1;
        arr = new int[size];
    }

    ~DEque()
    {
        delete [] arr;
    }

    //push_front function
    void push_front()
    {
        //check if queue if full
        if((front == 0 && rear == size-1) || (rear+1)%size == front)
        {
            cout <<"Queue is full!";
            return;
        }
        int data;
        cout << "Enter the value : ";
        cin >> data;
        if(front == -1)
        {
            front = rear = 0;
            arr[front] = data;
            return;
        }

        front = (front-1 + size)%size; //front will be -ve otherwise so we added size
        arr[front] = data;
    }

    //rear function
    void push_rear()
    {
        //check if queue is full
        if((front == 0 && rear == size-1) || (rear+1)%size == front)
        {
            cout << "Queue is full!";
            return;
        }

        int data ;
        cout << "Enter the value : ";
        cin >>data;
        if(front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
            return;
        }

        rear = (rear+1)%size;
        arr[rear] = data;
    }

    //pop front 
    void pop_front()
    {
        //check if empty
        if(front == -1)
        {
            cout << "Queue is empty!";
            return;
        }

        cout << "Deleted : " << arr[front];
        // If deque has only one element, reset to empty state
        if(front == rear)
            front = rear = -1;
        else
            front = (front +1)%size;
    }


    //pop back 
    void pop_rear()
    {
        if(front == -1)
        {
            cout << "Queue is empty!";
            return;
        }

        cout << "Deleted : " <<arr[rear];

        if(front == rear)
            front = rear = -1;
        else
            rear = (rear-1 + size) %size;

    }

    //display
    void display()
    {
        if(front == -1)
        {
            cout << "Queue if empty!";
            return;
        }
        cout << "Queue elements : ";
        for(int i = front ; i != rear ; i = (i+1)%size)
        {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
};
int main()
{
    int size;
    cout << "Enter the size : ";
    cin >> size;
    int ch;
    DEque q(size);
    cout << "Enter the operation : ";
    cout << "\n1.push_front()\n2.push_rear()\n3.pop_front()\n4.pop_rear()";
    cout << "\n5.display()\n6.exit()";

    do
    {
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1: q.push_front(); break;
        case 2: q.push_rear();  break;
        case 3: q.pop_front();  break;
        case 4: q.pop_rear();   break;
        case 5: q.display();    break;
        case 6: cout << "Exiting...."; break;
        default: cout << "Invalid choice";break;
        }
    } while (ch != 6);
    
    return 0;
}