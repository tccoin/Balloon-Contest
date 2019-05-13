#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, t, input, min=100001, size=0, start=0;
    int arr[100000] = {0};
    int len[100000] = {0};
    
    cin >> n >> t;
    
    for(int i=0;i<n;i++){
        cin >> input;
        arr[size] = 0;
        len[size] = 0;
        size++;
        for(int j=start;j<size;j++){
            arr[j] += input;
            len[j] ++;
            if(arr[j]>t){
                arr[j] = arr[start];
                len[j] = len[start];
                start++;
            }else if(arr[j]==t){
                if(len[j]<min) min = len[j];
                arr[j] = arr[start];
                len[j] = len[start];
                start++;
            }
        }
    }
    
    if(min==100001){
        cout << "No";
    }else{
        cout << min;
    }
    
    return 0;
} 
