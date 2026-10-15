#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

// ---------- MAX HEAP ----------
void maxHeapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void maxHeapSort(vector<int>& arr)
{
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Sort
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// ---------- MIN HEAP ----------
void minHeapify(vector<int>& arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void minHeapSort(vector<int>& arr)
{
    int n = arr.size();

    // Build min heap
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    // Sort
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }

    // Reverse for ascending order
    reverse(arr.begin(), arr.end());
}

// ---------- PRINT ARRAY ----------
void printArray(const vector<int>& arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

// ---------- MAIN ----------
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> original(n);

    srand(time(0));

    // Generate random numbers
    for (int i = 0; i < n; i++)
        original[i] = rand() % 100000;

    vector<int> maxArr = original;
    vector<int> minArr = original;

    // MAX HEAP SORT
    auto startMax = high_resolution_clock::now();
    maxHeapSort(maxArr);
    auto endMax = high_resolution_clock::now();

    // MIN HEAP SORT
    auto startMin = high_resolution_clock::now();
    minHeapSort(minArr);
    auto endMin = high_resolution_clock::now();

    // Calculate time
    double maxTime = duration<double>(endMax - startMax).count();
    double minTime = duration<double>(endMin - startMin).count();

    // Display results
    cout << "\nOriginal Array:\n";
    printArray(original);

    cout << "\nSorted using Max Heap:\n";
    printArray(maxArr);
    cout << "Time: " << maxTime << " seconds\n";

    cout << "\nSorted using Min Heap:\n";
    printArray(minArr);
    cout << "Time: " << minTime << " seconds\n";

    return 0;
}
