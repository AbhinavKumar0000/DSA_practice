#include <iostream>
using namespace std;

// Node structure for circular linked list
class Node {
public:
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class CircularQueue {
private:
    Node* rear;  // Only need rear pointer in circular list
    int size;
    int capacity;
    
public:
    // Constructor
    CircularQueue(int queueCapacity) : rear(nullptr), size(0), capacity(queueCapacity) {}
    
    // Destructor to free memory
    ~CircularQueue() {
        if (!isEmpty()) {
            Node* temp = rear->next;  // Start at front
            Node* toDelete;
            
            // Break the circular link temporarily
            rear->next = nullptr;
            
            while (temp != nullptr) {
                toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
    }
    
    // Check if queue is empty
    bool isEmpty() {
        return rear == nullptr;
    }
    
    // Check if queue is full
    bool isFull() {
        return size == capacity;
    }
    
    // Add element to the queue (enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflow! Cannot enqueue " << value << endl;
            return;
        }
        
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            rear = newNode;
            rear->next = rear;  // Points to itself
        } else {
            newNode->next = rear->next;  // New node points to front
            rear->next = newNode;        // Current rear points to new node
            rear = newNode;              // Update rear to new node
        }
        
        size++;
        cout << value << " enqueued to queue" << endl;
    }
    
    // Remove element from queue (dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Cannot dequeue" << endl;
            return -1;
        }
        
        Node* front = rear->next;
        int value = front->data;
        
        if (front == rear) {
            // Only one element in queue
            delete front;
            rear = nullptr;
        } else {
            rear->next = front->next;
            delete front;
        }
        
        size--;
        cout << value << " dequeued from queue" << endl;
        return value;
    }
    
    // Get front element without removing
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return rear->next->data;  // rear->next is front
    }
    
    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Queue elements (front to rear): ";
        Node* current = rear->next;  // Start at front
        
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != rear->next);  // Loop until we circle back
        
        cout << endl;
    }
    
    // Get current size of queue
    int getSize() {
        return size;
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();  // Output: 10 20 30 40 50

    cq.enqueue(60);  // Queue overflow message

    cq.dequeue();  // 10 dequeued
    cq.dequeue();  // 20 dequeued

    cq.display();  // Output: 30 40 50

    cq.enqueue(60);
    cq.enqueue(70);

    cq.display();  // Output: 30 40 50 60 70

    cout << "Front element: " << cq.peek() << endl;  // 30
    cout << "Current size: " << cq.getSize() << endl;  // 5

    return 0;
}