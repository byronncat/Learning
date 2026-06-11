#ifndef MERGE_SORT_H
#define MERGE_SORT_H

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

#endif
