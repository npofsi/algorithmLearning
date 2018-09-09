#include <iostream>
#include <cstdio>
#include <cstdlib>
//#include <cstring>
//#include <cmath>
//#include <alogrithm>
using namespace std;

void step(int x,int y,int d){
	
}
 
int main(){
	int a; 
	scanf("%d",&a); //
	if(a%2!=0){
		printf("请输入一个奇数");
		system("pause");
	}
	int vals[a+2][a+2];
	for(int i=0;i<a+2;i++)for(int j=0;j<a+2;j++){
		vals[i][j]=0;
		if((i>0&&i<a+2)&&(i>0&&i<a+2))vals[i][j]=-1; 
	}
	
	
	return 0;
} 
