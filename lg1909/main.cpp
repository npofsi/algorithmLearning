#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int c;
	cin>>c;
	int pri[3];
	int psl[3];
	int nm=2147483647;
	for(int i=0;i<3;i++){
		cin>>psl[i]>>pri[i];
		int p,g;
		for(g=0,p=0;g<c;g+=psl[i],p+=pri[i]){
		};
		if(p<nm)nm=p;
	}
	cout<<nm;
	return 0;
}
