#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
int count;
int height[102];
int lis[102],lds[102];
int LIS(int i){
	for(int p=1;p<=i;p++){
		if(height[p]<height[i]&&lis[p]+1>lis[i]){
			lis[i]=lis[p]+1;
		}else{
			if(lis[p]==0)lis[p]=1;
		}
	}
}

int LDS(int i){
	for(int p=i;p>=i;p--){
		if(height[p]<height[i]&&lds[p]+1>lds[i]){
			lds[i]=lds[p]+1;
		}else{
			if(lds[p]==0)lds[p]=1;
		}
	}
}

int main(){
	lis[1]=1;
	
	int maxx;
	cin>>count;
	lds[count]=1;
	for(int i=1;i<=count;i++){
		cin>>height[i];
	}
	
	for(int i=1;i<=count;i++){
		LIS(i);
		cout<<"  "<<lis[i]<<" ";
		LDS(count+1-i);
		cout<<"  "<<lds[i]<<" ";
	}
	
	return 0;
}
