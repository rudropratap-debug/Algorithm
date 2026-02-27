#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num, amount;

    cout<<"Enter number total of coins: ";
    cin >> num;

    vector<int> coins(num);
    cout<<"Enter selection of coins: ";
    for(int i = 0; i < num; i++)
        cin >> coins[i];

    cout<<"Enter amount: ";
    cin >> amount;

    vector<vector<long long>> dp(num + 1, vector<long long>(amount + 1, 0));

    for(int i = 0; i <= num; i++)
        dp[i][0] = 1;

    for(int i = 1; i <= num; i++) {
        for(int j = 1; j <= amount; j++) {

            dp[i][j] = dp[i - 1][j];

            if(j >= coins[i - 1])
                dp[i][j] += dp[i][j - coins[i - 1]];
        }
    }

    cout << "Total Combinations = " << dp[num][amount] << endl;

    return 0;
}