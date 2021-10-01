#include <iostream>
#include <string>
#include <cstring>
#include <regex>
const int mod = 998244353;
using namespace std;


long long arr[5050];

long long jc(long long n)
{
	long long ans = 1;
	for (int i = 1; i <= n; i++)
		ans *= i, ans%=mod;
	return ans;
}
long long C(long long n, long long k)
{
	return jc(n) / jc(k) / jc(n - k);
}
long long A(long long n, long long k)
{
	return jc(n) / jc(n - k);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

	}
	return 0;
}