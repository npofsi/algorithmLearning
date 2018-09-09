#include <iostream>
#include <cstdio>
#include <cstdlib>
//#include <cstring>
//#include <cmath>
#include <algorithm>
using namespace std;
int vals[100][100];
void step(int x,int y,int k,int d){
	vals[y][x]=k;
	k++;
	if(vals[y-1][x]>0&&vals[y+1][x]>0&&vals[y][x-1]>0&&vals[y][x+1]>0)return;
	if(d==0)if(!(vals[y][x+1]!=-1)){step(x+1,y,k,d);}else{
		 d=1;
		 step(x,y+1,k,d);
	}else
	if(d==1)if(!(vals[y+1][x]!=-1)){step(x,y+1,k,d);}else{
		 d=2;
		 step(x-1,y,k,d);
	}else
	if(d==2)if(!(vals[y][x-1]!=-1)){step(x-1,y,k,d);}else{
		 d=3;
		 step(x,y-1,k,d);
	}else
	if(d==3)if(!(vals[y-1][x]!=-1)){step(x,y-1,k,d);}else{
		 d=0;
		 step(x+1,y,k,d);
	}
}
 
int main(){
	int a; 
	printf("请输入一个>=3数：");
	scanf("%d",&a); //
	/*if(a%2==0){
		printf("请输入一个奇数\n");
		system("pause");
		
	}*/


	for(int i=0;i<a+2;i++)for(int j=0;j<a+2;j++){
		vals[i][j]=0;
		if((i>0&&i<a+1)&&(j>0&&j<a+1))vals[i][j]=-1; 
	}
	/*
	d
	0=right
	1=down
	2=left
	3=up
	*/
	step(1,1,1,0);
	for(int i=0;i<a+2;i++){
		printf("\n");
	for(int j=0;j<a+2;j++){
		printf("%4d ",vals[i][j]);
	 
	}}
	
	return 0;
} 
