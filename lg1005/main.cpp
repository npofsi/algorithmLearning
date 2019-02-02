#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring> 
#include <vector>

using namespace std;

int n,m;

int map[100][100];
int sorted[100][100];

int added[100];
int bins[100][100];




int store[100];
int addsto[100];
int addstd[100];
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
	
}






int main(){
	
	cin>>n>>m;	
	
	store[1]=1;	
		
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>map[i][j];		
		}
	}
	
	for(int q=1;q<=80;q++){
		HRM(2);
		for(int g=1;g<=100;g++){
			bins[q][g]=store[g];		
		}
	}

	for(int i=1;i<=n;i++){
		int lp=1,rp=m;
		for(int j=1;j<=m;j++){
			
			if(map[i][lp]>map[i][rp]){
				sorted[i][j]=map[i][rp];
				rp--;
			}else if(map[i][lp]<=map[i][rp]){
				sorted[i][j]=map[i][lp];
				lp++;			
			}
		}
	}
		
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			added[i]+=sorted[j][i];
		}	
	}


	for(int i=1;i<=m;i++){
		for(int g=1;g<=100;g++){
			store[g]=bins[i][g];		
		}
		HRM(added[i]);
		HRA();
	}

		int flag=0;
	for(int i=99;i>=1;i--){
		if(addsto[i]!=0)flag=1;		
		if(flag==1){
			cout<<addsto[i];		
		}	
		if(i==1&&flag==0)cout<<0;
	}

	return 0;
}
