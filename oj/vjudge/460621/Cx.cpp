#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int manx = 8e5 + 10;
const ull base = 31;

char s[manx];
int len;
ull hhash[manx], mul[manx];
void init()
{
    mul[0] = 1, hhash[0] = 0;
    for (int i = 1; i <= len; i++)
        mul[i] = mul[i - 1] * base;
    for (int i = 1; i <= len; i++)
        hhash[i] = hhash[i - 1] * base + s[i];
}
ull getHash(int l, int r)
{
    return hhash[r] - hhash[l - 1] * mul[r - l + 1];
}
int main()
{
    scanf("%s", s + 1);
    len = strlen(s + 1);
    init();
    for (int i = 1; i <= len / 3; i++)
    {
        ull c[] = {0, getHash(1, i), 0, 0, 0}, now = 1;
        int posb;
        for (int j = 1; j <= len - i + 1; j += i)
        {
            ull temp = getHash(j, j + i - 1);
            if (temp != c[now])
            {
                c[++now] = temp;
                if (now == 2)
                    posb = j;
            }
            if (now > 3)
                break;
        }
        if (now == 3 && c[1] == c[3])
        {
            int l = len % i;
            if (getHash(1, l) == getHash(len - l + 1, len))
            {
                for (int j = 1; j <= i; j++)
                    putchar(s[j]);
                putchar(' ');
                for (int j = posb; j <= posb + i - 1; j++)
                    putchar(s[j]);
                putchar('\n');
            }
            return 0;
        }
    }
    return 0;
}