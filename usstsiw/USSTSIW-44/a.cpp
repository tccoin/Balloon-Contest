#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, n, x, y, dx, dy;
    cin >> t >> n >> x >> y >> dx >> dy;
    
    bool test1 = t==0;
    bool test2 = (x-t)%dx==0&&(x-t)/dx>=0&&(x-t)/dx<n;
    bool test3 = (y-t)%dy==0&&(y-t)/dy>=0&&(y-t)/dy<n;
    
    if(test1||test2||test3){
        cout << "YES";
        return 0;
    }
    
    int i, j, xs[300], len, newY;
    for(i=0;i<n;i++){
        xs[i] = x - dx * i;
    }
    len = i+1;
    for(i=0;i<n;i++){
        newY = y - dy * i;
        for(j=0;j<len;j++){
            if(xs[j]+newY==t){
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "No";
    return 0;
} 
