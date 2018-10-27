#include <iostream>
using namespace std;
int lxm[5002][5002];
int lc, tc;
int main() {

  cin >> lc >> tc;
  for (int i = 0; i < tc; i++) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 0) {
      lxm[x][y] = 1;
      lxm[y][x] = 1;
    } else if (op == 1) {
      lxm[x][y] = 0;
      lxm[y][x] = 0;
    } else if (op==2) {
      cout << ((lxm[x][y] == 1) ? 'Y' : 'N')<<endl;
    }
  }
  return 0;
	}