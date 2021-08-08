#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>



using namespace std;

int n=0;
int arr[110];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	int count=0;
	for(int i=1;i<=n;i++){
		int cac=arr[i];
		int f=0;
		for(int a=1;a<i;a++){
			for(int b=a;b<i;b++){
				if(arr[a]+arr[b]==cac&&a!=b){
					f=1;
					//cout<<a<<'-'<<b<<endl;
				}
			};
		};
		if(f>=1)count++;
	}
	cout<<count;
	return 0;
}
