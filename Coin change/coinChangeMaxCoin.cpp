#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, amount;
    cin >> n;

    vector<int> coins(n);
    for(int i = 0; i < n; i++)
        cin >> coins[i];

    cin >> amount;

    vector<vector<long long>> dp(n + 1, vector<long long>(amount + 1, 0));

    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= amount; j++) {

            dp[i][j] = dp[i - 1][j];

            if(j >= coins[i - 1])
                dp[i][j] += dp[i][j - coins[i - 1]];
        }
    }

    cout << "Total Combinations = " << dp[n][amount] << endl;

    return 0;
}