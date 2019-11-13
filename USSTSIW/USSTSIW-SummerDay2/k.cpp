#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,nn=0;
    int input;
    int forbidden;
    bool valid;
    while(scanf("%d",&input)!=EOF){
        if(nn==0){
            n = input;
            scanf("%d",&input);
            valid = true;
            forbidden = 3;
        }
        nn+=1;
        if(input==forbidden){
            valid = false;
        }else{
            forbidden = 6-forbidden-input;
        }
        if(nn==n){
            if(valid){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
            nn = 0;
        }
    }
    return 0;
}
