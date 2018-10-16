#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct group {
	int l;
	int x, y;
	int p, q;
} ;
int a[1000];

int M, N, K, L, D;

vector<group> vx, vy;

int cx[1000],cy[1000];

int sx[1000],sy[1000];

int maxX() {
	int maxxl=0;
	for(int i=0; i<	M; i++) {
		if(cx[i]>cx[maxxl]&&i!=-1)maxxl=i;
	}
	cx[maxxl]=-1;
	return maxxl;
}
int maxY() {
	int maxyl=0;
	for(int i=0; i<N; i++) {
		if(cy[i]>cy[maxyl]&&i!=-1)maxyl=i;
	}
	cy[maxyl]=-1;
	return maxyl;
}
int main() {

	cin >> M >> N >> K >> L >> D;
	for (int i = 0; i < D; i++) {
		group g;
		cin >> g.x >> g.y >> g.p >> g.q;
		if (g.x == g.p) {
			g.l=(g.y+g.q)/2;
			vy.push_back(g);

		} else if (g.y == g.q) {
			g.l=(g.x+g.p)/2;
			vx.push_back(g);
		}
	}

	for(int i=0; i<vx.size(); i++) {
		cx[vx[i].l]++;
	}

	for(int i=0; i<vy.size(); i++) {
		cy[vy[i].l]++;
	}

	for(int i=0; i<K; i++) {
		sx[i]=maxX();
	}

	for(int i=0; i<L; i++) {
		sy[i]=maxY();
	}
	
	sort(sx,sx+K);
	sort(sy,sy+L);
	
	for(int i=0; i<K; i++) {
		cout<<sx[i]<<' ';
	}
	
	cout<<endl;
	
	for(int i=0; i<L; i++) {
		cout<<sy[i]<<' ';
	}
	
	
	
	
	return 0;
}




























