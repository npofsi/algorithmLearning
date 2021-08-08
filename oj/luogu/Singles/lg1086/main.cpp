#include<iostream>
#include<cstdio>
using namespace std;
int M,N,K;
int map[22][22];
struct Point{
	int x,y;
};

Point find(){
	int maxx=0;
	Point p;
	for(int x=1;x<=M;x++)
	for(int y=1;y<=N;y++){
		 if(map[x][y]>maxx){
				maxx=map[x][y];
			 	p.x=x;
				p.y=y;
		 }
	}
	return p;
}

int main(){
	cin>>M>>N>>K;
	for(int x=1;x<=M;x++)
	for(int y=1;y<=N;y++){
		 cin>>map[x][y];
	}

	

	return 0;
}
