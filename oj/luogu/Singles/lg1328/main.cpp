#include <iostream>
#include <algorithm>
using namespace std;

int a[201], b[201];
int Sa = 0, Sb = 0;

int main() {
  int N, NA, NB;
  cin >> N >> NA >> NB;
  if (N == 0) {
    cout << "0 0";
  }
  
  for (int i = 0; i < NA;i++) {
    cin >> a[i+1];
  }
  a[0] = a[NA];
  for (int i = 0; i < NB; i++) {
    cin >> b[i+1];
  }
  b[0] = b[NB];
  int x = 1, y = 1;
  for (int j = 1; j <= N; j++) {
    int Las = Sa;
    int Lbs = Sb;
    if (x >= NA)
      x -= NA;
    if (y >= NB)
      y -= NB;
    int c = a[x]; //[j % NA ];
    int d = b[y]; //[j % NB ];
    x++;
    y++;
    
    
    if ( c == 0 && ( d == 2 || d == 3 )) {
      Sa++;
    } else if ( c == 0 && (d == 1 || d == 4 )) {
      Sb++;
    } else if ( c == 1 && (d == 3 )) {
      Sa++;
    } else if ( c == 1 && ( d == 2 || d == 4 )) {
      Sb++;
    } else if ( c == 2 && (d == 4 )) {
      Sa++;
    } else if ( c == 2 && (d == 3 )) {
      Sa++;
    } else if ( c == 3 && (d == 4 )) {
      Sa++;
    } else if ( d == 0 && ( c == 2 || c == 3 )) {
      Sb++;
    } else if ( d == 0 && (c == 1 || c == 4 )) {
      Sa++;
    } else if ( d == 1 && (c == 3 )) {
      Sb++;
    } else if ( d == 1 && ( c == 2 || c == 4 )) {
      Sa++;
    } else if ( d == 2 && (c == 4 )) {
      Sb++;
    } else if ( d == 2 && (c == 3 )) {
      Sb++;
    } else if ( d == 3 && (c == 4 )) {
      Sb++;
    } else if (c == d) {
      cout << "eq:" << c << endl;
      continue;
    }
     cout << "[" << c << "," << d << "](" << Sa - Las << "," << Sb - Lbs << ")"<<endl;
  }
  cout << Sa << " " << Sb;
  return 0;
}