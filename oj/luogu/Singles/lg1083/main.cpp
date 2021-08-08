#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 struct req{
	int count;
	int start;
	int end;
}; 
int a[1000000];
req b[1000000];
int main() {
	int n,m,id=0,mode=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=m;j++){
		cin>>b[j].count;
		cin>>b[j].start;
		cin>>b[j].end;
	}
	for(int i=1;i<=m;i++){
		for(int j=b[i].start;j<=b[i].end;j++){
				if(a[j]-b[i].count>=0){
					a[j]-=b[i].count;
				}else{
					if(mode==0)mode=-1;
					if(mode==-1){
						cout<<-1<<endl;
					}
					cout<<i<<endl;
					return 0;
				}
//			b[j].count
//			b[j].start
//			b[j].end;
		}
	}
	if(mode==0)cout<<mode<<endl;
	//if(mode==-1)cout<<id;
	return 0;
}
