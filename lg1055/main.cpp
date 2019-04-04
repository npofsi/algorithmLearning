#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

#define z '0'

string str;
int nums[12];
int main(){
	cin>>str;
	
	nums[1]=str[0]-z;
	
	nums[2]=str[2]-z;
	nums[3]=str[3]-z;
	nums[4]=str[4]-z;
	
	nums[5]=str[6]-z;
	nums[6]=str[7]-z;
	nums[7]=str[8]-z;
	nums[8]=str[9]-z;
	nums[9]=str[10]-z;
	
	
	char c=str[12];
	int sum=0;
	
	for(int i=1;i<=9;i++){
		sum+=nums[i]*i;
		
	}
	//cout<<sum;
	int g=sum%11;
	int f=0;
	if(g==10&&c=='X'){
		f=1;
	}
	if(g!=10){
		if(g+'0'==c){
			f=1;
		}
		
	}
	
	if(f==1){
		cout<<"Right";
	}else{
		cout<<nums[1]<<'-'<<nums[2]<<nums[3]<<nums[4]<<'-'<<nums[5]<<nums[6]<<nums[7]<<nums[8]<<nums[9]<<'-';
		if(g==10){
			cout<<"X";
		}else{
			cout<<g;
		};
	}
	
	return 0;
}
