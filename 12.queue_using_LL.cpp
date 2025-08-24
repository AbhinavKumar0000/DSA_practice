#include <iostream>
using namespace std;

// Node structure for the linked list
class Node {
public:
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front; // Pointer to front of queue
    Node* rear;  // Pointer to rear of queue
    
public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr) {}
    
    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    
    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
    
    // Add element to the rear (enqueue)
    void enqueue(int value) {
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            // If queue is empty, both front and rear point to new node
            front = rear = newNode;
        } else {
            // Add new node at the end and update rear
            rear->next = newNode;
            rear = newNode;
        }
        
        cout << value << " enqueued to queue" << endl;
    }
    
    // Remove element from front (dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Queue is empty." << endl;
            return -1;
        }
        
        Node* temp = front;
        int dequeuedValue = temp->data;
        
        // Move front to the next node
        front = front->next;
        
        // If queue becomes empty, update rear to nullptr
        if (front == nullptr) {
            rear = nullptr;
        }
        
        delete temp; // Free memory
        cout << dequeuedValue << " dequeued from queue" << endl;
        return dequeuedValue;
    }
    
    // Get front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    
    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Queue elements (front to rear): ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    
    q.display(); // Output: 10 20 30 40
    
    q.dequeue(); // Output: 10 dequeued from queue
    q.dequeue(); // Output: 20 dequeued from queue
    
    q.display(); // Output: 30 40
    
    cout << "Front element is: " << q.peek() << endl; // Output: 30
    
    q.enqueue(50);
    q.enqueue(60);
    
    q.display(); // Output: 30 40 50 60
    
    // Test empty queue
    while (!q.isEmpty()) {
        q.dequeue();
    }
    
    q.dequeue(); // Output: Queue underflow! Queue is empty.
    
    return 0;
}