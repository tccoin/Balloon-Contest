#include <bits/stdc++.h>

using namespace std;

const double PI = 3.1415926535897;
int xx1, yy1, r, xx2, yy2, R;
double ll1, //公共边
    ang1,   // r圆心角
    ang2,   // R圆心角
    dis;    //圆心距

double calc() {
  cin >> xx1 >> yy1 >> r >> xx2 >> yy2 >> R;
  dis = sqrt((xx1 - xx2) * (xx1 - xx2) + (yy1 - yy2) * (yy1 - yy2));
  if (dis > r + R) {
    return 0;
  } else if (dis <= r - R) {
    return float(R * R) / float(r * r);
  } else if (dis <= R - r) {
    return 1;
  } else {
    ang1 = 2 * acos((dis * dis + r * r - R * R) / (2 * dis * r));
    ang2 = 2 * acos((dis * dis - r * r + R * R) / (2 * dis * R));
    ll1 = sin(ang1 / 2) * r * 2;
    return (0.5 * ang1 * r * r + 0.5 * ang2 * R * R - ll1 * dis / 2) /
           (PI * r * r);
  }
}

int main() {
  freopen("USSTSIW-SummerSelection//g.in", "r", stdin);
  freopen("USSTSIW-SummerSelection//g.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << fixed << setprecision(4) << calc() << "\n";
  }
  return 0;
}
