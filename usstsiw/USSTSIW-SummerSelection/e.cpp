#include <bits/stdc++.h>

using namespace std;

int s[100000];

int main() {
  // freopen((url + to_string(iiii) + format1).c_str(), "r", stdin);
  // freopen((url + to_string(iiii) + format2).c_str(), "w", stdout);
  int n = 0, lf = 0, lfm, input;
  cin >> n;
  lfm = -1;
  for (int i = 0; i < n; i++) {
    cin >> input;
    if (input != 1) {
      if (lfm == -1)
        lfm = i;
      for (; lf <= i; lf++) {
        s[lf] = i - lf;
      }
    } else {
      if (i == n - 1) {
        if (lfm == -1) {
          for (; lf <= i; lf++) {
            s[lf] = n - 1;
          }
        } else {
          for (; lf <= i; lf++) {
            s[lf] = lfm + n - lf;
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (s[i] % 2 == 0)
      cout << "Haruhi go first.\n";
    else
      cout << "Haruhi go secondary.\n";
  }
}
