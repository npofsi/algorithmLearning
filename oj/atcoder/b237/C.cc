#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string.h>
#include <vector>

#define i64 long long
inline bool is_palindrome(std::string str)
{
    if (str.size() == 0)
        return true;
    int start = 0, end = str.size() - 1;
    while (start != end + 2 && start != end + 1)
    {
        if (str[start] == str[end])
        {
            start++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
};

int main()
{
    std::string str;
    std::cin >> str;
    int sa = 0, ea = 0;
    while (str[sa] == 'a')
    {
        sa++;
    }
    int pos = 0;
    while (pos != str.size())
    {
        if (str[pos] == 'a')
        {
            ea++;
        }
        else
        {
            ea = 0;
        }

        pos++;
    }
    if (is_palindrome(str))
    {
        std::cout << "Yes";
    }
    else if (sa < ea)
    {
        int dif = ea - sa;
        if (is_palindrome(str.substr(0, str.size() - dif)))
        {
            std::cout << "Yes";
        }
        else
        {
            std::cout << "No";
        }
    }
    else
    {
        std::cout << "No";
    }

    return 0;
}