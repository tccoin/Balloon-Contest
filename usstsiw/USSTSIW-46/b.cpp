#include "bits/stdc++.h"

using namespace std;

int map[9][9];
//A 65
int main(){
    int T;
    cin >> T;
    char c1,c2;
    int  si,sj,di,dj;
    int ii,jj;
    for(int t=0;t<T;t++){
        cin >> c1 >> si >> c2 >> di;
        sj = c1 - 65;
        dj = c2 - 65;
        si = si - 1;
        di = di - 1;
    
        map[si][sj] = 0;
        int maxstep = (abs(si-di)+abs(sj-dj))*3;
        for(int step=0;step<maxstep;step++){
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    if(map[i][j]==step){
                        ii = i - 2;
                        jj = j - 1;
                        if(ii>=0&&jj>=0&&ii<9&&jj<9) map[ii][jj] = step + 1;
                        
                        ii = i - 2;
                        jj = j + 1;
                        if(ii>=0&&jj>=0&&ii<9&&jj<9) map[ii][jj] = step + 1;
                        
                        ii = i + 2;
                        jj = j - 1;
                        if(ii>=0&&jj>=0&&ii<9&&jj<9) map[ii][jj] = step + 1;
                        
                        ii = i + 2;
                        jj = j + 1;
                        if(ii>=0&&jj>=0&&ii<9&&jj<9) map[ii][jj] = step + 1;

                        ii = i - 1;
                        jj = j - 2;
                        if(ii>=0&&jj>=0&&ii<9&&jj<9) map[ii][jj] = step + 1;
                        
                        ii = i - 1;
                        jj = j + 2;
                        if(ii>=0&&jj>=0&&ii<9&&jj<9) map[ii][jj] = step + 1;
                        
                        ii = i + 1;
                        jj = j - 2;
                        if(ii>=0&&jj>=0&&ii<9&&jj<9) map[ii][jj] = step + 1;
                        
                        ii = i + 1;
                        jj = j + 2;
                        if(ii>=0&&jj>=0&&ii<9&&jj<9) map[ii][jj] = step + 1;
                        }
                }
                        if(map[])
            }
        }
    }
    return 0;
}
