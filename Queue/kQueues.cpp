#include <iostream>
using namespace std;

class kQueues {
    private:
    int *arr;    // Array to store queue elements
    int *front;  // Array to store indices of front elements of each queue
    int *rear;   // Array to store indices of rear elements of each queue
    int *next;   // Array to store next free or next element index
    int size;    // Total size of the array
    int k;       // Number of queues
    int freeSlot; // To track the next available free slot

    public:
    // Constructor to initialise all the values
    kQueues(int size, int k) {
        this->size = size;
        this->k = k;
        freeSlot = 0;

        arr = new int[size];
        front = new int[k];
        rear = new int[k];
        next = new int[size];

        // Initialize front and rear arrays for all queues to -1 (empty queues)
        for(int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        // Initialize the next array to store the next available free slot index
        for (int i = 0; i < size - 1; i++) {
            next[i] = i + 1;
        }
        next[size - 1] = -1;  // Last element should point to -1 (no next free slot)
    }

    // Destructor to free allocated memory
    ~kQueues() {
        delete [] arr;
        delete [] front;
        delete [] rear;
        delete [] next;
    }

    // Push operation to insert element into the queue
    void push(int data, int qn) {
        // Check for overflow (no free slot available)
        if(freeSlot == -1) {
            cout << "Queue overflow!" << endl;
            return;
        }

        // Step 1: Get the next free slot
        int index = freeSlot;

        // Step 2: Update the freeSlot to the next available free position
        freeSlot = next[index];

        // Step 3: If the queue is empty, update the front
        if(front[qn - 1] == -1) {
            front[qn - 1] = index;
        } else {
            // Link the new element to the previous rear
            next[rear[qn - 1]] = index;
        }

        // Step 4: Update the next of the current index to -1 (end of queue)
        next[index] = -1;

        // Step 5: Update the rear to the new index
        rear[qn - 1] = index;

        // Step 6: Insert the element into the array
        arr[index] = data;
    }

    // Pop operation to remove and return front element from the queue
    int pop(int qn) {
        // Check if the queue is empty
        if(front[qn - 1] == -1) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        // Get the index of the front element
        int index = front[qn - 1];

        // Update the front to the next element
        front[qn - 1] = next[index];

        // Step 1: Link the free slot back
        next[index] = freeSlot;

        // Step 2: Mark the current index as the new free slot
        freeSlot = index;

        // Return the popped element
        return arr[index];
    }
};

int main() {
    kQueues queues(10, 3); // 3 queues, total size 10

    // Test pushing and popping in multiple queues
    queues.push(10, 1); // Queue 1
    queues.push(20, 1); // Queue 1
    queues.push(15, 2); // Queue 2

    cout << "Popped from Queue 1: " << queues.pop(1) << endl; // Should return 10
    cout << "Popped from Queue 2: " << queues.pop(2) << endl; // Should return 15
    cout << "Popped from Queue 1: " << queues.pop(1) << endl; // Should return 20

    return 0;
}
