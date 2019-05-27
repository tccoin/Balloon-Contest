#include<bits/stdc++.h>
using namespace std;

int b[10000];
int c[10000];

int n,a;

void bm1(){
    int temp;
    for(int i=0;i<n/2;i++){
        temp = b[2*i];
        b[2*i] = b[2*i+1];
        b[2*i+1] = temp;
    }
}

void cm1(){
    int temp;
    for(int i=0;i<n/2;i++){
        temp = c[2*i];
        c[2*i] = c[2*i+1];
        c[2*i+1] = temp;
    }
}

void bm2(){
    int temp;
    int g = (n+1)/2;
    for(int i=0;i<n/2;i++){
        temp = b[i];
        b[i] = b[i+g];
        b[i+g] = temp;
    }
}

void cm2(){
    int temp;
    int g = (n+1)/2;
    for(int i=0;i<n/2;i++){
        temp = c[i];
        c[i] = c[i+g];
        c[i+g] = temp;
    }
}

int equal(){
    for(int i=0;i<n;i++){
        if(b[i]!=c[i])return 0;
    }
    return 1;
}

int calc(){
    int s = 0;
    while(1){
        s++;
        if(s%2==0){
            bm1();
            cm2();
        }else{
            bm2();
            cm1();
        }
        if(equal()) return 2*s;
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        b[i] = a;
        c[i] = a;
    }
    
    if(n==1){
        cout << 1;
    }else if(n==2){
        cout << 2;
    }else {
        cout << calc();
    }

    return 0;
}
