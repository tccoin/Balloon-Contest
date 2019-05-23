#include "bits/stdc++.h"

using namespace std;

int main(){
    int size, n, use;
    cin >> size >> n;
    vector<int> v(n, 0);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    sort(v.begin(),v.begin()+n,greater<int>());
    
    use = 0;
    int another;
    int nn = n;
    int ii = 0;
    __gnu_cxx::__normal_iterator<int*, std::vector<int> > r;
    while(ii<nn){
        r = upper_bound(v.begin()+1,v.begin()+nn-1, size - v[ii],greater<int>());
        if(*r<=size - v[ii]){
            v.erase(r);
            nn--;
        }
        ii++;
    }
    
    cout << ii;

//    for(int i=0; i<n; i++){
//        cout << v[i] << " ";
//    }
    return 0;
}
