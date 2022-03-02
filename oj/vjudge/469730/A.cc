#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define ll long long int
using namespace std;

ll period[10005];
ll value[10005];
ll dp[1000500];
ll maxe(ll a, ll b)
{
    return a > b ? a : b;
}

int main()
{
    ll t, m;
    scanf("%lld%lld", &t, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld", period + i, value + i);
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = period[i]; j <= t; j++)
        {
            dp[j] = maxe(dp[j], dp[j - period[i]] + value[i]);
        }
    }
    printf("%lld", dp[t]);
    return 0;
}