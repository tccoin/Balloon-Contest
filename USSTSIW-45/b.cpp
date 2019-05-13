#include <iostream>

using namespace std;

bool row[200001] = {0};
bool col[200001] = {0};

int main() {
  int n, m, input;

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> input;
      if (input) {
        row[i] = !row[i];
        col[j] = !col[j];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> input;
      if (input) {
        row[i] = !row[i];
        col[j] = !col[j];
      }
    }
  }

  bool yes = true;
  
  cout << "\n";

  for (int i = 0; i < n; i++) {
    if (row[i]) {
      yes = false;
      break;
    }
  }
  for (int j = 0; j < m; j++) {
    if (col[j]) {
      yes = false;
      break;
    }
  }

  if (yes) {
    cout << "Yes";
  } else {
    cout << "No";
  }

  return 0;
}
