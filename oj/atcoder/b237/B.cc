#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>

#define i64 long long

int len = 0;
int main()
{
    int H, W;
    std::cin >> H >> W;
    std::vector<i64> v;
    for (int i = 0; i < H * W; i++)
    {
        i64 c;
        std::cin >> c;
        v.push_back(c);
    }
    int ct = 0;
    for (int i = 1; i <= W; i++)
    {
        for (int j = 1; j <= H; j++)
        {
            ct++;
            int seq = (j - 1) * W + i;
            std::cout << v[seq - 1];
            if (ct % H == 0 && ct != H * W)
            {
                std::cout << std::endl;
            }
            else
            {
                std::cout << " ";
            }
        }
    }
    return 0;
}