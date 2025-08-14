// ABHINAV KUMAR
//  24BSA10110

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    int index = start - 1;
    int pivot = arr[end];

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            index++;
            swap(arr[j], arr[index]);
        }
    }
    index++;
    swap(arr[index], arr[end]);
    return index;
}

void quick_sort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int partitionIndex = partition(arr, start, end);
        quick_sort(arr, start, partitionIndex - 1);
        quick_sort(arr, partitionIndex + 1, end);
    }
}

int main()
{
    vector<int> arr = {12, 24, 45, 23, 12, 53, 1};
    quick_sort(arr, 0, arr.size() - 1);
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
