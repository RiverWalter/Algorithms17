#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
void BFSM(int u);
void OutputBFSAdjacencyMatrix();
void OutputBFSMVisitingOrder();
static vector<vector<int>> G;
static vector<bool> Visited;
static vector<int> Order;
static int N;
void BFSMCaller(int n, vector<vector<int>> &g)
{
    N = n;
    G = g;
    OutputBFSAdjacencyMatrix();
    Visited.clear();
    Order.clear();
    for (int i = 0; i < n; i++)
        Visited.push_back(false);
    BFSM(0);
    OutputBFSMVisitingOrder();
}
void BFSM(int u)
{
    queue<int> q;
    Visited[u] = true;
    Order.push_back(u);
    q.push(u);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int w = 0; w < N; w++)
            if (!Visited[w] && G[v][w])
            {
                Visited[w] = true;
                Order.push_back(w);
                q.push(w);
            }
    }
}
void OutputBFSAdjacencyMatrix()
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
void OutputBFSMVisitingOrder()
{
    printf("BFS visiting order: ");
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
            printf(",");
        printf("%d", Order[i] + 1);
    }
    printf("\n\n");
}
