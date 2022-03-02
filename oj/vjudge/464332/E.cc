#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct peo
{
    int song, say;
};
vector<peo> ps = vector<peo>();
bool cmpSong(const int &a, const int &b)
{
    return ps[a].song > ps[b].song;
}
bool cmpSay(const int &a, const int &b)
{
    return ps[a].say > ps[b].song;
}

void solve()
{

    int n = 0;

    scanf("%d", &n);

    ps = vector<peo>();
    vector<int> psong = vector<int>();
    vector<int> psay = vector<int>();

    for (int i = 0; i < n; i++)
    {
        int so, sa;
        scanf("%d%d", &so, &sa);
        peo p = peo{so, sa};
        ps.push_back(p);
        psong.push_back(i);
        psay.push_back(i);
    }
    sort(psong.begin(), psong.end(), cmpSong);
    sort(psay.begin(), psay.end(), cmpSay);
    int dif = 2147483647;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        int bottom;
        if (i != n - 1)
        {

            bottom = max(ps[psong[i + 1]].song, ps[psong[i]].say);
        }
        else
        {
            bottom = ps[psong[i]].say;
        }

        while (j < n && ps[psay[j]].say >= bottom)
        {
            if (psay[j] != psong[i])
            {
                int df = ps[psong[i]].song - ps[psay[j]].say;
                if (df < dif)
                    dif = df;
            }
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int bottom;
        if (i != n - 1)
        {
            bottom = max(ps[psay[i + 1]].say, ps[psay[i]].song);
        }
        else
        {
            bottom = ps[psay[i]].song;
        }

        while (j < n && ps[psong[j]].song >= bottom)
        {
            if (psong[j] != psay[i])
            {
                int df = ps[psay[i]].say - ps[psong[j]].song;
                if (df < dif)
                    dif = df;
            }
            j++;
        }
    }
    printf("%d", j);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        solve();
    }
    return 0;
}