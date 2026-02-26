// Profit / Weight approach for maximum weight 

#include<iostream>
using namespace std;

int main(){

    int num;
    cout<<"Enter number of products : ";
    cin>>num;

    double weight[num], profit[num],ratio[num];
    
    for(int i =  0; i < num; i++){
        cout<<"Enter weight for product "<<i+1<<": ";
        cin>>weight[i];

        cout<<"Enter profit for product "<<i+1<<": ";
        cin>>profit[i];

        ratio[i] = profit[i] / weight[i];
    }

    for(int i = 0; i < num-1;i++){
        for(int j = 0; j < num-i-1;j++){
            if(ratio[j]<ratio[j+1]){
                swap(ratio[j],ratio[j+1]);
                swap(weight[j],weight[j+1]);
                swap(profit[j],profit[j+1]);
            }
        }
    }


    double capacity;
    cout<<"Enter capacity: ";
    cin>>capacity;

    double maxProfit = 0;

    for(int i = 0; i < num; i++){

        if(capacity <= 0)break;

        else if(weight[i] <= capacity){
        maxProfit += profit[i];
        capacity -= weight[i];
        }

        else {
            maxProfit += ratio[i] * capacity;
            capacity = 0;
        }
        
    }

    cout<<"Max profit: ";
    cout<<maxProfit<<endl;

    return 0;
}