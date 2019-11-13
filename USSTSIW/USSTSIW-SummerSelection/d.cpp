#include <bits/stdc++.h>

using namespace std;

struct DisjointSet {
  vector<int> father, rank;
  int num;
  DisjointSet(int n) : father(n), rank(n) {
    num = n;
    for (int i = 0; i < n; i++)
      father[i] = i;
  }
  int find(int v) { return father[v] = father[v] == v ? v : find(father[v]); }
  void merge(int x, int y) {
    int a = find(x), b = find(y);
    if (a != b)
      num--;
    if (rank[a] < rank[b]) {
      father[a] = b;
    } else {
      father[b] = a;
      if (rank[b] == rank[a]) {
        ++rank[a];
      }
    }
  }
};

struct tuitem {
  int x, y, index;
  bool operator<(const tuitem b) const { return index < b.index; }
};

tuitem tu[200000];
int kk[200000];
int aa[200000];
int rr[200000];

int main() {
  // freopen("C:\\Users\\Tccoin\\codes\\balloon-contest\\USSTSIW-"
  //         "SummerSelection\\d.in",
  //         "r", stdin);
  // freopen("C:\\Users\\Tccoin\\codes\\balloon-contest\\USSTSIW-"
  //         "SummerSelection\\d.out",
  //         "w", stdout);
  int n, m, k, i1, i2;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> i1 >> i2;
    tu[i] = tuitem{i1 - 1, i2 - 1};
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> kk[i];
    kk[i]--;
    aa[kk[i]] = k - 1 - i;
  }
  for (int i = 0; i < m; i++) {
    // 以星球编号大的作为航道编号，只有两个星球都enable了该航道才可用
    tu[i].index = max(aa[tu[i].x], aa[tu[i].y]);
  }
  // 给航道排序，后面就不用循环查询哪个航道可用了
  sort(tu, tu + m);
  DisjointSet set(n);

  int j = 0;
  for (int i = 0; i < k; i++) {
    rr[k - 1 - i] = set.num - (k - i);
    for (; tu[j].index == i; j++) {
      set.merge(tu[j].x, tu[j].y);
    }
  }
  for (int i = 0; i < k; i++) {
    cout << rr[i] << "\n";
  }
  return 0;
}