#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 55;
const int inf = 2147483647;
typedef struct Edge
{
    int from, to;
    int weight;
    int checked;
} Edge;
typedef struct Graph
{
    vector<Edge> edges;
    int parent[N];
    int childC[N];
    int pointC;
    int treeW;
} Graph;

void createGraph(Graph &graph, int pointCount, int edgeCount)
{
    graph.pointC = pointCount;
    for (int i = 0; i <= pointCount; i++)
    {
        graph.parent[i] = i;
        graph.childC[i] = 0;
    }
    graph.edges.clear();
    for (int i = 0; i < edgeCount; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        Edge e = {from, to, weight, false};
        //Edge ex = {
        //    to, from, weight};
        graph.edges.push_back(e);
        //graph.edges.push_back(ex);
    }
}

bool cmpEdge(const Edge &a, const Edge &b)
{
    return ((a).weight - (b).weight) < 0;
}

void printEdgeV(Graph &graph)
{
    for (int i = 0; i < graph.edges.size(); i++)
    {
        cout << graph.edges[i].weight << " ";
    }
}

int findRoot(Graph &graph, int child)
{
    if (graph.parent[child] == child)
    {
        return child;
    }
    graph.parent[child] = findRoot(graph, graph.parent[child]);
    return graph.parent[child];
}

bool unionTree(Graph &graph, Edge e)
{
    int root1 = findRoot(graph, e.from);
    int root2 = findRoot(graph, e.to);
    if (root1 != root2)
    {
        if (graph.childC[root1] > graph.childC[root2])
        {
            graph.childC[root1] += graph.childC[root2];
            graph.parent[root2] = root1;
        }
        else
        {
            graph.childC[root2] += graph.childC[root1];
            graph.parent[root1] = root2;
        }
        return true;
    }
    return false;
}

void genMinimalTree(Graph &graph)
{

    sort(graph.edges.begin(), graph.edges.end(), cmpEdge);
    int checkC = 0;
    int n = graph.edges.size();
    if (n == 0)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (unionTree(graph, graph.edges[i]))
        {
            graph.edges[i].checked = true;
            checkC++;
            graph.treeW += graph.edges[i].weight;
        }
        if (checkC == graph.pointC - 1)
        {
            break;
        }
    }
    if (checkC != graph.pointC - 1)
    {
    }
}

int main()
{
    while (1)
    {
        int pc, ec;
        cin >> pc;
        if (pc != 0)
        {
            cin >> ec;
            Graph g;
            g.treeW = 0;
            createGraph(g, pc, ec);

            genMinimalTree(g);
            //printEdgeV(g);
            cout << g.treeW << endl;
        }
        else
        {
            break;
        }
    }
    return 0;
}