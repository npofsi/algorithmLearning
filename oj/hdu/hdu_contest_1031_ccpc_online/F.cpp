#include<iostream>
#include<queue>

using namespace std;

int arr[1000010000];
int ark[1000010];
int arx[5500][5500];


int dfs(int last,int sum,int laststate) {
	int th = last + 1;
	int sum1 = dfs(sum + th * th);
}

void solve() {
	int n;
	cin >> n;
	int i = 0;
	while (1) {
		i++;

	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		solve();
	}
	return 1;
}