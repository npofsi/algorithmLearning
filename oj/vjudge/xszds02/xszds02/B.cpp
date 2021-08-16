#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include<algorithm>
using namespace std;
int n, k;
string s[1005];
int a[1005];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			string st;
			cin >> st;
			string v = st.substr(33);
			sscanf(v.c_str(), "%d", &a[i]);

		}
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= k - 1; i++)
			cout << a[i] << " ";
		cout << a[k] << endl;


	}
	return 0;
}