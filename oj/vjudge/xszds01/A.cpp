#include<iostream>
#include<string>
#include<math.h>
#include<string.h>
#include<vector>
#define ll long long

using namespace std;
ll hpred = 0, hpblue = 0;
int main() {

	for (int i = 0; i < 5; i++) {
		ll hp = 0;
		cin >> hp;
		hpblue += hp;
	}
	for (int i = 0; i < 5; i++) {
		ll hp = 0;
		cin >> hp;
		hpred += hp;
	}
	//cout << hpred << ":" << hpblue;
	if (hpred == hpblue) {
		cout << "Blue" << endl;
	}
	else if (hpred > hpblue) {
		cout << "Red" << endl;
	}
	else if (hpblue > hpred) {
		cout << "Blue" << endl;
	}

	return 0;
}