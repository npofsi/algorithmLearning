#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int n=0,m=0;
int cn[120],cm[120];
int cr=0,cs=0;

int main(){
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int cnn=n-i+1,cmn=m-j+1;
			if(i==j){
				cs+=cnn*cmn;
			}else{
				cr+=cnn*cmn;
			}
		}
	}
	
	printf("%d %d",cs,cr);
	
	return 0;
}
