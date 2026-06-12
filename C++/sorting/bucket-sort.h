#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<int> &arr)
{
    if (arr.empty())
        return;

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int bucketCount = maxVal - minVal + 1;

    vector<vector<int>> buckets(bucketCount);

    for (int num : arr)
        buckets[num - minVal].push_back(num);

    int index = 0;
    for (const auto &bucket : buckets)
    {
        for (int num : bucket)
            arr[index++] = num;
    }
}

#endif
