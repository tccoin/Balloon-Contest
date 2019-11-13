#include <bits/stdc++.h>

using namespace std;

int ai[100000];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,t,v,x,y,q,ysum=0;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> ai[i];
    }

    for(int i=0;i<m;i++){
        cin >> t;
        if(t==1){
            cin >> v >> x;
            ai[v-1] = x-ysum;
        }else if(t==2){
            cin >> y;
            ysum += y;
        }else if(t==3){
            cin >> q;
            cout << ai[q-1]+ysum << "\n";
        }
    }

    return 0;
}
