#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
///#include <array>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
vector<int> num;
int l=0;
int xcount=0;
iterator max(){
	int maxx=0;
	for(int i=0;i<l;i++){
		maxx=max(num[maxx],num[i])==num[maxx]?maxx:i;
	}
	return num.begin()+maxx; 
}
int main(int argc, char** argv) {
	freopen("input.txt","r",stdin);
	char c=' ';
	int flag=0;
	while(scanf("%c",&c)!=EOF){
		if((flag||c!='0')&&c!='\n'&&c!='\r\n'){	
			num.push_back(c-'0');
			printf("%d:%c\n",l,c);
			l++;
			flag=1;
		}else{
			continue;
		}
	}
	num.erase(num.end()-1);
	for(int i=0;i<xcount;i++){
		if(i<l&&num[i]>num[i+1]){
			num.erase(num.begin()+i,num.begin()+i);
		}
	}
	for(int i=0;i<num.size();i++){
		printf("%d",num[i]);
	}
	return 0;
}
