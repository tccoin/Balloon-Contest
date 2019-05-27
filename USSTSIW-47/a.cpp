#include <bits/stdc++.h>

using namespace std;



int main(){
    int T;
    string a,b;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> a >> b;
        if(a=="-0") a="0";
        if(b=="-0") b="0";
        if(a=="0"&&b=="0"){
            cout << "true" << "\n";
            continue;
        }
        if(a[0]=='-'&&b[0]!='-'||a[0]!='-'&&b[0]=='-'){
            if(a[0]=='-')a.erase(0, 1);
            if(b[0]=='-')b.erase(0, 1);
            int asize = a.size();
            int bsize = b.size();
            if(asize!=bsize){
                cout << "false" << "\n";
            }else{
                int s =1;
                for(int i=0;i<asize;i++){
                    if(a[i]!=b[i]){
                        s=0;
                    }
                }
                if(s){
                    cout << "true" << "\n";
                }else{
                    cout << "false" << "\n";
                }
                
            }
            
        }else{
            cout << "false" << "\n";
        }
    }
    
    return 0;
}
