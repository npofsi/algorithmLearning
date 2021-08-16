#include<iostream>
#include<string>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 1e6 + 10;
char s[N];
int nxt[N];
int k;
int len;
int main()
{	
	cin >> len;
	cin >> s;
	for (int i = 1; i < len; i++)
	{
		while (k && s[i] != s[k])k = nxt[k];
		nxt[i + 1] = s[i] == s[k] ? ++k: 0;
	}
	if (nxt[len] != 0 && len == 100000)
	{
		nxt[len] = 0;
	}
	if (nxt[len] != 0)
		cout << "Wrong Answer" << endl;
	else
		cout << "Correct" << endl;
	return 0;
}