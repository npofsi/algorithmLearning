#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

#define ll long long int

using namespace std;

int num[100005];
int forw[100005];
int backw[100005];
void printArray(int *arr, int n, int start = 0)
{
    for (int i = start; i < start + n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int B, L;
    scanf("%d%d", &B, &L);
    for (int i = 0; i < L; i++)
    {
        scanf("%d", &num[i + 1]);
    }

    backw[1] = num[1];
    for (int i = 2; i <= L; i++)
    {
        backw[i] = num[i] - backw[i - 1];
        if (backw[i - 1] >= B || backw[i - 1] <= -B)
        {
            backw[i] += backw[i - 1] / B;
            backw[i - 1] %= B;
        }
    }
    if (backw[L] >= B || backw[L] <= -B)
    {
        backw[L + 1] += backw[L] / B;
        backw[L] %= B;
    }
    printArray(backw, L, 1);

    forw[L] = num[L];

    for (int i = L - 1; i >= 1; i--)
    {
        forw[i] = num[i] - forw[i + 1];
        if (forw[i + 1] >= B || forw[i + 1] <= -B)
        {
            forw[i] += forw[i + 1] / B;
            forw[i + 1] %= B;
        }
    }
    if (forw[1] >= B || forw[1] <= -B)
    {
        forw[0] += forw[1] / B;
        forw[1] %= B;
    }
    printArray(forw, L, 1);
    //start
    if (forw[1] == 0 && backw[L] == 0)
    {
        cout << "0 0" << endl;
        return 0;
    }
    if (forw[1] - num[1] <= 0 && num[1] - forw[1] < num[1])
    {

        cout << 1 << " " << num[1] - forw[1] << endl;
        return 0;
    }

    //mid
    for (int i = 2; i <= L - 1; i++)
    {
        int d = forw[i] - num[i] + backw[i] - num[i];
        //cout << "[" << d << "]" << endl;
        if (d < num[i] && d >= 0)
        {
            cout << i << " " << d << endl;

            return 0;
        }
    }

    //end
    if (backw[L] - num[L] <= 0 && num[L] - backw[L] < num[L])
    {
        if (num[L] - backw[L] == num[L])
        {

            cout << "0 0" << endl;
            return 0;
        }
        cout << L << " " << num[L] - backw[L] << endl;
        return 0;
    }

    //nosolution
    cout << -1 << " " << -1 << endl;
    return 0;
}