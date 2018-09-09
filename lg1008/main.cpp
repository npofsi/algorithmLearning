#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	bool nhastx(int);
	int io=123;
	for(;io<=329;io++){
		if(nhastx(io))cout<<io<<" "<<io*2<<" "<<io*3<<"\n";
	}
	return 0;
}

bool nhastx(int oo){
	stringstream st;
	string str;
	st<<""<<oo<<""<<oo*2<<""<<oo*3;
	str=st.str();
	for(int i=0;i<str.length();i++){
		if(str.at(i)=='0')return false;
		if(str.find_first_of(str[i])!=str.find_last_of(str[i]))return false;
	}
	return true;
}


