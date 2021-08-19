#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
typedef struct v2 {
	int from, to;
	int len;
};
vector<int> diff;

unordered_map<int, vector<v2> > mc;
void solve() {

	int n, a[2005], i, j, k;
	int ans = 0;
	diff.clear();
	mc.clear();
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{

		scanf("%d", &a[i]);

	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i+1; j < n; j++) {
			if (i != j) {
				int d = a[j] - a[i];
				v2 v = { j,i,d };
				if (mc.count(d) <= 0) {
					mc[d] = vector<v2>();
				}
				mc[d].push_back(v);
			}
		}
	}

	/*for (auto it = mc.begin(); it != mc.end(); it++) {
		vector<v2>& vs = it->second;
		int len = vs.size();
		cout << it->first << "<<<" << endl;
		if (len == 1 || len == 0)continue;
		for (int i = 0; i < len; i++) {
			cout << "[" <<vs[i].from<<"-" <<vs[i].to<< "," <<it->first<< "]" << " ";
		}
		cout << endl;
	}*/

	for (auto it = mc.begin(); it != mc.end(); it++) {
		vector<v2>& vs = it->second;
		int len = vs.size();
		if (len == 1 || len == 0)continue;
		for (int i = 0; i < len - 1; i++) {
			for (int j = i+1; j < len; j++) {
				if (vs[i].to == vs[j].from || vs[i].from == vs[j].to) {
					ans++;
				}
			}
		}
	}

	cout << ans << endl;


}

int main()
{

	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}