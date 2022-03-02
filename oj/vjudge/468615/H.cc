
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

#define ll long long int

using namespace std;

priority_queue<int, vector<int>, greater<>> arr[100005];
vector<int> vqu;
int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        int number, color;
        scanf("%d %d", &number, &color);
        arr[color].push(number);
        vqu.push_back(color);
    }
    int n = vqu.size();
    int last = 0;
    for (int i = 0; i < n; i++)
    {

        if (arr[vqu[i]].top() >= last)
        {
            last = arr[vqu[i]].top();
            arr[vqu[i]].pop();
            //cout << last << endl;
        }
        else
        {
            printf("N\n");
            return 0;
        }
    }
    printf("Y\n");
    return 0;
}