#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Iterative Factorial using while loop
unsigned long long factorialWhile(int n)
{
    unsigned long long result = 1;

    while (n > 0)
    {
        result *= n;
        n--;
    }

    return result;
}

// Recursive Factorial
unsigned long long factorialRecursive(int n)
{
    if (n <= 1)
        return 1;

    return n * factorialRecursive(n - 1);
}

int main()
{
    int n;

    cout << "Enter a non-negative integer (e.g., 20): ";
    cin >> n;

    if (n < 0)
    {
        cout << "Invalid input! Please enter a non-negative integer.";
        return 1;
    }

    // Measure While Loop
    auto startWhile = high_resolution_clock::now();
    unsigned long long resWhile = factorialWhile(n);
    auto endWhile = high_resolution_clock::now();

    duration<double, nano> durationWhile = endWhile - startWhile;

    // Measure Recursive
    auto startRec = high_resolution_clock::now();
    unsigned long long resRec = factorialRecursive(n);
    auto endRec = high_resolution_clock::now();

    duration<double, nano> durationRec = endRec - startRec;

    // Output
    cout << "\n--- Results for " << n << "! ---" << endl;
    cout << "While Loop Result : " << resWhile << endl;
    cout << "While Loop Time   : " << durationWhile.count() << " ns" << endl;
    cout << "-------------------------------" << endl;
    cout << "Recursive Result  : " << resRec << endl;
    cout << "Recursive Time    : " << durationRec.count() << " ns" << endl;

    return 0;
}
