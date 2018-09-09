#include <stdio.h>
#include <vector>
using namespace std;
void DFS(int u);
void OutputDFSAdjacencyList();
void OutputDFSVisitingOrder();
static vector<vector<int>> G;
static vector<bool> Visited;
static vector<int> Order;
static int N;
void DFSCaller(int n, vector<vector<int>> &g)
{
    N = n;
    G = g;
    OutputDFSAdjacencyList();
    Visited.clear();
    Order.clear();
    for (int i = 0; i < n; i++)
        Visited.push_back(false);
    DFS(0);
    OutputDFSVisitingOrder();
}
void DFS(int u)
{
    Visited[u] = true;
    Order.push_back(u);
    for (auto v: G[u])
        if (!Visited[v])
            DFS(v);
}
void OutputDFSAdjacencyList()
{
    printf("N = %d\n", N);
    printf("The adjacency list:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%3d: ", i + 1);
        for (auto j : G[i])
            printf("%2d", j + 1);
        printf("\n");
    }
}
void OutputDFSVisitingOrder()
{
    printf("DFS visiting order: ");
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
            printf(",");
        printf("%d", Order[i] + 1);
    }
    printf("\n\n");
}
