#include <iostream>
#include <time.h>
#include <stdlib.h>
int INF = 2147483647;
using namespace std;

int m, n;
int min;
int sta[100];

int mat[100][100];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        mat[i][i] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }

    for (int i = 2; i < n - 1; i++)
    {
    }

    return 0;
}