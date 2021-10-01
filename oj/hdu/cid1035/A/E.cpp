#include <iostream>
#include <string>
#include <cstring>
#include <regex>

using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--)
	{
		long long p;
		cin >> p;
		cout << 12 * p << " " << 4 << endl;
		cout << 1 * p << " " << 2 * p << " " << 3 * p << " " << 6 * p << endl;
	}
	return 0;
}