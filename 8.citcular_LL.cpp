#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class CircularList
{
    Node *head;
    Node *tail;

public:
    CircularList()
    {
        head = tail = nullptr;
    }

    ~CircularList()
    {
        if (!head)
            return;
        Node *current = head;
        head->next = nullptr; // Break the circular link
        while (current)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void printList()
    {
        if (!head)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "(circular)" << endl;
    }
};

int main()
{
    CircularList cl;
    cl.push_front(1);
    cl.push_front(2);
    cl.push_front(3);
    cl.printList();
    return 0;
}