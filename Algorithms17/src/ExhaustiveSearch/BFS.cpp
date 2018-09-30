#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
void BFS(int u);
void OutputAdjacencyList();
void OutputBFSVisitingOrder();
void Initialization();
static vector<vector<int>> G;
static vector<bool> Visited;
static vector<int> Order;
static int N;
void BFSCaller(int n, vector<vector<int>> &g, int v0)
{
    N = n;
    G = g;
    OutputAdjacencyList();
    Initialization();
    BFS(v0);
    OutputBFSVisitingOrder();
}
void BFS(int v)
{
    queue<int> q;
    Visited[v] = true;
    Order.push_back(v);
    q.push(v);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto w : G[u])
            if (!Visited[w])
            {
                Visited[w] = true;
                Order.push_back(w);
                q.push(w);
            }
    }
}
static void OutputAdjacencyList()
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
static void OutputBFSVisitingOrder()
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
static void Initialization()
{
    Visited.clear();
    Order.clear();
    for (int i = 0; i < N; i++)
        Visited.push_back(false);
}
