#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
//最小生成树·Prim算法
const int N = 55;
const int inf = 2147483647;
typedef struct
{
    int matx[N][N];
    int edgeC;
    int pointC;
    vector<int> U;
    int treeW = 0;
} Graph;
void createGraph(Graph &graph, int pointCount, int edgeCount)
{
    graph.edgeC = edgeCount;
    graph.pointC = pointCount;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            graph.matx[i][j] = -1;
        }
    }
    for (int i = 0; i < edgeCount; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph.matx[from][to] = weight;
        graph.matx[to][from] = weight;
    }
    return;
}

void genMinimalTree(Graph &graph)
{
    if (graph.edgeC == 0)
    {
        graph.treeW = 0;
    }

    graph.U.push_back(1);
    while (graph.U.size() != graph.pointC)
    {
        int n = graph.U.size();
        int min = inf;
        int to = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int ew = graph.matx[graph.U[i]][j];
                if (ew != -1 && ew < min)
                {
                    min = ew;
                    to = j;
                }
            }
        }

        graph.treeW += min;
        graph.U.push_back(to);
    }
}

int main(int, char **)
{
    while (1)
    {
        int pc, ec;
        cin >> pc;
        if (pc != 0)
        {
            cin >> ec;
            Graph g;
            createGraph(g, pc, ec);
            genMinimalTree(g);
            cout << "gen:";
            cout << g.treeW << endl;
        }
        else
        {
            break;
        }
    }
    return 0;
}
