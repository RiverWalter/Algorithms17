#include <stdio.h>
#include <vector>
using namespace std;
void DFS(int u);
void OutputAdjacencyList();
void OutputDFSVisitingOrder();
void Initialization();
void Finalization();
static vector<vector<int>> G;
static vector<bool> Visited;
static vector<pair<int, int>*> PreOrder;
static vector<pair<int, int>*> PostOrder;
static int N, Order;
void DFSCaller(int n, vector<vector<int>> &g, int v0)
{
    N = n;
    G = g;
    OutputAdjacencyList();
    Initialization();
    DFS(v0);
    OutputDFSVisitingOrder();
    Finalization();
}
static void DFS(int v)
{
    Visited[v] = true;
    PreOrder.push_back(new pair<int, int>(v, ++Order));
    for (auto u: G[v])
        if (!Visited[u])
            DFS(u);
    PostOrder.push_back(new pair<int, int>(v, ++Order));
}
static void OutputAdjacencyList()
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
static void OutputDFSVisitingOrder()
{
    printf("DFS preorder: ");
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
            printf(",");
        printf("(%d, %d)", PreOrder[i]->first + 1,
            PreOrder[i]->second);
    }
    printf("\n");
    printf("DFS postorder: ");
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
            printf(",");
        printf("(%d, %d)", PostOrder[i]->first + 1,
            PostOrder[i]->second);
    }
    printf("\n\n");
}
static void Initialization()
{
    Order = 0;
    PreOrder.clear();
    PostOrder.clear();
    Visited.clear();
    for (int i = 0; i < N; i++)
        Visited.push_back(false);
}
static void Finalization()
{
    for (auto p : PreOrder)
        delete p;
    for (auto p : PostOrder)
        delete p;
}