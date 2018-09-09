#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("input.txt","r",stdin);
	int tpg,cot;
	std::cin>>tpg;
	std::cin>>cot;
	int arr[cot];
	int jar[cot][2];
	for(int i=0;i<cot;i++){
		jar[i][0]=0;
		jar[i][1]=0;
	}
	
	for(int i=0;i<cot;i++)std::cin>>arr[i];
	
	sort(arr,arr+cot);
	for(int x=0;x<cot;x++){
		arr[x]=0
	}
	
	
	return 0;
}
