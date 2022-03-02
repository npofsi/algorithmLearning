#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define i64 long long
const int L = 200010;

int dis[L], h[L];
std::vector<int> mav[L];
int is_in_queue[L];
std::queue<int> que;
int main()
{
    int N, M;
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> h[i];
    }
    for (int i = 0; i < M; i++)
    {
        int U, V;
        std::cin >> U >> V;
        mav[U].push_back(V);
        mav[V].push_back(U);
    }

    que.push(1);
    is_in_queue[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        dis[i] = -2147483647;
    };
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        is_in_queue[now] = 0;
        for (auto i = mav[now].begin(); i != mav[now].end(); i++)
        {
            int dif = h[now] - h[*i];
            int w = dif < 0 ? dif * 2 : dif;
            if (w + dis[now] > dis[*i])
            {
                dis[*i] = w + dis[now];
                que.push(*i);
                is_in_queue[*i] = 1;
            }
        }
    }
    int maxh = 0;
    for (int i = 1; i <= N; i++)
    {
        if (dis[i] > maxh)
        {
            maxh = dis[i];
        }
    }
    std::cout << maxh;
    return 0;
}