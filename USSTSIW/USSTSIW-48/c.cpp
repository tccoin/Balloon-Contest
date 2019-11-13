#include<bits/stdc++.h>
using namespace std;
int s[1000];
int main(){
    int n, i,j,x;
    cin >> n;
    for(x=0;x<n-1;x++){
        cin >> s[x];
    }
    cin >> i >> j;
    if(i>j){
        int temp = i;
        i=j;
        j=temp;
    }
    int step = 0;
    for(x=i-1;x<j-1;x++){
        step += s[x];
    }
    cout << step;
    return 0;
}
