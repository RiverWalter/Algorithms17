#include <stdio.h>
#include <vector>
using namespace std;
void DFSM(int u);
void OutputDFSAdjacencyMatrix();
void OutputDFSMVisitingOrder();
static vector<vector<int>> G;
static vector<bool> Visited;
static vector<int> Order;
static int N;
void DFSMCaller(int n, vector<vector<int>> &g)
{
    N = n;
    G = g;
    OutputDFSAdjacencyMatrix();
    Visited.clear();
    Order.clear();
    for (int i = 0; i < n; i++)
        Visited.push_back(false);
    DFSM(0);
    OutputDFSMVisitingOrder();
}
void DFSM(int u)
{
    Visited[u] = true;
    Order.push_back(u);
    for (int v = 0; v < N; v++)
        if (!Visited[v] && G[u][v] == 1)
            DFSM(v);
}
void OutputDFSAdjacencyMatrix()
{
    printf("N = %d\n", N);
    printf("The adjacency matrix:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d", G[i][j]);
        printf("\n");
    }
}
void OutputDFSMVisitingOrder()
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
