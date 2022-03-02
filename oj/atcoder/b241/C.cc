#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int N = 0;
int a[1002][1002];

inline int getTile(int i, int j)
{
    if (i < 0 || i >= N || j < 0 || j >= N)
    {
        return -1;
    }
    else
    {
        return a[i][j];
    }
}
int checkH(int i, int j, int o)
{
    int b = 0;
    for (int x = 0; x < 6; x++)
    {
        switch (getTile(i, j + x + o))
        {
        case 1:
            b++;
            break;
        case -1:
            return 0;
        }
    }
    return (b >= 4) ? 1 : 0;
}
int checkV(int i, int j, int o)
{
    int b = 0;
    for (int x = 0; x < 6; x++)
    {
        switch (getTile(i + x + o, j))
        {
        case 1:
            b++;
            break;
        case -1:
            return 0;
        }
    }
    return (b >= 4) ? 1 : 0;
}
int checkD(int i, int j, int o)
{
    int b = 0;
    for (int x = 0; x < 6; x++)
    {
        switch (getTile(i + x + o, j + x + o))
        {
        case 1:
            b++;
            break;
        case -1:
            return 0;
        }
    }
    return (b >= 4) ? 1 : 0;
}
int checkD2(int i, int j, int o)
{
    int b = 0;
    for (int x = 0; x < 6; x++)
    {
        switch (getTile(i + x + o, j - x - o))
        {
        case 1:
            b++;
            break;
        case -1:
            return 0;
        }
    }
    return (b >= 4) ? 1 : 0;
}
int main()
{

    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::string S;
        std::cin >> S;
        for (int j = 0; j < N; j++)
        {
            if (S[j] == '#')
            {
                a[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (getTile(i, j) > 0)
                for (int offset = -5; offset <= 0; offset++)
                {

                    if (
                        checkH(i, j, offset) ||
                        checkV(i, j, offset) ||
                        checkD(i, j, offset) ||
                        checkD2(i, j, offset))
                    {
                        goto Yes;
                    }
                }
        }
    }
    std::cout << "No";
    return 0;
Yes:
    std::cout << "Yes";
    return 0;
}