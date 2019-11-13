#include <bits/stdc++.h>

using namespace std;

bool isPrime(int num) {
  for (int i = 2; i < num; i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

int main() {
  // freopen("USSTSIW-SummerDay3//in.txt", "r", stdin);
  // freopen("USSTSIW-SummerDay3//out.txt", "w", stdout);
  int n, next, prev;
  cin >> n;
  if (isPrime(n)) {
    cout << 0;
  } else {
    for (int i = n - 1; i > 1; i--) {
      if (isPrime(i)) {
        prev = i;
        break;
      }
    }
    for (int i = n + 1; i < 1299710; i++) {
      if (isPrime(i)) {
        next = i;
        break;
      }
    }
    cout << (next - prev);
  }
  return 0;
}
