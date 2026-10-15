#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, amount;

    // Step 1: Take number of coins
    cout << "Enter number of coins: ";
    cin >> n;

    // Step 2: Store coin values
    vector<int> coins(n);

    cout << "Enter the coin values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    // Step 3: Take target amount
    cout << "Enter the amount: ";
    cin >> amount;

    // Step 4: DP array
    vector<int> dp(amount + 1, amount + 1);

    // Step 5: Store the coin used for each amount
    vector<int> usedCoin(amount + 1, -1);

    // Step 6: Base case
    dp[0] = 0;

    // Step 7: Dynamic Programming
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                if (dp[i - coins[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - coins[j]] + 1;

                    // Remember which coin was used
                    usedCoin[i] = coins[j];
                }
            }
        }
    }

    // Step 8: Check whether amount can be made
    if (dp[amount] > amount)
    {
        cout << "Amount cannot be made using the given coins." << endl;
    }
    else
    {
        cout << "Minimum number of coins required: "
             << dp[amount] << endl;

        // Step 9: Display the coins used
        cout << "Coins used: ";

        int currentAmount = amount;

        while (currentAmount > 0)
        {
            int coin = usedCoin[currentAmount];

            cout << coin << " ";

            currentAmount = currentAmount - coin;
        }

        cout << endl;
    }

    return 0;
}
