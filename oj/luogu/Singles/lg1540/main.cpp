#include <vector>
#include <iostream> 
#include <algorithm>
using namespace std;
int main() {
    int m, n, t, ans = 0;
    cin >> m >> n;
    vector<int> v;
    for (int i = 0; i<n; i++) {
      cin >> t;
      if (find(v.begin(), v.end(), t) == v.end()) { 
        v.push_back(t);                                  
        ans += 1;
      }
      if (v.size() > m)     
        v.erase(v.begin()); 
    }
    cout << ans << endl;
}