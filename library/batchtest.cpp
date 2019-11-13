for (int iiii = 1; iiii < 66; iiii++) {
  string url = "C:\\Users\\Tccoin\\Downloads\\tc\\E1\\";
  string format1 = ".in";
  string format2 = ".ans";
  // cout << (url + to_string(iiii) + format1);
  freopen((url + to_string(iiii) + format1).c_str(), "r", stdin);
  freopen((url + to_string(iiii) + format2).c_str(), "w", stdout);
}