#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, amount;
    cout << "Enter the number of coins: ";
    cin >> n;

    int coin[n];

    for (int i = 0; i < n; i++)
        cin >> coin[i];

    sort(coin, coin + n);

    cout << "Enter the amount: ";
    cin >> amount;
    int table[n + 1][amount + 1];
    for (int i = 0; i <= n; i++)
        table[i][0] = 0;
        
    for (int j = 1; j <= amount; j++)
        table[0][j] = amount + 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (j >= coin[i - 1])
            {
                table[i][j] = min(table[i - 1][j],
                    (1 + table[i][j - coin[i - 1]]));
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }
    cout << "Minimum number of coin is: " << table[n][amount] << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << coin[i - 1];
        for (int j = 0; j <= amount; j++)
        {
            cout << " " << table[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}