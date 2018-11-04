#include <iostream>
using namespace std;
struct node {
  int data=2147483647;
  node last;
  node next;
}; 
int n;
node head;
void opt(int op,int x){
	head.data=0;
	head.next=head;
	head.last=head;
	switch(op){
		case 1:{
			node l=head;
			while(l.data<x){
				l=l.next;
			}
			node t;
			t.data=x;
			t.last=l.last;
			t.next=l;
			l.last.next=t;
			l.last=t;
			
			break;
		}
		case 2:{
			node l=head;
			while(l.data!=x){
				l=l.next;
			}
			l.last.next=l.next;
			l.next.last=l.last;
			
			break;
		}
		case 3:{
			int rank=0;
			node l=head;
			while(l.data!=x){
				l=l.next;
				rank++:
			}
			cout<<rank<<endl;
			break;
		}
		case 4:{
			int rank=0;
			node l=head;
			while(rank!=x){
				l=l.next;
				rank++:
			}
			cout<<l.data<<endl;
			break;
		}
		case 5:{
			node l=head;
			while(l.data!=x){
				l=l.next;
			}
			cout<<l.last.data<<endl;
			break;
		}
		case 6:{
			int flag=0;
			node l=head;
			while((l.data!=x&&flag==0)||(flage==1&&l.data==x)){
				if(l.data==x)flag=1;
				l=l.next;
			}
			cout<<l.data<<endl;
			break;
		}
	}
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
  	int op,x;
	cin>>op>>x;
	opt(op,x);
  }
  return 0;
};
