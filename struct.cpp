#include <iostream>
#include <string>
using namespace std;

// Define a structure for Employee
struct Employee
{
    string name;
    double salary;
};

int main()
{
    // Create an Employee object
    Employee emp;

    // Create a pointer to the Employee structure
    Employee *empPtr = &emp;

    // Accept input from user using pointer
    cout << "Enter employee name: ";
    cin.ignore();               // Clear input buffer
    getline(cin, empPtr->name); // Using arrow operator with pointer

    cout << "Enter employee salary: ";
    cin >> empPtr->salary;

    // Display the employee information using pointer
    cout << "\nEmployee Details (accessed via pointer):\n";
    cout << "Name: " << empPtr->name << endl;
    cout << "Salary: " << empPtr->salary << endl;

    return 0;
}