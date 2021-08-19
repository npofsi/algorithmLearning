#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include<set>
#include <unordered_map>
using namespace std;
typedef struct v2 {
	int from, to;
	int len;
};
unordered_map<int, int> mc;
unordered_map<int, bool> vis;
int sum[2005][2005];
void solve() {

	int n, a[2005];
	int num[2005];
	int maze[2005];
	int pos = 0;
	scanf("%d", &n);
	memset(sum, 0, sizeof(sum));
	memset(maze, 0, sizeof(maze));
	memset(num, 0, sizeof(num));
	vis.clear();
	mc.clear();
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (!vis[a[i]])
		{
			maze[++pos] = a[i];
			vis[a[i]] = 1;
		}
	}
	sort(maze + 1, maze + 1 + pos);
	for (int i = 1; i <= pos; i++)
	{
		mc[maze[i]] = i;
		num[i] = maze[i];
	}
	for (int i = 1; i <= n; i++)
		sum[i][mc[a[i]]] = 1;
	for (int i = 1; i <= pos; i++)
		for (int j = 1; j <= n; j++)
			sum[j][i] += sum[j - 1][i];
	int ans = 0;
	for(int i=1;i<=n-2;i++)
		for (int j = i + 2; j <= n; j++)
		{
			int mid = a[i] + a[j];
			if (mid % 2 == 1)continue;
			mid = mid / 2;
			ans += sum[j - 1][mc[mid]] - sum[i][mc[mid]];
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