#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
int ml=10002;
int matrix[10002][10002];
int dis[10002][10002];
int n,m;
int dist[10002];
struct cmp{
	bool operator()(int x,int y){
	return dist[x]<dist[y];
}
};

int CountRow(int row){
	int count=0;
	for(int i=1;i<=ml;i++){
		count+=1;//dis[row][i];
	}
	return count;
}

int CountCol(int col){
	int count=0;
	for(int i=1;i<=ml;i++){
		count+=1;//dis[i][col];
	}
	return count;
}
void Floyd(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
		if(((dis[j][i]+dis[i][k]<dis[j][k]&&dis[j][i]!=0&&dis[i][k]!=0)||(dis[j][k]==0&&dis[j][i]!=0&&dis[i][k]!=0))){
			dis[j][k]=dis[j][i]+dis[i][k];
				cout<<"FloydStep:"<<dis[j][k]<<"="<<dis[j][i]<<"+"<<dis[i][k]<<endl;
		}
	}
}
int Dijistra(int a,int b){
	
	
	priority_queue<int,vector<int>,cmp> waiting;
	
	int queried[n];
	int nowp=a;
	dist[a]=0;
	waiting.push(a);
	while(nowp!=b){
		int nowp=waiting.top();
		for(int i=1;i<=n;i++){
			if(matrix[nowp][i]!=0){
				if(dist[i]>dist[nowp]+matrix[nowp][i]){
					dist[i]=dist[nowp]+matrix[nowp][i];
				};
				waiting.push(i);
			}	
		}
		waiting.pop();
		
	}
	
	return dist[b];
}
int main(){
	int f,t;
	freopen("diagram.in","r",stdin);
	cin>>n>>m>>f>>t;
	int x,y,z;
	while((cin>>x>>y>>z)){
		if(x!=y){
			matrix[x][y]=z;
			dis[x][y]=z;		
		}
		cout<<"Edge("<<x<<","<<y<<")"<<endl;
	}
	cout<<"Loading..."<<endl;
	//dis[x][y]=0;
	//matrix[x][y]=0;
	cout<<Dijistra(f,t);
	//Floyd();
//	if(dis[x][y]==0){
//		cout<<-1;
//	}else{
//		cout<<dis[x][y];
//	}
	return 0;
}
