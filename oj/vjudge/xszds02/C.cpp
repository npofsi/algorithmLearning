#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;

long long dp[5005][5005];

const long long mod = 1e9 + 7;
char s1[5005], s2[5005];
void solve() {

//	cin >> s1;
//	cin >> s2;
	int n1 = strlen(s1);
	int n2 = strlen(s2);



	if (s1[0] == s2[0]) {
		dp[0][0] = 1;
	}
	else {
		dp[0][0] = 0;
	}
	for (int j = 1; j < n1; j++) {
		if (s1[j] == s2[0]) { dp[0][j] = dp[0][j - 1] + 1; }
		else {
			dp[0][j] = dp[0][j - 1];
		}
	}

	for (int i = 1; i < n2; i++) {
		for (int j = 0; j < n1; j++) {
			if (j < i)dp[i][j] = 0;
			//cout << i << "," << j << endl;
			if (s2[i] == s1[j]) {
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1])% mod;
			}
			else {
				dp[i][j] = dp[i][j - 1];
				//dp[i][j] %= mod;
			}
		}
	}
	
	/*for (int i = 0; i < n2; i++) {
		for (int j = 0; j < n1; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << dp[n2 - 1][n1 - 1] << endl;;

	return;
}

int main() {
	while ((scanf("%s%s",s1,s2))!=EOF) {
		solve();
	}
	return 0;
}