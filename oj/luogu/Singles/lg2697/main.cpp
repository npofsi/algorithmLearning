#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int arr[1000002];
//int cnu[1000001];
int main(int argc, char** argv) {
	//freopen("in.txt","r",stdin);
	char c=' ';
	int i=0;
	ios::sync_with_stdio(false);
	int v=0;
	arr[0]=0;
	while(scanf("%c",&c)!=EOF){
	
		i++;
		arr[i]=arr[i-1]+(c=='R'?-1:1);
		//v+=(c=='R'?-1:1);
		
		
	}
	int max=0;
	for(int x=0;x<=i;x++){
	//cout<<" "<<arr[x]<<" ";
		for(int y=x;y<=i;y++){
			if(arr[x]==arr[y]){
				max=((y-x)>max?y-x:max);
			}
		}
	}
	//if(max==i-1)max++;
	printf("%d",max);
	return 0;
}
