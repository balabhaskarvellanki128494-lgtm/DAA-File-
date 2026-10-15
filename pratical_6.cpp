#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    // For n matrices, we need n+1 dimensions
    vector<int> p(n + 1);

    cout << "Enter " << n + 1 << " dimensions: ";
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    // DP table
    vector<vector<long long>> m(n + 1,
                                vector<long long>(n + 1, 0));

    // Table to store the best split position
    vector<vector<int>> split(n + 1,
                              vector<int>(n + 1, 0));

    // Dynamic Programming
    for (int chainLength = 2; chainLength <= n; chainLength++)
    {
        for (int i = 1; i <= n - chainLength + 1; i++)
        {
            int j = i + chainLength - 1;

            m[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++)
            {
                long long cost = m[i][k]
                               + m[k + 1][j]
                               + (long long)p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    // Display DP Table
    cout << "\nDP Table:\n\n";

    // Column headings
    cout << setw(8) << " ";

    for (int i = 1; i <= n; i++)
    {
        cout << setw(12) << ("A" + to_string(i));
    }

    cout << endl;

    // Print table
    for (int i = 1; i <= n; i++)
    {
        cout << setw(8) << ("A" + to_string(i));

        for (int j = 1; j <= n; j++)
        {
            if (j >= i)
            {
                cout << setw(12) << m[i][j];
            }
            else
            {
                cout << setw(12) << "-";
            }
        }

        cout << endl;
    }

    // Minimum cost
    cout << "\nMinimum number of scalar multiplications: "
         << m[1][n] << endl;

    // Function to print optimal parenthesization
    cout << "Optimal Parenthesization: ";

    auto printOrder = [&](auto&& self, int i, int j) -> void
    {
        if (i == j)
        {
            cout << "A" << i;
            return;
        }

        cout << "(";

        int k = split[i][j];

        self(self, i, k);
        cout << " x ";
        self(self, k + 1, j);

        cout << ")";
    };

    printOrder(printOrder, 1, n);

    cout << endl;

    return 0;
}
