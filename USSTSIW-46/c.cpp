#include "bits/stdc++.h"

using namespace std;

int main(){
    int n;
    unsigned long long int a, b;
    long double x1, x2, x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        x1 = b * 0.012f / 23.0f;
        x2 = (floor(a/1000)*11.0f+floor(a%1000/100))*0.012f/23.0f;
        x  = x1 + x2;
        cout << setprecision(3) << fixed << x << "\n";
    }
    return 0;
}
