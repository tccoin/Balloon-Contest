#include <bits/stdc++.h>

using namespace std;

int arr[1000][1000] = {0};

int main(){
    int n, s, min, losti, lostj;
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    s = 0;
    
    for(int i=0;i<n;i++){
        min = 10001;
        for(int j=0;j<n;j++){
            if(arr[i][j]<min) min=arr[i][j];
        }
        if(min==-1){
            losti = i;
            continue;
        }
        s += min;
        for(int j=0;j<n;j++){
            arr[i][j] -= min;
        }
    }
    
    for(int j=0;j<n;j++){
        min = 10001;
        for(int i=0;i<n;i++){
            if(arr[i][j]<min) min=arr[i][j];
        }
        if(min==-1){
            lostj = j;
            continue;
        }
        s += min;
        for(int i=0;i<n;i++){
            arr[i][j] -= min;
        }
    }
    
    int failx, faily;
    
    if(losti>0) failx = arr[losti-1][lostj];
    else        failx = arr[losti+1][lostj];
    
    if(lostj>0) faily = arr[losti][lostj-1];
    else        faily = arr[losti][lostj+1];
    
    s += failx+faily;
    
    cout << failx+faily << " " << s;
    
    return 0;
} 
