#include <iostream>

#define INF 1000000090
using namespace std;

int n,m,s,t;
int matx[2501][2501];
int dis[2501],vis[2501];

int dijkstra(){
	int a,j,u,v;
	int min;
	for(int a=1;a<=n;a++){
		min=INF;
		for(int j=1;j<=n;j++){
			if(vis[j]==0&&dis[j]<min){
				min=dis[j];
				u=j;
			}
		}
		vis[u]=1;
		for(v=1;v<=n;v++){
			if(matx[u][v]<INF){
				if(vis[v]==0&&dis[v]>dis[u]+matx[u][v]){
					//vis[v]=1;
					dis[v]=dis[u]+matx[u][v];
				}
			}
		}
	}
	return dis[t];
}

int main(){
	
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>s>>t;
	
	for(int x=1;x<=n;n++){
		for(int y=1;y<=n;n++){
			if(x==y)
				matx[x][y]=0;
			else
				matx[x][y]=INF;
				
		}
	}
	
	for(int p=1;p<=m;p++){
		int sp,tp,wp;
		cin>>sp>>tp>>wp;
		matx[sp][tp]=wp;
		matx[tp][sp]=wp;
	}
	
	for(int h=1;h<=n;h++){
		dis[h]=matx[s][h];
	}
	vis[s]=1;
	
	cout<<dijkstra();
	
	return 0;
}
