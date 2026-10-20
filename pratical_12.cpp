#include <iostream>
#include <climits>
using namespace std;

int n, cost[10][10];
int visited[10];
int minCost = INT_MAX;

void tsp(int city, int count, int totalCost, int start)
{
    if (count == n && cost[city][start] > 0)
    {
        int finalCost = totalCost + cost[city][start];

        if (finalCost < minCost)
            minCost = finalCost;

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && cost[city][i] > 0)
        {
            visited[i] = 1;

            tsp(i, count + 1,
                totalCost + cost[city][i], start);

            visited[i] = 0;
        }
    }
}

int main()
{
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;

    tsp(0, 1, 0, 0);

    if (minCost == INT_MAX)
        cout << "No valid tour exists.";
    else
        cout << "Minimum travelling cost = " << minCost;

    return 0;
}
