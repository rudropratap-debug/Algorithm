#include<iostream>
#include<climits>

using namespace std;

int main(){
    int num;
    cout<<"Enter number of coins: ";
    cin>>num;

    int coins[num];
    cout<<"Enter choice of coins: ";

    for(int i = 0;  i < num; i++){
        cin>>coins[i];
    }

    int amount;
    cout<<"Enter amount: ";
    cin>>amount;

    int dp[num + 1][amount + 1];

    // Initialize DP table
    for(int i = 0; i <= num; i++){
        for(int j = 0; j <= amount; j++){
            dp[i][j] = INT_MAX - 1;
        }
    }

    // Base case
    for(int i = 0; i <= num; i++)
        dp[i][0] = 0;

    // Fill DP table
    for(int i = 1; i <= num; i++) {
        for(int j = 1; j <= amount; j++) {
            if(j >= coins[i - 1])
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            else 
                dp[i][j] = dp[i - 1][j];   
        }
    }

    if(dp[num][amount] == INT_MAX - 1)
        cout<<"Coin change not possible"<<endl;
    else
        cout<<"Total coins used : "<<dp[num][amount]<<endl;

    return 0;
}