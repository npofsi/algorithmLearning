#include<iostream>
#include<string>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
	int n;
	double ans=0;
	double sum = 0;
	cin >> n;
	for(double i=1;i<=20;i++)
		for (double j = 1; j <= 20; j++)
		{
			ans = 0;
			ans += (j - i);
			if (i > j)ans += 10;
			if (j > i)ans -= 10;
			ans *= (1.0 / 400.0);
			sum += ans;
		}
	printf("%.4f", sum * (n - 1));
	return 0;
}