#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
void BFS(int u);
void OutputBFSAdjacencyList();
void OutputBFSVisitingOrder();
static vector<vector<int>> G;
static vector<bool> Visited;
static vector<int> Order;
static int N;
void BFSCaller(int n, vector<vector<int>> &g)
{
    N = n;
    G = g;
    OutputBFSAdjacencyList();
    Visited.clear();
    Order.clear();
    for (int i = 0; i < n; i++)
        Visited.push_back(false);
    BFS(0);
    OutputBFSVisitingOrder();
}
void BFS(int u)
{
    queue<int> q;
    Visited[u] = true;
    Order.push_back(u);
    q.push(u);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto w : G[v])
            if (!Visited[w])
            {
                Visited[w] = true;
                Order.push_back(w);
                q.push(w);
            }
    }
}
void OutputBFSAdjacencyList()
{
    printf("N = %d\n", N);
    printf("The adjacency list:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%3d: ", i + 1);
        for (auto j: G[i])
            printf("%2d", j + 1);
        printf("\n");
    }
}
void OutputBFSVisitingOrder()
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
