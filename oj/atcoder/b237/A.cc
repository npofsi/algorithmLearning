#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
typedef long long i64;

int main()
{
    string N;
    int sign = 0;
    i64 num = 0;
    int len = 0;
    cin >> N;
    if (N[0] == '-')
    {
        sign = -1;
        len = -1;
    }
    else
    {
        sign = 1;
    }

    len += N.size();

    if (len > 10)
    {
        cout << "No";
    }
    else
    {

        if (!sscanf(N.c_str(), "-%lld", &num))
            sscanf(N.c_str(), "%lld", &num);
        if ((num <= 2147483647 && sign == 1) || (num <= 2147483648) && sign == -1)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
    }

    return 0;
}