#include <iostream>
using namespace std;

// Node structure for doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class Deque {
private:
    Node* front;
    Node* rear;
    int size;
    
public:
    // Constructor
    Deque() : front(nullptr), rear(nullptr), size(0) {}
    
    // Destructor to free memory
    ~Deque() {
        while (!isEmpty()) {
            deleteFront();
        }
    }
    
    // Check if deque is empty
    bool isEmpty() {
        return size == 0;
    }
    
    // Get size of deque
    int getSize() {
        return size;
    }
    
    // Insert at front
    void insertFront(int value) {
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
        cout << value << " inserted at front" << endl;
    }
    
    // Insert at rear
    void insertRear(int value) {
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        size++;
        cout << value << " inserted at rear" << endl;
    }
    
    // Delete from front
    int deleteFront() {
        if (isEmpty()) {
            cout << "Deque underflow! Cannot delete from front." << endl;
            return -1;
        }
        
        Node* temp = front;
        int value = temp->data;
        
        if (front == rear) { // Only one element
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        
        delete temp;
        size--;
        cout << value << " deleted from front" << endl;
        return value;
    }
    
    // Delete from rear
    int deleteRear() {
        if (isEmpty()) {
            cout << "Deque underflow! Cannot delete from rear." << endl;
            return -1;
        }
        
        Node* temp = rear;
        int value = temp->data;
        
        if (front == rear) { // Only one element
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        
        delete temp;
        size--;
        cout << value << " deleted from rear" << endl;
        return value;
    }
    
    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return front->data;
    }
    
    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return rear->data;
    }
    
    // Display deque from front to rear
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        
        cout << "Deque elements (front to rear): ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    
    dq.insertFront(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertRear(25);
    
    dq.display(); // Output: 5 10 20 25
    
    cout << "Front element: " << dq.getFront() << endl; // 5
    cout << "Rear element: " << dq.getRear() << endl;    // 25
    
    dq.deleteFront();
    dq.deleteRear();
    
    dq.display(); // Output: 10 20
    
    dq.insertFront(2);
    dq.insertRear(30);
    
    dq.display(); // Output: 2 10 20 30
    
    // Test empty deque operations
    while (!dq.isEmpty()) {
        dq.deleteRear();
    }
    
    dq.deleteFront(); // Deque underflow message
    
    return 0;
}