#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main()
{
    int M, N;
    std::cin >> N >> M;

    std::vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int c;
        std::cin >> c;
        v.push_back(c);
    }

    int flag = 0;
    for (int i = 0; i < M; i++)
    {
        int l;
        std::cin >> l;
        int fi = 0;
        for (size_t i = 0; i < v.size(); i++)
        {
            if (v[i] == l)
            {
                v.erase(v.begin() + i);
                fi = 1;
                break;
            }
        };
        if (!fi)
            flag = 1;
    }
    if (!flag)
    {
        std::cout << "Yes";
    }
    else
    {
        std::cout << "No";
    }
    return 0;
}