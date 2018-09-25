#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int base=10007;
int d[2000][2000];

int quickPow(int a,int b){
	int bas=a;
	int ans=1;
	while(b){
		if(b&1)ans=(ans*bas)%base;
		bas=(bas*bas)%base;
		b>>=1;
	}
	return ans;
}
int main() {
	int a,b,k,n,m;
	cin>>a>>b>>k>>n>>m;
	a%=base;
	b%=base;
	a=quickPow(a,n);
	b=quickPow(b,m);
	 for (int i = 0; i<=k; i++)
    {
        d[i][0] = 1;
        d[i][i] = 1;
    }
   
    int c=min(n,m);
	for (int i = 2; i<=k; i++)//从1开始就会WA
    {
        for (int j = 1; j<=c; j++)
        {
            d[i][j] = (d[i-1][j]+d[i-1][j-1]) %base;
        }
    }
    int sum = (a*b)%base;
    sum=(sum* d[k][c])%base;
    printf("%d",sum);
	return 0;
}
