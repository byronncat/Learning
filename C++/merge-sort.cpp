#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &arr, int left = 0, int right = -1)
{
    if (right == -1)
        right = arr.size() - 1;

    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right)
            temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];

        while (i <= mid)
            temp[k++] = arr[i++];
        while (j <= right)
            temp[k++] = arr[j++];

        for (i = left; i <= right; i++)
            arr[i] = temp[i - left];
    }
}

int main()
{
    vector<int> arr = {170, 45, 75, 90, 2, 802, 100, 66, 1204};
    mergeSort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}