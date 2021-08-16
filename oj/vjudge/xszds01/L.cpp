#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
char t[maxn];
int dimat[9][9];
int main()
{
	int m,i,j,flag=1,cnt;
	scanf("%d", &m);
	scanf("%s", t);
	for (i = 0; i <= m - 2; i++)
	{
		flag = 1;
		cnt = 0;
		for (j = m - 1 - i; j <= m - 1; j++)
		{
			if (t[cnt] != t[j])
			{
				flag = 0;
				break;
			}
			cnt++;
		}
		if (flag == 1)
			break;
	}
	if (m == 1)
		flag = 0;
	if (flag == 0)
		printf("Correct\n");
	else
		printf("Wrong Answer\n");
	return 0;
}