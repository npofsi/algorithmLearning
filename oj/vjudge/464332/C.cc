#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define db double
using namespace std;
int cas = 0;

void solve()
{
    int n;
    db arr[10010];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &arr[i]);
    }
    sort(arr, arr + n, std::greater<db>());
    db p = 0;
    db q = 1;
    db fp = arr[0];
    if (fp >= 0.5)
    {
        printf("%.12f\n", arr[0]);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {

            p = (arr[i] * q + (1 - arr[i]) * p);
            q = q * (1 - arr[i]);
            if (p > fp)
            {
                fp = p;
            }
        }

        printf("%.12f\n", fp);
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        solve();
    }
    return 0;
}