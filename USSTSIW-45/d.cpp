#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, t;

  cin >> n >> t;

  int sum[100000];

  cin >> sum[0];
  for (int i = 1; i < n; i++) {
    cin >> sum[i];
    sum[i] += sum[i - 1];
  }

  int m = 100001;
  int lt = 0;

  for (int i = 0; i < n; i++) {
    int *emmmmmmm = lower_bound(sum + i, sum + n - 1, sum[i] + t);
    int ehhhhhhh = *emmmmmmm - sum[i];
    if (ehhhhhhh == t && emmmmmmm - sum - i < m) {
      m = emmmmmmm - sum - i;
    } else if (ehhhhhhh < t) {
      break;
    }
  }

  if (m == 100001)
    cout << "No";
  else
    cout << m;

  return 0;
}
