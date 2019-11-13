int read() {
  int ret = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    ret = ret * 10 + ch - 48, ch = getchar();
  return ret * f;
}