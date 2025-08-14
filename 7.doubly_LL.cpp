#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList
{

    Node *head;
    Node *tail;

public:
    DoublyList()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void printll()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
            return;

        Node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
    }

    void pop_back()
    {
        if (tail == NULL)
            cout << "doubly LL is empty" << endl;

        Node *temp = tail;
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL;

        delete temp;
    }
};

int main()
{
    DoublyList dl;
    dl.push_front(10);
    dl.push_front(20);
    dl.push_front(30);
    dl.printll(); // Output: 30 20 10
    dl.push_back(40);
    dl.push_back(50);
    dl.printll(); // Output: 30 20 10 40 50
    dl.pop_front();
    dl.printll(); // Output: 20 10 40 50
    dl.pop_back();
    dl.printll(); // Output: 20 10 40

    return 0;
}