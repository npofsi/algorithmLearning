#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#define i64 long long

int main()
{
    std::string s = "";
    int N;
    std::cin >> N >> s;
    std::deque<int> deq;
    if (N == 0)
    {
        std::cout << "0";
        return 0;
    }
    int n = N;
    deq.push_back(n);
    for (int i = N - 1; i >= 0; i--)
    {
        n--;
        if (s[i] == 'L')
        {
            deq.push_back(n);
        }
        else
        {
            deq.push_front(n);
        }
    }

    int len = deq.size();
    for (int i = 0; i < len; i++)
    {
        std::cout << deq[i];
        if (i != len - 1)
            std::cout << " ";
    }
    return 0;
}