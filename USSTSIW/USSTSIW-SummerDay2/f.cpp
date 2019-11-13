#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //Efreopen("out.txt","w",stdout);
    int t,road,frog;
    string map;
    cin >> t;
    for(int iii=0;iii<t;iii++){
        road = 0;
        frog = 0;
        cin >> map;
        for(int i=0;i<map.size();i++){
            if(map[i]=='.'){
                road+=1;
            }else if(map[i]=='B'){
                road+=1;
                frog+=1;
            }
        }
        if(frog+1<=road&&frog*2>=road){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
