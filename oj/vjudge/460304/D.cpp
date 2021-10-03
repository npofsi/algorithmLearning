#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
const int N= 200010;
ll a[N];
int n;
int check(ll h) {
	ll t = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < h)t +=( h - a[i]);
	}
	if (t <= h)return 1;
	return 0;
}
int ca = 0;
void solve() {
	
	scanf("%d", &n);
	ll max=1;
	for (int i = 1; i <= n; i++) {
		ll c;
		scanf("%lld", &c);
		a[i] = c;
		if (c > max)max = c;
	}
	ll l = 1, r = 1.6e10;
	while (l < r) {
		ll mid = (l + r)/2;
		if (check(mid)){ 
			l = mid + 1; 
		}else {
			r = mid;
		}
	}
	printf("Case #%d: %lld\n", ++ca, r);
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		solve();
	}
	return 0;
}