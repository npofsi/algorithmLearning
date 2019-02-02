#include <iostream>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int map[15][15];
int dp[15][15][15][15];
//int i=1,j=1;
int y=1,x=1;
int main() {
	int l=0;
	scanf("%d",&l);
	while(true){
		scanf("%d %d %d",&x,&y,&map[x][y]);
		if(x==0&&y==0&&map[x][y]==0)break;
	}

	for(int i=1;i<=l;i++)
	for(int j=1;j<=l;j++)
	for(int p=1;p<=l;p++)
	for(int q=1;q<=l;q++){
		dp[i][j][p][q]=max(max(dp[i-1][j][p-1][q],dp[i-1][j][p][q-1]),max(dp[i][j-1][p-1][q],dp[i][j-1][p][q-1]))+map[i][j]+map[p][q];
		if(i==p&&j==q)dp[i][j][p][q]-=map[p][q];
	}

	cout<<dp[l][l][l][l];


	return 0;
}
// 8
// 2 3 13
// 2 6  6
// 3 5  7
// 4 4 14
// 5 2 21
// 5 6  4
// 6 3 15
// 7 2 14
// 0 0  0
