#include<bits/stdc++.h>
using namespace std;
int z[21] = {18,16,14,14,14,5,5,5,5,5,5,5,5,5,5,4,4,4,4,4,4};

int cal(int i, int remain, int s){
//    cout << i << " "<< remain << " "<< s << "\n";
    if(i==21) return 100;
    if(remain==z[i]){
        return s+1;
    }else if(remain>z[i]){
        int route1 = cal(i+1,remain-z[i],s+1);
        int route2 = cal(i+1,remain,s);
        return route1<=route2?route1:route2;
    }else{
        return cal(i+1,remain,s);
    }
}

int main(){
    int T,x;
    int s;
    for(int x=0;x<201;x++){
        if(x==150){
            cout << 0 << "\n";
        }else{
            s = cal(0,150-x,0);
            if(s<100){
                cout << s << "\n";
            }else{
                cout << -1 << "\n";
            }
        }
        
    }
    return 0;
}
