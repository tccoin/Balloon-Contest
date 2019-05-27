#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y,xx,yy;
    cin >> n;
    
    for(int i=n/8;i>=0;i--){
        x = i * 8;
        y = n - x;
        if(x%8==0&&y%5==0){
            for(int j=0;j<y/5;j++){
                cout << 5;
            }
            for(int j=0;j<x/8;j++){
                cout << 8;
            }
            return 0; 
        }
    }

    cout << -1;
    return 0;
}
