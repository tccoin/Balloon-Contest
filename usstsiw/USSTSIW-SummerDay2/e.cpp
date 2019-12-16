#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int maxval=-1,minval=-1;
    int n,q;
    int operation, l,r,x,v;
    int ai[100000];
    int maxlist[100000][100000];
    int minlist[100000][100000];

    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> ai[i];
        if(maxval==-1||ai[i]>maxval)maxval = ai[i];
        if(minval==-1||ai[i]<minval)minval = ai[i];
        maxlist[i] = maxval;
        minlist[i] = minval;
    }
    for(int i=0;i<q;i++){
        cin >> operation;
        if(operation==1){
            cin >> l >> r;
        }else{
            cin >> q >> v;
        }
    }


    return 0;
}
