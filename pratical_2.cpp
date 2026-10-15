#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
    int n = 100000;
    vector<int> arr;

    // Store numbers from 1 to 100000
    for (int i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    // Linear Search
    auto start = high_resolution_clock::now();

    auto it = find(arr.begin(), arr.end(), key);

    auto stop = high_resolution_clock::now();

    cout << "\nLinear Search\n";

    if (it != arr.end())
        cout << "Element found at index " << (it - arr.begin()) << endl;
    else
        cout << "Element not found" << endl;

    cout << "Time Taken: "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    // Binary Search
    start = high_resolution_clock::now();

    bool found = binary_search(arr.begin(), arr.end(), key);

    stop = high_resolution_clock::now();

    cout << "\nBinary Search\n";

    if (found)
    {
        auto binaryIt = lower_bound(arr.begin(), arr.end(), key);
        cout << "Element found at index "
             << (binaryIt - arr.begin()) << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    cout << "Time Taken: "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    return 0;
}
