#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int profit[] = {0,1,2,6,5};
    int weight[] = {0,2,3,4,5};

    int capacity = 8;
    int n = 4;

    int k[n+1][capacity+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= capacity; j++){
            if(i == 0 || j == 0)
                k[i][j] = 0;

            else if(weight[i] <= j){
                k[i][j] = max(k[i-1][j],
                profit[i] + k[i-1][j-weight[i]]);
            }
                

            else
                k[i][j] = k[i-1][j];
        }
    }

    cout << k[n][capacity] << endl;
    return 0;
}
