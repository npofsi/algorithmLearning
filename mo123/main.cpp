#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define INF 2147483647
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Edge{
	int u;
	int v;
	int w;
	//int enable=true;
};

Edge p[500001];
int links[200001];
int n,m,k;
int comp(Edge x,Edge y){
	if(x.w>y.w){
		return false;
	}
	return true;
}
void join(Edge e){
	links[find(e.u)]=e.v
//	if(findx(e.u)!=find(e.v)){
//		
//	}
}
int findx(int a){
//	if(links[a]==b||links[b]==a){
//		return false;
//	}
    int last=1; 
	int pos=a;
	//int poss=b;
	//vector<int> aps={};
	//vector<int> bps={};
	while(pos!=0){
		//aps.push_back(pos);
		last=pos;
		pos=links[pos];
	}
	return last;
}
int main(int argc, char** argv) {
	cin>>n>>m;//>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		Edge e;
		e.u=x;
		e.v=y;
		e.w=w;
		p[i]=e;
	}
	sort(p,p+m,comp);
	int t=0;
	int ans=0;
	 for(int i=1;i<=m;i++){
	    //vector<int> links=isLinked[p[i].u];
	 	if(findx(p[i].v)!=findx(p[i].u)){
	 		//cout<<p[i].u<<" "<<p[i].v;
	 		//p[i].enable=false;
	 		//links.push_back
			join(p[i].v);
	 		//isLinked[p[i].v].push_back(p[i].u);
	 		ans+=p[i].w;
		 }
		 t++;
		 if(t==n-1)break;
	 }
	//if(ans!=0)
	cout<<ans;
	//else 
	//cout<<"No Answser";
	return 0;
}


















