#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long ll;
ll arr[100010];
ll mta[100010];
ll smt[100010][11];
ll M = 998244353;
inline int pos(char c)
{
    return c - 'a';
}
int main(int, char **)
{
    int n = 0;
    cin >> n;
    char *spr = "nunhehheh";
    for (int i = 0; i < n; i++)
    {
        char str[100010];
        memset(mta, 0, 100002);
        ll sumx = 0;
        scanf("%s", str);

        int len = strlen(str);
        if (len < 10)
        {
            cout << 0 << endl;
            continue;
        }
        if (spr[0] == str[0])
        {
            smt[0][0] = 1ll;
        }
        else
        {
            smt[0][0] = 0ll;
        }

        for (int i = 1; i < len; i++)
        {
            if (str[i] == spr[0])
            {
                smt[i][0] = smt[i - 1][0] + 1ll;
            }
            else
            {
                smt[i][0] = smt[i - 1][0];
            }
        }

        for (int i = 1; i < 9; i++)
        {
            if (spr[i] == str[0])
            {
                smt[0][i] = 0ll;
            }
            else
            {
                smt[0][i] = 0ll;
            }
        }

        for (int i = 1; i < 9; i++)
        {
            for (int j = 1; j < len; j++)
            {
                if (spr[i] == str[j])
                {
                    smt[j][i] = (smt[j - 1][i] + smt[j - 1][i - 1]) % M;
                    if (i == 8)
                    {
                        mta[j] = smt[j - 1][i - 1];
                    }
                }
                else
                {
                    smt[j][i] = smt[j - 1][i];
                }
                //cout << smt[j][i] << " ";
            }
            //cout << endl;
        }

        if (str[len - 1] == 'a')
            arr[len - 1] = 1ll;
        else
            arr[len - 1] = 0ll;

        for (int j = len - 2; j >= 0; j--)
        {
            if (str[j] == 'a')
            {
                arr[j] = (2ll * arr[j + 1] + 1ll) % M;
            }
            else
            {
                arr[j] = arr[j + 1];
                sumx = (sumx + (arr[j] * mta[j]) % M) % M;
            }
        }
        cout << sumx << endl;
    }
}
