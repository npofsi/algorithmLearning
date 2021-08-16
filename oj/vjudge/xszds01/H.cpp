#include<iostream>
#include<string>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool ch[2001000];

vector<int> arr1, arr2;
int main() {
	int n;
	cin >> n;
	arr1.push_back(n);
	arr2.push_back(n + 1);
	int smin = 1;
	int smax = 2 * n;
	for (int i = 1; i <= n - 1;i++) {
		if (i % 2 == 1) {
			int a = smin;
			int b = a + (i + 1);
			if(ch[a]==1)
		}
		else {

		}
		

	}
	return 0;
}