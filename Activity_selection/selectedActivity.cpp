#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
int main(){
    int num;
    cout<<"Enter number of activity: ";
    cin>>num;
    
    int st[num], et[num];
    string items[num];


    for(int i = 0; i < num; i++){

        cout<<"Enter name of activity: ";
        cin>>items[i];

        cout<<"Enter start time for activity "<<i+1<<": ";
        cin>>st[i];

        cout<<"Enter end time for activity "<<i+1<<": ";
        cin>>et[i];
    }

    for(int i = 0; i < num - 1; i++){
        for(int j = 0; j < num - i - 1; j++){
            if(et[j] > et[j+1]){
                swap(et[j],et[j+1]);
                swap(st[j],st[j+1]);
                swap(items[j],items[j+1]);
            }
        }
    }


    int counter = 1;
    int lastEnd = et[0];
    string selectedItems[num];
    int k = 0;
    selectedItems[k++] = items[0];
    for(int i = 1; i<num; i++){
        if(st[i] >= lastEnd){
            counter++;
            lastEnd = et[i];
            selectedItems[k++] = items[i];
        }
    }

    cout<<"Max number of activities : "<<counter<<endl;
    cout<<"Selected items: ";
    for(int i = 0; i < k; i++){
        cout<<selectedItems[i]<<" ";
    }
.
    return 0;
}