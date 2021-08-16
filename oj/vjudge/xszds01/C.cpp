#include<iostream>
#include<string>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct Point {
	int x, y, z;
} Point;
int dis(Point& a, Point& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}

bool greaterZ(Point& a, Point& b) {
	return a.z > b.z;
}

bool normal(Point& pl1, Point& pl2, Point& pm1, Point& pm2) {
	if (0 == (pl1.x - pl2.x) * (pm1.x - pm2.x) + (pl1.y - pl2.y) * (pm1.y - pm2.y) + (pl1.z - pl2.z) * (pm1.z - pm2.z)) {
		return 1;
	}
	return 0;
}


void solve() {
	vector<Point> ps;
	for (int i = 0; i < 8; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		Point p = { x,y,z };
		ps.push_back(p);
	}

	sort(ps.begin(), ps.end(), greaterZ);

	int flag = 1;
	int min = 2147483647;
	for (int i = 1; i < 8; i++) {
		int ds = dis(ps[0], ps[i]);
		if (ds < min)min = ds;
	}
	if (min <= 0) {
		cout << "NO" << endl;
		return;
	}

	for (int i = 1; i < 8; i++) {
		vector<Point> psx;
		int count = 0;
		for (int j = 0; j < 8; j++) {
			if (i != j) {
				int ds = dis(ps[i], ps[j]);
				if (ds == min) {
					psx.push_back(ps[j]);
					count++;
				}
			}
			
		}
		if (count == 3 && normal(ps[i], psx[0], ps[i], psx[1]) && normal(ps[i], psx[0], ps[i], psx[2]) && normal(ps[i], psx[2], ps[i], psx[1])) { continue; }
		else {
			flag = 0;
		}
	}




	if (flag) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

}
int main() {
	int count = 0;
	cin >> count;
	for (int i = 0; i < count; i++) {
		solve();
	}
	return 0;
}