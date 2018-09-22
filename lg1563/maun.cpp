#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

string names[100002];
int direct[100002];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> direct[i] >> temp;
    names[i]=temp;
  }
  int pointer=0;
  for (int i = 1; i <= m; i++) {
    int d,move;
    cin >> d >> move;
    if (direct[i]==0) {
      if (d == 0) {
        pointer += move;
        if (pointer > n) {
          pointer -= n;
        }
      } else if (d == 1) {
        pointer = (pointer+n-move)%n;
        if (pointer <1) {
          pointer += n;
        }
      }
    }else
    if (direct[i]==1) {
      if (d == 0) {
        pointer=(pointer +n- move)%n;
        if (pointer <1) {
          pointer += n;
        }
      } else if (d == 1) {
        pointer += move;
        if (pointer >n) {
          pointer -= n;
        }
      }
    }
  }
  cout << names[pointer] <<endl;
	return 0; 
}