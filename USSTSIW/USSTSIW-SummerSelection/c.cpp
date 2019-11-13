#include <bits/stdc++.h>

using namespace std;

int arr[1000][1000];

int main() {
  int m, n, input;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      arr[i][j] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> input;
      if (input % 2 == 1) {
        arr[i][j] = !arr[i][j];
        if (i >= 1) {
          arr[i - 1][j] = !arr[i - 1][j];
        }
        if (j >= 1) {
          arr[i][j - 1] = !arr[i][j - 1];
        }
        if (i <= n - 2) {
          arr[i + 1][j] = !arr[i + 1][j];
        }
        if (j <= m - 2) {
          arr[i][j + 1] = !arr[i][j + 1];
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << arr[i][j];
    }
    cout << "\n";
  }
  cout << "\n";
  return 0;
}
