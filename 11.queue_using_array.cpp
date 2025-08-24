#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the queue

class LinearQueue {
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    LinearQueue() {
        front = -1; // Initialize front and rear to -1 (empty queue)
        rear = -1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Check if the queue is full
    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    // Add an element to the rear of the queue (enqueue)
    void enqueue(int x) {
        if (isFull()) {
            cout << "Error: Queue is full!" << endl;
            return;
        }
        else if (isEmpty()) {
            front = rear = 0; // Initialize both to 0 for first element
        }
        else {
            rear++; // Increment rear for new element
        }
        arr[rear] = x;
        cout << x << " enqueued to queue" << endl;
    }

    // Remove an element from the front of the queue (dequeue)
    int dequeue() {
        int x;
        if (isEmpty()) {
            cout << "Error: Queue is empty!" << endl;
            return -1;
        }
        else if (front == rear) {
            // Only one element in queue, reset to empty state
            x = arr[front];
            front = rear = -1;
        }
        else {
            x = arr[front];
            front++; // Move front to next element
        }
        cout << x << " dequeued from queue" << endl;
        return x;
    }

    // Get the front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Error: Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    LinearQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display(); // Output: 10 20 30 40

    q.dequeue(); // Output: 10 dequeued from queue
    q.dequeue(); // Output: 20 dequeued from queue

    q.display(); // Output: 30 40

    q.enqueue(50);
    q.enqueue(60);

    q.display(); // Output: 30 40 50 60

    cout << "Front element is: " << q.peek() << endl; // Output: 30

    return 0;
}