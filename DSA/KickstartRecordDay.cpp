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
        int x=0;
        
        if (a[0]>a[1]){
            x++;
        }
        for (int i=1;i<size;i++){
            int c=0;
            if (a[i]>a[i+1] || i==size-1){
                for (int j=0;j<i;j++){
                    if (a[i]>a[j]){
                        c++;
                    }
                }
                if (c==i){
                    x++;
                }
            }
        }   
        cout<<x<<endl;;
    }
    return 0;
}