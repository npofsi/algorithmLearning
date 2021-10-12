#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 8e5 + 5;
const ull base = 31;

char s[N];

int len;
ull shash[N], mul[N];

void initHash()
{
    mul[0] = 1;
    shash[0] = 0;
    for (int i = 1; i <= len; i++)
    {
        mul[i] = mul[i - 1] * base;
    }
    for (int i = 1; i <= len; i++)
    {
        shash[i] = shash[i - 1] * base + s[i];
    }
}
ull modHash(int l, int r)
{
    return shash[r] - shash[l - 1] * mul[r - l + 1];
}
int main(int, char **)
{
    scanf("%s", s + 1);
    //cout << s + 1 << endl;
    len = strlen(s + 1);
    initHash();
    for (int i = 1; i <= len / 3; i++)
    {
        ull c[] = {0, 0, 0, 0, 0};
        c[1] = modHash(1, i);
        ull now = 1;
        int pos;
        for (int j = 1; j <= len - i + 1; j += i)
        {
            ull m = modHash(j, j + i - 1);
            if (m != c[now])
            {
                c[++now] = m;
                if (now == 2)
                    pos = j;
            }
            if (now > 3)
                break;
        }
        if (now == 3 && c[1] == c[3])
        {
            int l = len % i;
            if (modHash(1, l) == modHash(len - l + 1, len))
            {
                //cout << s + 1 << endl;
                string str = string(s + 1);
                cout << str.substr(0, i) << " " << str.substr(pos - 1, i) << endl;
            }
            return 0;
        }
    }
    return 0;
}
