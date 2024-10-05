#include <iostream>
#include <vector>
using namespace std;

bool compare(pair<double, int> p1, pair<double, int> p2){
    return p1.first >p2.first;
}

int fractionKnapsack(vector<int> val, vector<int> wt, int W){
    int n = val.size();
    vector<pair<double, int>> ratio(n, make_pair(0.0, 0));

    for (int i=0; i<n; i++){
        double r = val[i];
        ratio[i] = make_pair(r,i);
    }

    sort(ratio.begin(), ratio.end(), compare);
    int ans=0; 
    for(int i=0; i<n; i++){
        int idx = ratio[i].second;
        if(wt[idx]<=W){
            ans += val[idx];
            W=0;
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> val = {60,100,120};
    vector<int> wt = {10,20,30};
    int W = 50;
    cout<<fractionKnapsack(val, wt, 50);
    return 0;
}