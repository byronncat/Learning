#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

#include "bubble-sort.h"
#include "counting-sort.h"
#include "heap-sort.h"
#include "merge-sort.h"
#include "quick-sort.h"
#include "radix-sort.h"

template <typename SortFunc>
void runBenchmark(const string &name, SortFunc sortFn, vector<int> data)
{
    vector<int> working = data;

    auto start = chrono::high_resolution_clock::now();
    sortFn(working);
    auto end = chrono::high_resolution_clock::now();

    bool correct = is_sorted(working.begin(), working.end());
    double elapsedMs = chrono::duration<double, milli>(end - start).count();

    cout << left << setw(10) << name << " | "
         << setw(10) << fixed << setprecision(3) << elapsedMs
         << (correct ? " | OK" : " | FAIL") << "\n";
}

int main()
{
    const int size = 100000;
    vector<int> input(size);
    iota(input.begin(), input.end(), 1);

    mt19937 rng(42);
    shuffle(input.begin(), input.end(), rng);

    cout << "Sorting benchmark\n";
    cout << left << setw(10) << "Algorithm" << setw(13) << " | Time (ms)" << " | Result\n";
    cout << "------------------------------\n";

    // runBenchmark("Bubble", [](vector<int> &arr)
    //              { bubbleSort(arr); }, input);
    runBenchmark("Counting", [](vector<int> &arr)
                 { countingSort(arr); }, input);
    runBenchmark("Merge", [](vector<int> &arr)
                 { mergeSort(arr); }, input);
    runBenchmark("Quick", [](vector<int> &arr)
                 { quickSort(arr); }, input);
    runBenchmark("Radix", [](vector<int> &arr)
                 { radixSort(arr); }, input);
    runBenchmark("Heap", [](vector<int> &arr)
                 { heapSort(arr); }, input);

    return 0;
}
