#include <iostream>
#include <algorithm>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	long long total=0;
	int x,n;
	cin>>x>>n;
	for(long i=x;i<n+x;i++){
		if(i%7==6||i%7==0){
			
		}else{
			total+=250;
		}
	}
	cout<<total;
	return 0;
}
