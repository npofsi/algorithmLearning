#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include<algorithm>
using namespace std;
const int N = 1e6 + 10;
int a[N];
bool flag = 0;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int minn = 1e9 + 10;
		int num = 0;
		flag = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			minn = min(minn, a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == minn)num++;
			if (a[i] % minn != 0)flag = 1;
		}
		if (flag == 0)
		{
			if (num % 2 == 1)cout << num / 2 + 1 << endl;
			else             cout << num / 2 << endl;
 		}
		else
		{
			cout << 1 << endl;
		}
	}
	return 0;
}