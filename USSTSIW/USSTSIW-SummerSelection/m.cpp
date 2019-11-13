#include <bits/stdc++.h>

using namespace std;

int arr[1000][1000];

int main() {
  int n, s, sum = 0;
  cin >> n;
  for (int i = 1; i < n; i++) {
    s = 0;
    for (int j = 2; j < n; j++) {
      if (n % j == 0 && i % j == 0) {
        s = 1;
      }
    }
    if (s == 0)
      sum++;
  }
  cout << sum;
  return 0;
}
