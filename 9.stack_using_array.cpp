#include <iostream>
using namespace std;

#define max_size 100

class stack
{
private:
    int arr[max_size];
    int top;

public:
    stack()
    {
        top = -1;
    }

    void push(int val)
    {
        if (top >= max_size - 1)
        {
            cout << "stack is overflow" << endl;
            return;
        }
        else
        {
            arr[++top] = val;
            cout << val << " pushed in stack" << endl;
        }
    }

    int pop()
    {
        if (top < 0)
        {
            cout << "stack is already empty" << endl;
            return -1; // Return error value
        }
        else
        {
            int val = arr[top--];
            return val;
        }
    }

    int peek()
    {
        if (top < 0)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    void display()
    { // Changed return type to void
        if (top < 0)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl; // Added newline
    }
};

int main()
{
    stack s;
    s.push(5);
    s.push(7);
    cout << "Top element: " << s.peek() << endl;
    s.display();
    return 0;
}