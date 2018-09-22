#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct {
  int x, y;
  int p, q;
}group;
vector<group> vx, vy;
int main() {
  int M, N, K, L, D;
  cin >> M >> N >> K >> L >> D;
  for (int i = 0; i < D; i++) {
    group g;
    cin >> g.x >> g.y >> g.p >> g.q;
    if (g.x == g.p)vy.push_back(g);
    if (g.y == g.q)vx.push_back(g);
  }
return 0;
 }