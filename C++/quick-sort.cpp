#include <iostream>
#include <vector>
using namespace std;

int pickPivot(vector<int> &arr, int low, int high)
{
    // int pivotIndex = low + rand() % (high - low + 1);
    // swap(arr[pivotIndex], arr[high]);

    // int pivot = arr[high];
    int pivot = arr[high];
    return pivot;
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = pickPivot(arr, low, high);
    int i = low - 1;

    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low = 0, int high = -1)
{
    if (high == -1)
        high = arr.size() - 1;

    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{
    vector<int> arr = {170, 45, 75, 90, 2, 802, 100, 66, 1204};
    quickSort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}