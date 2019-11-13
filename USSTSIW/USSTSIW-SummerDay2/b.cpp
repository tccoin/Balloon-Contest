#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int cup;
    double log3 = log(3);
    while(true){
        cin >> cup;
        if(cup==0)break;
        cout << ceil(log(cup)/log3) << "\n";
    }
    return 0;
}
