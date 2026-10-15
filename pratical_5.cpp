#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, capacity;

    // Number of items
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n);
    vector<int> profit(n);

    // Input weights
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    // Input profits
    cout << "Enter profits: ";
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }

    // Input capacity
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // DP table
    vector<vector<int>> dp(n + 1,
                           vector<int>(capacity + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= capacity; w++)
        {
            if (weight[i - 1] <= w)
            {
                // Maximum of:
                // 1. Don't take item
                // 2. Take item
                dp[i][w] = max(
                    dp[i - 1][w],
                    profit[i - 1] +
                    dp[i - 1][w - weight[i - 1]]
                );
            }
            else
            {
                // Item cannot fit
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Display maximum profit
    cout << "\nMaximum profit: "
         << dp[n][capacity] << endl;

    // 0/1 array
    vector<int> selected(n, 0);

    // Find selected items
    int w = capacity;

    for (int i = n; i >= 1; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            selected[i - 1] = 1;
            w = w - weight[i - 1];
        }
    }

    // Display 0/1 solution
    cout << "\n0/1 Selection:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1
             << ": " << selected[i] << endl;
    }

    // Display total weight
    int totalWeight = 0;

    for (int i = 0; i < n; i++)
    {
        if (selected[i] == 1)
        {
            totalWeight += weight[i];
        }
    }

    cout << "\nTotal weight: " << totalWeight << endl;
    cout << "Maximum profit: " << dp[n][capacity] << endl;

    return 0;
}
