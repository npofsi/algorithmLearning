#include <iostream>
#include <algorithm>

using namespace std;
int che[15][15];
int nc[15];
int line = 0;
int n;
int c = 0;
int s = 0;
void find(int co) {
 
  for (int cow = 1; cow <= n; cow++) {
  	 line++;
           nc[line] = cow;
           //cout << nc[line];
        
          int flag=0;
          for (int i = 1; i < line; i++) {
            if (nc[i] == cow)
              flag = 1;
            if (nc[i] + i == cow + line)
              flag = 1;
            if (nc[i] - i == cow - line)
              flag = 1;
          }
          
          line--;
          if (flag == 1)
            continue;
            
        if (line+1 == n) {
          c++;
          s++;
          if (c <=3) {
            for (int i = 1; i <= n; i++)
              cout << nc[i] << " ";
              
            cout << endl;
          } else {
          }
        } else {
          if(flag==0)find(cow);
        }
        nc[line] = 0;
        
  }
  
}

int main(void) {
  cin >> n;
  find(1);
  cout << s;
	return 0;
}