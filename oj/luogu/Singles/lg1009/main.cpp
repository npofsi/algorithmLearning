#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int store[100];
int addsto[100];

void HRA(){
	for(int i=1;i<=99;i++){
		addsto[i]+=store[i];
		if(addsto[i]>=10){
			int buffer=addsto[i]/10;
			addsto[i+1]+=buffer;
			addsto[i]-=buffer*10;
		}	
	}
	
}


void HRM(int bed){
	for(int i=1;i<=99;i++){
		store[i]=store[i]*bed;	
		
	}
	for(int i=1;i<=99;i++){
		if(store[i]>=10){
			int buffer=store[i]/10;
			store[i+1]+=buffer;
			store[i]=store[i]-buffer*10;
		}	
	}
	//cout<<bed<<endl;
	if(bed>1)HRM(bed-1);
}



int main(){
	
	store[1]=1;
	int b;
	cin>>b;
	//HRM(b);
	int flag=0;
	//for(int i=66;i>=1;i--){cout<<store[i];}

	for(int h=1;h<=b;h++){
		HRM(h);
		HRA();	
		memset(store,0,sizeof(store));
		store[1]=1;
	}
	
	for(int i=99;i>=1;i--){
		if(addsto[i]!=0)flag=1;		
		if(flag==1){
			cout<<addsto[i];		
		}	
	}
	//cout<<flag;
	
	return 0;
}
