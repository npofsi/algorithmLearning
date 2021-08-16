#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;


string notes[] = {
    "C","C#","D","D#","E","F","F#","G","G#","A","A#","B"
};

int find_note(string str) {
    for (int i = 0; i < 12; i++) {
        if (strcmp(str.c_str(), notes[i].c_str()) == 0) {
            return i + 1;
        }
    }
}
string chords[] = {
    "Major triad",
    "Minor triad",
    "Dissonance"
};

void solve() {
    string nx1, nx2, nx3;
    cin >> nx1 >> nx2 >> nx3;
    int n1 = find_note(nx1), n2 = find_note(nx2), n3 = find_note(nx3);
    int dis = n2 - n1;
    int dis2 = n3 - n2;
    if (n2 - n1 < 0) {
        n1 -= 12;
        dis = n2 - n1;

    }
    //cout << dis << endl;
    if (n3 - n2 < 0) {
        n2 -= 12;
        dis2 = n3 - n2;
       
    }
    //cout << dis2 << endl;
    if (dis == 3 && dis2 == 4) {
        cout << chords[1]<<endl;
    }
    else if (dis == 4 && dis2 == 3) {
        cout << chords[0]<<endl;
    }
    else {
        cout << chords[2]<<endl;
    }
}

int main(int, char **)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
}
