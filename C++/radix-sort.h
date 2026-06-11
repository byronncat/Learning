#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <vector>
using namespace std;

int getMaxRadix(vector<int> &arr)
{
    int mx = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countingSort(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int> &arr)
{
    int m = getMaxRadix(arr);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

#endif
