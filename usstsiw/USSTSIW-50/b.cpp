#include <bits/stdc++.h>

using namespace std;

int main(){
    char l;
    int nums=0, numi=0, numw=0;
    
    do{
        l = cin.get();
        if(l=='s'||l=='S') nums++;
        else if(l=='i'||l=='I') numi++;
        else if(l=='w'||l=='W') numw++;
    }
    while(l != '\n');
    
    int complete = min(min(nums, numi), numw);
    nums -= complete;
    numi -= complete;
    numw -= complete;
    for(int i=0;i<complete;i++){
        cout << "SIW";
    }
    
    
    int remainder = max(max(nums, numi), numw);
    for(int i=0;i<remainder;i++){
        if(nums-->0) cout << "S";
        if(numi-->0) cout << "I";
        if(numw-->0) cout << "W";
    }
    
    return 0;
}

