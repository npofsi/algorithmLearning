#include <iostream>
#include <string>
#include <cstring>
#include <regex>

using namespace std;
string fu[] = { "zh","q","w","","r","t","y","sh","ch","","p","","s","d","f","g","h","j","k","l","z","x","c","v","b","n","m" };
string seqf = "vqwertyuiopasdfghjklzxcvbnm";
string yuan[] = { "iu","ei","e","uan","ue","un","u","i","o","uo" , "ie","a","ong","iong","ai","en","eng","ang","an","uai","ing","uang","iang","ou","ia","ua","ao","ui","in","iao","ian" };
string seqy = "qwertyuioopassdfghjkkllzxxcvbnm";


int find_fu(string str, int& lens) {
	int N_fu = seqf.size();
	for (int i = 0; i < N_fu; i++) {
		int l = fu[i].size();
		int ls = str.size();
		if (l != 0 && l <= ls && strcmp(fu[i].c_str(), str.substr(0, l).c_str()) == 0) {
			lens = l;
			return i;
		}
	}
	return -1;
}

int find_yuan(string str) {
	int N_yuan = seqy.size();
	for (int i = 0; i < N_yuan; i++) {
		int l = yuan[i].size();
		if (strcmp(yuan[i].c_str(), str.c_str()) == 0) {
			return i;
		}
	}
	return -1;
}




char s[1000];
int main() {

	while (scanf("%s", s) == 1) {
		string sg = string(s);
		if (sg.size() == 1)cout << sg << sg;
		else if (sg.size() == 2)cout << sg; 
		else if (strcmp(s, "ang") == 0)  cout << "ah";
		else {
			int lens = -1;
			int fus = find_fu(sg, lens);
			if (lens == -1)lens = 0;

			int yuans = find_yuan(sg.substr(lens));
			if (fus == -1) {
				if (sg.size() != 2 && sg.size() != 1)cout << yuan[yuans][0] << seqy[yuans];
			}
			else {
				cout << seqf[fus] << seqy[yuans];
			}

		}

		if (getchar() == '\n') { cout << endl; }
		else { cout << " "; };
	}
	return 0;
}