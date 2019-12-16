#include "bits/stdc++.h"

using namespace std;

int map[8][8];

int main(){
    int n, m, t, input;
    
    cin >> n >> m >> 
    vector<vector<int>> arr(n,vector(m));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;i++){
            cin >> map[i][j];
            if(map[i][j]=="s"){
                sx = i;
                sy = j;
            }else if(map[i][j]=="p"){
                px = i;
                py = j;
            }
        }
    }
    
    bool win  = false;
    int  step = 0;
    int posx, posy;
    
}
