#include <iostream>
using namespace std;
int solve()
{
    int n;
    cin >> n;
    int c = n / 3;
    int c1, c2;
    switch (n % 3)
    {
    case 0:
        c1 = c;
        c2 = c;
        break;
    case 1:
        c1 = c + 1;
        c2 = c;
        break;
    case 2:
        c1 = c;
        c2 = c + 1;
        break;
    default:
        break;
    }
    cout << c1 << " " << c2 << endl;
    return 0;
}
int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}