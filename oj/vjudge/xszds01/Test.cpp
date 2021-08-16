#include<iostream>
#include<string>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int arr[65535];
bool arr[200000];
void clean() {
	for (int i = 0; i < 60000; i++) {
		arr[i] = 0;
	
	}
}
void output(int n) {
	cout << "[]Example" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[n+1+i] << " ";
	}
}
void fill(int n) {
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
}
bool check(int n) {
	for (int i = 0; i < n; i++) {
		if (arr[n + 1 + i] - arr[i] != i + 1) {
			return false;
		}
	}
	return true;
}

int main() {
	int n = 8;
	fill(n);
	for (int i = 0; i <= (int)pow(2, n); i++) {
		next_permutation(arr, arr + n);
		if (check(n))output(n);
	}
}