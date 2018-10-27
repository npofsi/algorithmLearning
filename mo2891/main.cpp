#include <iostream>
using namespace std;
int mis[1002];
int ml[1002];
int pl[1002];
int a=0x0, b;
int main() {
  int n = 1;
  while (cin >> mis[n]) {
    if (n == 7)
      break;
    n++;
  }
  for (int y = 0; y <= n; y++)
    pl[y] = 0;
  for (int i = 1; i <n; i++) {
    for (int j = 1; j < i; j++) {
      if (mis[j] < mis[i]) {
        pl[i] = max(pl[i], pl[j] + 1);
      }
    }
    a = max(pl[i], a);
  }
  for (int i = n-1; i >= 1; i--) {
    ml[i] = 0;
    for (int j = i ; j <= n; j++) {
      if (mis[j] <= mis[i]) {
        ml[i] = max(ml[i], ml[j] + 1);
      }
    }
    b = max(ml[i], b);
  }
  cout << b <<endl<< a;
  return 0;
}