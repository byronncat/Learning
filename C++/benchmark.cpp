#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

#define main merge_sort_main
#include "merge-sort.cpp"
#undef main

#define main quick_sort_main
#include "quick-sort.cpp"
#undef main

#define main radix_sort_main
#include "radix-sort.cpp"
#undef main

template <typename SortFunc>
void runBenchmark(const string &name, SortFunc sortFn, vector<int> data)
{
    auto start = chrono::high_resolution_clock::now();
    sortFn(data);
    auto end = chrono::high_resolution_clock::now();

    double elapsedMs = chrono::duration<double, milli>(end - start).count();

    cout << left << setw(10) << name << " | "
         << setw(10) << fixed << setprecision(3) << elapsedMs << " ms\n";
}

int main()
{
    const int size = 100000;
    vector<int> input(size);
    iota(input.begin(), input.end(), 1);

    mt19937 rng(42);
    shuffle(input.begin(), input.end(), rng);
    // for (int i = 0; i < input.size(); i++)
    //     input[i] = i + 1;

    cout << "Sorting benchmark\n";
    cout << "Algorithm" << setw(10) << " | Time (ms)\n";
    cout << "------------------------------\n";

    runBenchmark("Merge", [](vector<int> &arr)
                 { mergeSort(arr); }, input);
    runBenchmark("Quick", [](vector<int> &arr)
                 { quickSort(arr); }, input);
    runBenchmark("Radix", [](vector<int> &arr)
                 { radixSort(arr); }, input);

    return 0;
}
