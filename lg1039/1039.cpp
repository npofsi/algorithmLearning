#include <iostream>
#include <map>
#include <string>
//#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define ll long long

vector<string> split(string str){
	vector<string> s;
	string::iterator i=str.begin();
	for(;i<str.end();i++){
		
		if(*i==':'&&*(i+1)==' '){
			s.push_back(str.assign(str.begin(),i));//.substr(0,i);
			s.push_back(str.assign(i+2,str.end()));;
		}
	}
}

int por[100];//tf
vector<string> says[100];//语言 
string names[100];//名字 
string lastd[100];//最后一次说的星期 
int isgb[100];//暂定的罪犯 
int ismb[100];//确定的罪犯 
int state = -1;
string S[10]=
{
    "Today is Sunday.",
    "Today is Monday.",
    "Today is Tuesday.",
    "Today is Wednesday.",
    "Today is Thursday.",
    "Today is Friday.",
    "Today is Saturday.",
};
string G[3]={
	" is guilty.",
	" is not guilty.",
};
string I[3]={
	"I am guilty.",
	"I am not guilty."
};
int main() {
	string gu="guilty";
	map<string,int> pers;
	int m,n,p;
	cin>>m>>n>>p;
	string name[m];
	
	for(int i=0;i<m;i++){
		cin>>names[i];
		pers[names[i]]=i;
	}
	for(int i=0;i<p;i++){
		string str="\n";
		getline(cin,str);
		vector<string> g=split(str);
		says[ pers[ g[0] ] ].push_back(g[1]);
	}
	
	for(int i=0;i<p;i++){
		for(int j=0;j<m;j++){
			for(int h=0;h<7;h++){
				//if(says[m])
			}
		}
	}
	
	cout<<split("make: i am not guilty.")[0];
	return 0;
}
