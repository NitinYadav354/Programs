#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int MinCoins(vector<int> coins, int Val){
    int count = 0;
    for(int i=coins.size()-1; i>=0 && Val>0; i--){
        if(coins[i]<=Val){
            count += Val/coins[i];
            Val = Val%coins[i];
        }
    }
    return count;
}

int main(){
    vector<int> coins = {1,2,5,10,20,50,100,500,2000};
    int Val = 1099;
    cout<<MinCoins(coins, Val)<<endl;

    return 0;
}