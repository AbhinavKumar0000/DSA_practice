#include <iostream>
using namespace std;

void selection_sort(int arr[], int n)
{
    int si = 1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[si])
            {
                si = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[si];
        arr[si] = temp;
    }
}
void print_array(int arr[], int n)
{
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    selection_sort(arr, size);
    print_array(arr, size);
}