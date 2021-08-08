#include <iostream>
using namespace std;

void solve()
{
    int m, n;
    cin >> n >> m;
    if (n == 1)
    {
        cout << 0 << endl;
    }
    else if (n == 2)
    {
        cout << m << endl;
    }
    else
    {
        cout << 2 * m << endl;
    }
}
int main(int, char **)
{
    int c = 0;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        solve();
    }
}
