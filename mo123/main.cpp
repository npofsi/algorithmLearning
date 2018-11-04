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
  return x.w < y.w;
}

int findx(int x)
{
    int k, j, r;
    r = x;
    while(r != links[r])     //查找跟节点
        r = links[r];      //找到跟节点，用r记录下
    k = x;
    while (k != r) //非递归路径压缩操作
    {
      j = links[k]; //用j暂存parent[k]的父节点
      links[k] = r; // parent[x]指向跟节点
      k = j;         // k移到父节点
    }
    return r; //返回根节点的值
}
int findxx(int a){
//	if(links[a]==b||links[b]==a){
//		return false;
//	}
       // int last=1; 
	int pos=a;
	//int poss=b;
	//vector<int> aps={};
	//vector<int> bps={};
	while(pos!=links[pos]){
		//aps.push_back(pos);
		//last=pos;
		pos=links[pos];
	}
	return pos;
}
void join(Edge e){
	links[findx(e.u)]=findx(e.v);
//	if(findx(e.u)!=find(e.v)){
//		
//	}
}

int main(int argc, char** argv) {
	cin>>n>>m;//>>k;
        for (int c = 0; c <= n; c++) {
          links[c] = c;
        }
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		Edge e;
		e.u=x;
		e.v=y;
		e.w=w;
		p[i]=e;
	}
	sort(p,p+m+1,comp);
	int t=0;
	long long ans=0;
	 for(int i=1;i<=m;i++){
	    //vector<int> links=isLinked[p[i].u];
	 	if(findx(p[i].v)!=findx(p[i].u)){
	 		//cout<<p[i].u<<" "<<p[i].v;
	 		//p[i].enable=false;
	 		//links.push_back
			join(p[i]);
	 		//isLinked[p[i].v].push_back(p[i].u);
	 		ans+=p[i].w;
                        t++;
		 }
		 
		 if(t==n-1)break;
	 }
	//if(ans!=0)
	cout<<ans;
	//else 
	//cout<<"No Answser";
	return 0;
}
















