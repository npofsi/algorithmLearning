#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,x;
	cin>>n>>x;
	int total=0;
	stringstream st;
	for(int i=1;i<=n;i++){
		st<<i;	
	}
	string str=st.str();
	//cout<<str;
		for(int i=0;i<str.length();i++){
			
			if(str.at(i)==x+'0')total++;
		}
	cout<<total;
	return 0;
}
