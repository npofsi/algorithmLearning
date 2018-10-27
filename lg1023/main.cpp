#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int hope,maxl;

vector<int> sold[100001];
vector<int> priz[100001];
vector<int> csold[100000];
vector<int> cpriz[100000];

int cont;

bool cmp(int a,int b) {
  if (b < a) {
  	
    return false;
  }
  return true;
	}

int main() {
  int lsold=1, lpriz=1;
  int i = 0;
  cin >> hope;
  while (lsold != -1 && lpriz != -1) {
    int s, p;
    cin >> s >> p;
    sold.push_back(s);
    priz.push_back( p);
    i++;
  }
  cont = i - 1;
  cin >> maxl;
  
  
  
  return 0; 
}