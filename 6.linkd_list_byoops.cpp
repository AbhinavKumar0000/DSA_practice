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
        next = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val); // dynamic object if the function ends it stays in memory
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {

        if (head == NULL)
        {
            cout << "Linked List is Empty";
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty";
            return;
        }
        else
        {
            Node *temp = head;

            while (temp->next != tail)
            {
                temp = temp->next;
            }

            temp->next = NULL;
            delete tail;
            tail = temp;
        }
    }

    void insert_bw(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Inalid Position passed";
        }
        if (pos == 0)
        {
            push_front(val);
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                if (temp == NULL)
                {
                    cout << "INVALID POSITION";
                    return;
                }
                temp = temp->next;
            }

            Node *NewNode = new Node(val);
            NewNode->next = temp->next;
            temp->next = NewNode;
        }
    }

    void delete_bw(int pos)
    {
        if (pos < 0)
        {
            cout << "INVALIS POSSION PASSING";
        }
        if (pos == 0)
        {
            pop_front();
        }

        else
        {
            Node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                if (temp == NULL)
                {
                    cout << "INVALID POSITION";
                    return;
                }
                temp = temp->next;
            }

            Node *nodeToDelete = temp->next; // Node to be deleted
            temp->next = nodeToDelete->next; // Bypass the node
            if (nodeToDelete == tail)
            { // Update tail if last node is deleted
                tail = temp;
            }
            delete nodeToDelete; // Free memory
        }
    }

    int search(int key)
    {
        Node *temp = head;
        int index = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    void print_ll()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.print_ll();
    ll.insert_bw(4, 0);
    ll.print_ll();
    ll.delete_bw(2);
    ll.print_ll();
    cout << ll.search(3);
    return 0;
}
