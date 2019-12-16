#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, s;
    while(cin >> n){
        s = 1;
        if (n==0) return 0;
        for(int i=2;i<n/2+1;i++){
            if(n%i==0) s++;
        }
        cout << s << "\n";
    }
    return 0;
}

