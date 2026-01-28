#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    // +1 for dummy 0th index
    int profit[n+1], weight[n+1];

    profit[0] = 0;
    weight[0] = 0;

    for(int i = 1; i <= n; i++){
        cout<<"Enter profit of item "<< i<<": ";
        cin>>profit[i];

        cout<<"Enter weight of item "<<i<<": ";
        cin>>weight[i];
    }

    int capacity;
    cout<<"Enter capacity: ";
    cin>>capacity;

    // DP table
    int k[n+1][capacity+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= capacity; j++){
            if(i == 0 || j == 0)
                k[i][j] = 0;
            else if(weight[i] <= j)
                k[i][j] = max(k[i-1][j],
                profit[i] + k[i-1][j - weight[i]]);
            else
                k[i][j] = k[i-1][j];
        }
    }

    cout<<"Maximum Profit = "<<k[n][capacity]<<endl;

    return 0;
}
