#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstdlib>
#define ll long long
#define pa pair<int, int>
#define INF INT_MAX
#define db double
using namespace std;
int n, m, q;
int mat[2005][2005];
struct lq
{
    int x;
    int y;
};
void solve()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    queue<lq> mq = queue<lq>();
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            mat[i][j] = 1;
        }
    }
    for (int i = 0; i < q; i++)
    {
        int t = 0;
        int mx, my;
        scanf("%d%d", &mx, &my);
        if (mat[mx][my] == 0)
        {
            printf("0\n");
            continue;
        }
        else
        {
            mat[mx][my] = 0;
            t++;
            if (mx - 1 >= 1)
                mq.push(lq{mx - 1, my});
            if (my - 1 >= 1)
                mq.push(lq{mx, my - 1});
            if (mx + 1 <= n)
                mq.push(lq{mx + 1, my});
            if (my + 1 <= m)
                mq.push(lq{mx, my + 1});
            while (mq.size() != 0)
            {

                lq mlq = mq.front();
                int x = mlq.x;
                int y = mlq.y;
                if (mat[x][y] == 0)
                {
                    mq.pop();
                    continue;
                }
                if ((x == 1 && y == 1 && mat[x + 1][y] == 0 && mat[x][y + 1] == 0) ||
                    (x == 1 && y == m && mat[x + 1][y] == 0 && mat[x][y - 1] == 0) ||
                    (x == n && y == 1 && mat[x - 1][y] == 0 && mat[x][y + 1] == 0) ||
                    (x == n && y == m && mat[x - 1][y] == 0 && mat[x][y - 1] == 0) ||
                    (x == 1 && (y != 1 && y != m) && mat[x + 1][y] == 0 && (mat[x][y - 1] == 0 || mat[x][y + 1] == 0)) ||
                    (x == n && (y != 1 && y != m) && mat[x - 1][y] == 0 && (mat[x][y - 1] == 0 || mat[x][y + 1] == 0)) ||
                    (y == 1 && (x != 1 && x != n) && mat[x][y + 1] == 0 && (mat[x - 1][y] == 0 || mat[x + 1][y] == 0)) ||
                    (y == m && (x != 1 && x != n) && mat[x][y - 1] == 0 && (mat[x - 1][y] == 0 || mat[x + 1][y] == 0)) ||
                    ((x != 1 && x != n && y != 1 && y != m) && (mat[x][y - 1] == 0 || mat[x][y + 1] == 0) && (mat[x - 1][y] == 0 || mat[x + 1][y] == 0)))
                {
                    t++;
                    mat[x][y] = 0;
                    if (x - 1 >= 1)
                        mq.push(lq{x - 1, y});
                    if (y - 1 >= 1)
                        mq.push(lq{x, y - 1});
                    if (x + 1 <= n)
                        mq.push(lq{x + 1, y});
                    if (y + 1 <= m)
                        mq.push(lq{x, y + 1});
                }
                else
                {
                }
                mq.pop();
            }
            printf("%d\n", t);
        }
    }
}
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        solve();
    }
    return 0;
}