#include <bits/stdc++.h>

using namespace std;

int main() {
  // freopen("USSTSIW-SummerDay3//in.txt", "r", stdin);
  // freopen("USSTSIW-SummerDay3//out.txt", "w", stdout);
  long long s;
  long long n = 1;
  long long r = 1;
  long long sum = 1;
  long long rsum = 1;

  cin >> s;

  while (true) {
    n++;
    sum += n;
    if (sum > s)
      break;
    if ((s - sum) % n == 0) {
      r = n;
      rsum = sum;
    }
  }
  cout << (s - rsum) / r + 1 << " " << (s - rsum) / r + r;

  return 0;
}
