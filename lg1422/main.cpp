#include <iostream>
#include <cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	float v;
	cin>>v;
	if(v<=150){
		printf("%.1f",0.4463*v);
	}else if(v<=400){
		printf("%.1f",0.4463*150+0.4663*(v-150));
	}else if(v>400){
		printf("%.1f",0.4463*150+0.4663*250+0.5663*(v-400));
	}
	return 0;
}
