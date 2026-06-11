#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int> &arr)
{
    int mx = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countingSort(vector<int> &arr)
{
    int max = getMax(arr);
    vector<int> count(max + 1, 0);

    // Count occurrences of each number
    for (int i = 0; i < arr.size(); i++)
        count[arr[i]]++;

    // Prefix sum
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Build the output array
    vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the output array to the original array
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

int main()
{
    vector<int> arr = {170, 45, 75, 90, 2, 802, 100, 66, 1204};
    countingSort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}