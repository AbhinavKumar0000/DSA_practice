#include <iostream>
using namespace std;

// Simple Node structure
struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;  // Pointer to top node

public:
    Stack() {
        top = NULL;  // Initialize empty stack
    }

    void push(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
        cout << val << " pushed to stack\n";
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        Node* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    
    s.display();
    
    cout << "Top element: " << s.peek() << endl;
    
    cout << s.pop() << " popped from stack\n";
    cout << s.pop() << " popped from stack\n";
    
    s.display();
    
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}