#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
char s[maxn];
struct node {
	int x, y;
}pos[maxn];




int main()
{
	int t, n, i, j, minm;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		scanf("%s", s);
		for (i = 0; i <= n; i++)
			pos[i].x = 0, pos[i].y = 0;
		for (i = 0; i < n; i++)
		{
			pos[i + 1].x = pos[i].x;
			pos[i + 1].y = pos[i].y;
			if (s[i] == 'U')
				pos[i + 1].y++;
			else if (s[i] == 'D')
				pos[i + 1].y--;
			else if (s[i] == 'R')
				pos[i + 1].x++;
			else if (s[i] == 'L')
				pos[i + 1].x--;
		}
		minm = n;
		pos[0].x = 0, pos[0].y = 0;
		for (i = 1; i <= n - 2; i++)
		{
			for (j = i + 1; j <= n - 1; j++)
			{
				if (pos[i - 1].x == pos[j].x && pos[i - 1].y == pos[j].y)
				{
					minm = min(minm, j - i + 1);
					break;
				}
			}
		}
		printf("%d\n", minm);
	}
	return 0;
}
