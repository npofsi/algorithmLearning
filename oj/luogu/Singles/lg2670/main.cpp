#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

string arr[110];
int map[110][110];
int n=0,m=0;

int main(){
	cin>>n>>m;
	
	for(int h=0;h<n;h++){
		string cache;
		cin>>cache;
		arr[h]=cache;
	}
	
	
	for(int h=0;h<n;h++){
		for(int l=0;l<m;l++){
			if(arr[h][l]=='*'){
				map[h][l]=-1;
				if(h-1>=0&&map[h-1][l]!=-1)map[h-1][l]++;
				if(l-1>=0&&map[h][l-1]!=-1)map[h][l-1]++;
				if(h+1<n&&map[h+1][l]!=-1)map[h+1][l]++;
				if(l+1<m&&map[h][l+1]!=-1)map[h][l+1]++;
				if(h-1>=0&&l-1>=0&&map[h-1][l-1]!=-1)map[h-1][l-1]++;
				if(h+1<n&&l+1<m&&map[h+1][l+1]!=-1)map[h+1][l+1]++;
				if(h-1>=0&&l+1<m&&map[h-1][l+1]!=-1)map[h-1][l+1]++;
				if(h+1<n&&l-1>=0&&map[h+1][l-1]!=-1)map[h+1][l-1]++;
				
			}
		}
	}
	
	for(int h=0;h<n;h++){
		for(int l=0;l<m;l++){
				if(map[h][l]==-1){
					cout<<'*';
				}else{
					cout<<map[h][l];
				}
					
		}
		cout<<endl;
	}
	
	return 0;
}

