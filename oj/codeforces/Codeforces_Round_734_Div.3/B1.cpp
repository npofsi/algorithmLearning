#include <iostream>
#include <string>
using namespace std;
int arr[40];
void solve()
{

    for (int i = 0; i < 40; i++)
    {
        arr[i] = 0;
    }

    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        arr[s[i] - 'a']++;
    }
    int cts[3] = {0,
                  0,
                  0};
    for (int i = 0; i < 26; i++)
    {
        switch (arr[i])
        {
        case 1:
            cts[0]++;
            break;
        case 2:
            cts[1]++;
            break;
        case 3:
            cts[2]++;
            break;
        default:
            break;
        }
    }
}

int main()
{
    int t = 0;
    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}