#include <iostream> 
#include <string> 
using namespace std;

void TowerofHanoi(int n, string S, string D, string H){
    if (n==1){
        cout<<"Disk "<<n<<" From "<<S<<" to "<<D<<endl;
        return;
    }
    else{
        TowerofHanoi(n-1,S,H,D);
        cout<<"Disk "<<n<<" From "<<S<<" to "<<D<<endl;
        TowerofHanoi(n-1,H,D,S);
    }
}

int main(){
    TowerofHanoi(4,"A","B","C");
    return 0;
}