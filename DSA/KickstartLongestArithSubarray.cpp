#include <iostream>
using namespace std;

int main(){
    int tc;
    cout<<"Enter Test Case: ";
    cin>>tc;
    for(int j=0;j<tc;j++){
        int size;
        cout<<"Size: ";
        cin>>size;
        int a[size];
        for (int i=0;i<size;i++){
            cin>>a[i];
        }  
        int c=2;
        int ans=0;
        
        for (int i=0;i<size;i++){
            int d=a[i+1]-a[i];
            if (a[i+2]-a[i+1]==d){
                c++;
            }
            else{
                if (c>ans){
                    ans=c;
                }
                c=2;
            }
        }
        cout<<"Case # "<<j+1<<": "<<ans<<endl;
    }
    return 0;
}