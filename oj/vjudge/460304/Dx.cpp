#include <iostream>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int maxn = 2e5 + 9;
ll a[maxn];
int n;
bool check(ll x) {
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < x)sum += (x - a[i]);
	}
	if (sum <= x)return 1;
	return 0;
}
int main() {
	int t;
	cin >> t;
	int cas = 0;
	while (t--) {

		cin >> n;
		for (int i = 1; i <= n; i++)cin >> a[i];
		ll l = 1, r = 2e10;
		while (l < r) {
			ll mid = l + r >> 1;
			if (check(mid))l = mid + 1;
			else r = mid;
		}
		printf("Case #%d: %d\n", ++cas, r);
	}
	return 0;
}