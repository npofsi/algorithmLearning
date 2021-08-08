#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

typedef struct C{
	int x=0,y=0,z=0;
};
int n,h,r,T;
vector<C> cs;
vector<int> rs;
int links[1001][1001];
int read[1001];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int dist(int x1,int y1,int z1,int x2,int y2,int z2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
}
bool isLink(C c1,C c2){
	if(dist(c1.x,c1.y,c1.z,c2.x,c2.y,c2.z)<=2*r)return true;
	return false;
}

bool isGround(C w){
	if(w.y-r<=0){
		
		return true;
	}
	return false;
}
bool dfs(int o){
	
	bool fl=true;
	if(cs[o].y+r>=h){
		fl=false;
	}else{
		for(int u=0;u<n;u++){
			if(!read[o]&&isLink(cs[u],cs[o])){
				read[o]=true;
				fl*=dfs(u);
			}
		}
	}
	return fl;
}
void solve(){
	cin>>n>>h>>r;
	for(int i=0;i<n;i++){
		int x,y,z;
		C xs;
		cin>>xs.x>>xs.z>>xs.y;
		if(isGround(xs)){
			rs.push_back(cs.size());
		}
		cs.push_back(xs);
	}
//	for(int x=0;x<n;x++){
//		for(int y=0;y<n;y++){
//			if(isLink(cs[x],cs[y])){
//				links[x][y]=1;
//				links[y][x]=1;
//			}
//		}
//		
//	}
	bool stat=1;
	for(int j=0;j<rs.size();j++){
		stat*=dfs(rs[j]);
	}
        cs.resize(0);
        rs.resize(0);
        memset(read, 0, sizeof(read));
	if(stat)cout<<"No"<<endl;
	else 
	cout<<"Yes"<<endl;
}







































int main(int argc, char** argv) {
	cin>>T;

        for (int i = 0; i < T; i++) {
          solve();
        }

        return 0;
}