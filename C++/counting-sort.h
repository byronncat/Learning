#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include <vector>
using namespace std;

int getMaxCounting(vector<int> &arr)
{
    int mx = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countingSort(vector<int> &arr)
{
    int max = getMaxCounting(arr);
    vector<int> count(max + 1, 0);

    for (int i = 0; i < arr.size(); i++)
        count[arr[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

#endif
