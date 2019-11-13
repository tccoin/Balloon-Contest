#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,size;
    unsigned long long bitadd[18] = {9, 54, 384, 3024, 25332, 220824, 1978404, 18080424,
167731332, 1574304984, 14914341924, 142364319624,
1367428536132, 13202860761144, 128037802953444, 1246324856379624, 12170706132009732, 119179318935377304};
    unsigned long long result;
    string zo;

    cin >> t;
    for(int i=0;i<t;i++){
        result = 0;
        cin >> zo;
        size = zo.size();
        for(int j=0;j<size;j++){
            if(zo[j]=='1'){
                result += bitadd[size-1-j];
            }
        }
        cout << result << "\n";
    }

}
