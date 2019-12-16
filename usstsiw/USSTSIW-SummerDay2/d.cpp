#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    unsigned long long t, l, r, k;

    cin >> t;

    for(int i=0;i<t;i++){
        cin >> l >> r >> k;
        if(k%2==1){
            cout << r-l+1 << "\n";
        }else{
            cout << r-l+1-(r/(k+1)-(l-1)/(k+1)) << "\n";
        }
    }


    return 0;
}
