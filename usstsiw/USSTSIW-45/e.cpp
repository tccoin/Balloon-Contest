#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    float tmp = 0;
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> x;
        tmp = sqrt((x-1)*2 + 0.25)-0.5;
        cout << (tmp==floor(tmp)) << "\n";
    }
    
    return 0;
} 


