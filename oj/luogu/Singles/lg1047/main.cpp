#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int road[10005];
int s=0,m2=0,l=0,m=0;
int flag=0;

int main(){
	int c=0;
	
	scanf("%d %d",&l,&m);
	
	m2=m;
	
	do{
		m--;
		int a,b;
		scanf("%d %d",&a,&b);
		road[a]+=1;
		road[b]-=1;
		
	}while(m!=0);
	
	for(s=0;s<=l;s++){
		//int ff=flag;
		flag+=road[s];
		if(flag==0&&road[s]==0)c++;
	}
		
	
	printf("%d",c);
	
	return 0;
}
