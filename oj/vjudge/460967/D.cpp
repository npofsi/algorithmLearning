#include <iostream>
#include <string.h>
#include <string>
using namespace std;

string suffixsx[] = {"a", "i", "y", "l", "n", "ne", "o", "r", "t", "u", "v", "w"};
string suffixsy[] = {"as", "ios", "ios", "les", "anes", "anes", "os", "res", "tas", "us", "ves", "was"};

int main(int, char **)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int flag = 0;
        int len = str.size();
        for (int i = 0; i < 12; i++)
        {
            int lp = suffixsx[i].size();
            if (strcmp(str.substr(len - lp).c_str(), suffixsx[i].c_str()) == 0)
            {
                cout << str.substr(0, len - lp) << suffixsy[i] << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << str << "us" << endl;
    }
}
