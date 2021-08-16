#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include<algorithm>
using namespace std;
char maze[10][10];
int s;
int num;
int minn;
int ans;
void dfs(int x,int s)
{
	if (x == 0)
	{
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i <= 2; i++)
		{
			if (maze[i][0] == maze[i][1]&&maze[i][1] == maze[i][2] && maze[i][1] == 'O')sum1++;
			if (maze[i][0] == maze[i][1] && maze[i][1] == maze[i][2] && maze[i][1] == 'X')sum2++;
			if (maze[0][i] == maze[1][i] && maze[1][i] == maze[2][i] && maze[1][i] == 'O')sum1++;
			if (maze[0][i] == maze[1][i] && maze[1][i] == maze[2][i] && maze[1][i] == 'X')sum2++;
		}
		if (maze[0][0] == maze[1][1] && maze[1][1] == maze[2][2] && maze[0][0] == 'O')sum1++;
		if (maze[0][0] == maze[1][1] && maze[1][1] == maze[2][2] && maze[0][0] == 'X')sum2++;
		if (maze[0][2] == maze[1][1] && maze[1][1] == maze[2][0] && maze[1][1] == 'O')sum1++;
		if (maze[0][2] == maze[1][1] && maze[1][1] == maze[2][0] && maze[1][1] == 'X')sum2++;
		if (abs(sum1 - sum2) < minn)
		{
			minn = abs(sum1 - sum2);
			ans = sum1 - sum2;
		}
		return;

	}
	for(int i=0;i<=2;i++)
		for (int j = 0; j <= 2; j++)
		{
			if (maze[i][j] != '.')continue;
			if (s == 0)
			{
				maze[i][j] = 'O';
				dfs(x - 1, 1 - s);
				maze[i][j] = '.';
			}
			else
			{
				maze[i][j] == 'X';
				dfs(x - 1, 1 - s);
				maze[i][j] = '.';
			}
		}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		minn = 20;
		scanf("%d", &s);
		num = 0;
		for (int i = 0; i <= 2; i++)
			scanf("%s", maze[i]);
		for(int i=0;i<=2;i++)
			for (int j = 0; j <= 2; j++)
				if (maze[i][j] == '.')
					num++;
		dfs(num,s);
		printf("%d\n", ans);
	}
	return 0;
}