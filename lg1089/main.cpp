#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int red[13];
int inhand=0;
int now=0;
int main(){
	
	for(int i=1;i<=12;i++){
		scanf("%d",&red[i]);
		now+=300;
		
		if((now-red[i])>=100){
								
				
				//cout<<"*"<<now<<endl;
				inhand+=((now-red[i])/100)*100;
		}else{
			if((now-red[i])<0){
					  cout<<"-"<<i;
					  return 0;	
			}
			
		}
	now=(now-red[i])%100;
	};
	
	
	printf("%.0f",now+inhand*(1.2));
	
	
	return 0;
}
