#include <bits/stdc++.h>

using namespace std;

long ai[1000];

int main(){
    long n,t,s=0,k=0;
    cin >> n >> t;
    for(int i=0;i<n;i++){
        cin >> ai[i];
    }
    sort(ai,ai+n);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(ai[j]-ai[i]<=t){
                s+=1;
            }else{
                break;
            }
        }
    }
    cout << s*2;
    return 0;
}
