#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 0;
  long long int s;
  cin >> n;
  if (n == 1) {
    s = 2;
  } else {
    s = 4;
    long long int ox = 1, xo = 1, oo = 1, xx = 1;
    long long int nox, nxo, noo, nxx;
    for (int i = 0; i < n - 2; i++) {
      s = s + xo + xx;
      nox = xo + oo;
      nxo = xx;
      noo = xo;
      nxx = ox + xx;
      ox = nox % 99037660;
      xo = nxo % 99037660;
      oo = noo % 99037660;
      xx = nxx % 99037660;
      s = s % 99037660;
    }
  }
  cout << s % 99037660;
  return 0;
}