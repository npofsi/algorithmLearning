#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, q;
long long a[N];
long k, p;
int main()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= q; i++)
	{
		scanf("%lld%lld", &p, &k);
		long long len = p * a[k];
		long long tim = len / m;
		len = len % m;
		if (tim % 2 == 0)
			printf("%lld\n", len);
		else
			printf("%lld\n", m - len);
	}
	return 0;
}