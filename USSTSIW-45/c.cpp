#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> arr(n,vector<int>(m,0));
    
    // input
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    // print color
    int color = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0) arr[i][j] = ++color;
            if(arr[i][j] > 1){
                if(j<m-1&&!arr[i][j+1]){
                    arr[i][j+1] = color;
                }
                if(i<n-1&&!arr[i+1][j]){
                    arr[i+1][j] = color;
                }
            }
        }
    }
    
    // fill the bucket
    vector<int> bucket(color+1, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] > 1){
                bucket[arr[i][j]] += (i+j)%2?1:-1;
            }
        }
    }
    
    // check the bucket
    for(int i=2;i<color+1;i++){
        if(bucket[i]!=0){
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
    return 0;
} 


