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

    int INF = 1e9;

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= amount; j++) {

            dp[i][j] = dp[i - 1][j];

            if(j >= coins[i - 1])
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i - 1]]);
        }
    }

    if(dp[n][amount] == INF)
        cout << "Not possible\n";
    else
        cout << "Minimum Coins = " << dp[n][amount] << endl;

    return 0;
}
