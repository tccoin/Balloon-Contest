#include <bits/stdc++.h>

using namespace std;

const int MAXBIT = 5;

int five[MAXBIT][5];
int pos[MAXBIT];
bitset<MAXBIT> bit[5][MAXBIT];
bitset<MAXBIT> ans;

int main() {
  // freopen("USSTSIW-SummerSelection//h.in", "r", stdin);
  // freopen("USSTSIW-SummerSelection//h.out", "w", stdout);
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> five[i][j];
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < n; j++) {
      pos[five[j][i]] = j;
    }
    bit[i][pos[1]].reset();
    for (int j = 2; j < n + 1; j++) {
      bit[i][pos[j]] = bit[i][pos[j - 1]];
      bit[i][pos[j]].set(pos[j - 1]);
    }
    // for (int j = 0; j < n; j++) {
    //   cout << bit[i][j] << "\n";
    // }
    // cout << "\n";
  }

  for (int i = 0; i < n; i++) {
    ans.set();
    for (int j = 0; j < 5; j++) {
      ans &= bit[j][i];
    }
    cout << ans.count() << "\n";
  }

  return 0;
}
