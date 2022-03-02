#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using i64 = long long;

int main()
{
    int Q = 0;
    std::cin >> Q;
    std::multiset<i64> s;
    for (int i = 0; i < 5; i++)
    {
        s.insert(-1);
        s.insert(1E18);
    }
    while (Q--)
    {
        int t;
        i64 x;
        int k;
        std::cin >> t;
        if (t == 1)
        {
            std::cin >> x;
            s.insert(x);
        }
        else if (t == 2)
        {
            std::cin >> x >> k;
            k--;
            auto it = std::prev(s.lower_bound(x + 1));
            while (k--)
                it--;

            std::cout << *it << std::endl;
        }
        else if (t == 3)
        {
            std::cin >> x >> k;
            k--;
            auto it = s.lower_bound(x);
            while (k--)
                it++;
            if (*it >= 1E18)
                std::cout << "-1" << std::endl;
            else
                std::cout << *it << std::endl;
        }
    }
    return 0;
}