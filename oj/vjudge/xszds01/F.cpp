#include<iostream>
#include<string>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e8 + 10;
int prime[100010];
int tot;
bool vis[N];
int num[10010];
void p(int maxn)
{
	for (int i = 2; i <= maxn; i++)
	{
		if (!vis[i])
			prime[++tot] = i;
		for (int j = 1; j <= tot && i * prime[j] <= maxn; j++)
			vis[i * prime[j]] = 1;
	}
}
void solv(int a)
{
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
		{
			num[++num[0]] = i;
			num[++num[0]] = a / i;
		}
	}
	sort(num + 1, num + 1 + num[0]);
}
int main()
{
	vis[1] = 1;
	int n, m;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		if (m % n == 0)
		{
			cout << 0 << endl;
			continue;
		}
		if (n > m)
		{
			cout << n - m << endl;
			continue;
		}
		if (m > n)
		{

			int x = m / n+1;
			int ans = 1e9;
			ans = min(ans, x * n - m);
			p(m);
			if(!vis[m])
			cout << ans << endl;
			else
			{
				
			}
		}
	}
	return 0;
}