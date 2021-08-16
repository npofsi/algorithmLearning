#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include<algorithm>
using namespace std;
int main()
{
	long long n;
	long long m;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		n = sqrt(n);
		m = sqrt(m);
		cout <<  n*m << endl;
	}
	return 0;
}