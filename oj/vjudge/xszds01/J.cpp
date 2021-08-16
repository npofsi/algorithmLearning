#include<iostream>
#include<string>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
#define pa pair<int,int>
using namespace std;
int n, m, t;
const int N = 1e6 + 10;
struct lq {
	int to;
	int nxt;
	int val;
}node[N<<1];
int head[N], tot;
int d[N];
int a[N];
int w[N];
int v[N];
int f[N];
int maze[3005][3005];
priority_queue<pa, vector<pa>, greater<pa> >Q;
void add(int u, int v, int val)
{
	node[++tot].nxt = head[u];
	node[tot].to = v;
	node[tot].val = val;
	head[u] = tot;
}
void dij()
{
	memset(d, 0x7f7f7f, sizeof(d));
	d[1] = 0;
	Q.push(make_pair(0, 1));
	while (Q.size())
	{
		int u = Q.top().second;
		int dis = Q.top().first;
		Q.pop();
		if (dis > d[u])continue;
		for (int i = head[u]; i; i = node[i].nxt)
		{
			int v = node[i].to;
			if (d[v] > d[u] + node[i].val)
			{
				d[v] = d[u] + node[i].val;
				Q.push(make_pair(d[v], v));
			}
		}
	}
}
int main()
{
	cin >> n >> m >> t;
	for (int i = 2; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		if (u == v)continue;
		maze[u][v] = maze[v][u] = 1;
	}
	for(int i=1;i<=n-1;i++)	
		for (int j = i+1; j <= n; j++)
		{
			if (maze[i][j])
			{
				add(i, j, 1);
				add(j, i, 1);
			}
		}
	dij();
	for (int i = 2; i <= n; i++)
	{
		w[i] = 2 * d[i];
		v[i] = a[i];
	}
	for(int i=2;i<=n;i++)	
		for (int j = w[i]; j <= t; j++)
		{
			f[j] = max(f[j], f[j-w[i]] +v[i]);
		}
	for (int i = 1; i <= t; i++)
		cout << f[i] << " ";
	cout << endl;
	return 0;
}