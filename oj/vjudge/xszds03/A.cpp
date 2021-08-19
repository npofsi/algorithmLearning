#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int main() {
	int a, b, n;
	cin >> a >> b >> n;
	int s = b - a;
	int len1 = n - b;
	int len2 = n - a;
	int ans = 0;
	if (len1 % s == 0)ans += len1 / s;
	else
	{
		ans += len1 / s + 1;
	}
	if (len2 % s == 0)ans += len2/ s;
	else
		ans += len2 / s + 1;
	cout << ans << endl;
	return 0;
}