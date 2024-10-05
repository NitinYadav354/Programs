#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;    

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second > p2.second;
}

int maxProfit(vector<pair<int, int>> jobs){
    sort(jobs.begin(), jobs.end(), compare);
    int profit = jobs[0].second;
    int SafeDeadline = 2;

    for(int i=1; i<jobs.size(); i++){
        if(jobs[i].first >= SafeDeadline){
            profit += jobs[i].second;
            SafeDeadline++;
        }   
    }
    return profit;
}

int main(){
    int n = 4;
    vector<pair<int, int>> Jobs(n, make_pair(0,0));
    Jobs[0] = make_pair(4,20);
    Jobs[1] = make_pair(1,10);
    Jobs[2] = make_pair(1,40);
    Jobs[3] = make_pair(1,30);

    cout<<"Max profit: "<<maxProfit(Jobs)<<endl;
    return 0;

}