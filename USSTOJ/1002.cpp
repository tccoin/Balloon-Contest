#include <bits/stdc++.h>

using namespace std;

int main() {
  int tttt, ttt;
  cin >> tttt;
  for (ttt = 0; ttt < tttt; ttt++) {
    int i, j;

    // input
    int n, n1, input, nNeg = 0, s = 0;
    int arr[200];

    cin >> n;
    n1 = 2 * n - 1;
    for (i = 0; i < n1; i++) {
      cin >> input;
      arr[i] = abs(input);
      nNeg += input < 0 ? 1 : 0;
    }

    sort(arr, arr + n1);

    int mustBeNeg = min(nNeg % n, n - nNeg % n);

    for (i = 0; i < n1; i++) {
      s += arr[i] * (i < mustBeNeg ? -1 : 1);
    }

    cout << s;
  }
  return 0;
}
