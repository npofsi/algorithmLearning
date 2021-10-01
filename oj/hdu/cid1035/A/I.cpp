#include<iostream>
using namespace std;
int a[10];
int main()
{
	a[1] = 7;
	a[2] = 27;
	a[3] = 41;
	a[4] = 49;
	a[5] = 63;
	a[6] = 78;
	a[7] = 108;
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			int x; cin >> x;
			sum += a[x];
		}
		if (sum >= 120)sum -= 50;
		else if (sum >= 89)sum -= 30;
		else if (sum >= 69)sum -= 15;
		cout << sum << endl;
	}
	return 0;
}