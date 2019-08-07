#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
static void KruskalMST();
static int FindSet(int u);
static void UnionSets(int u, int v);
static void Initialization();
static void GenEdges();
static void MakeSet();
static void Output(int v0);
static int N;
static vector<vector<int>> WMatrix;
static vector<pair<int, pair<int, int>>> Edges;
//Node struct for the disjoint set
struct DJSNode {
    int Parent; int Rank;
    DJSNode(int p) : Parent(p), Rank(0) {}
};
static vector<DJSNode> DisjointSet;
static vector<pair<int, int>> MST;
//The adjacency list for MST
static vector<vector<int>> MSTList;
static vector<int> Prev;
void KruskalMSTCaller(int n, 
    vector<vector<int>> &wMatrix, int v0)
{
    N = n;
    WMatrix = wMatrix;
    Initialization();
    KruskalMST();
    Output(v0);
}
static void KruskalMST()
{
    for (auto &e: Edges)
    {
        int u = e.second.first;
        int v = e.second.second;
        int setU = FindSet(u);
        int setV = FindSet(v);
        if (setU != setV)
        {
            MST.push_back(e.second);
            if (MST.size() == N - 1)
                break;
            UnionSets(setU, setV);
        }
    }
}
static int FindSet(int u)
{
    while (u != DisjointSet[u].Parent)
        u = FindSet(DisjointSet[u].Parent);
        //For path compression:
        //DisjointSet[u].Parent = 
        //    Find(DisjointSet[u].Parent);
    return u;
}
static void UnionSets(int u, int v)
{
    if (DisjointSet[u].Rank >= DisjointSet[v].Rank)
        DisjointSet[v].Parent = u;
    else
        DisjointSet[u].Parent = v;
    if (DisjointSet[u].Rank == DisjointSet[v].Rank)
        DisjointSet[u].Rank++;
}
static void Initialization()
{
    GenEdges();
    sort(Edges.begin(), Edges.end());
    MakeSet();
    MST.clear();
}
static void GenEdges()
{
    Edges.clear();
    //Traverse the upper triangle of WMatrix
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
            if (WMatrix[i][j] != INT_MAX)
                Edges.push_back({ WMatrix[i][j], 
                    {i, j} });
    }
}
static void MakeSet()
{
    DisjointSet.clear();
    for (int i = 0; i < N; i++)
        DisjointSet.push_back(DJSNode(i));
}
static void OutputWMatrix()
{
    printf("N = %d\n", N);
    printf("The weight matrix:\n");
    printf("%3c", ' ');
    for (int j = 0; j < N; j++)
        printf("%3d", j + 1);
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        printf("%3d", i + 1);
        for (auto j : WMatrix[i])
            if (j < INT_MAX)
                printf("%3d", j);
            else
                printf("%3c", '*');
        printf("\n");
    }
}
static void OutputPath(int u)
{
    if (Prev[u] == -1)
        printf("%d", u + 1);
    else
    {
        OutputPath(Prev[u]);
        printf("-%d", u + 1);
    }
}
static void GenMSTList()
{
    MSTList.clear();
    MSTList.resize(N);
    for (auto &e: MST)
    {
        MSTList[e.first].push_back(e.second);
        MSTList[e.second].push_back(e.first);
    }

}
static void GenPrev(int v)
{
    for (auto &u : MSTList[v])
        if (u != -1)
        {
            Prev[u] = v;
            auto w = find(MSTList[u].begin(), 
                MSTList[u].end(), v);
            MSTList[u][w - MSTList[u].begin()] = -1;
            GenPrev(u);
        }
}
static void Output(int v0)
{
    printf("Kruskal's MST algorithm\n");
    OutputWMatrix();
    int wSum = 0;
    for (int i = 0; i < N - 1; i++)
        wSum += WMatrix[MST[i].first][MST[i].second];
    GenMSTList();
    Prev.clear();
    Prev.resize(N);
    for (int i = 0; i < N; i++)
        Prev[i] = -2;
    Prev[v0] = -1;
    GenPrev(v0);
    printf("The MST edges:\n");
    printf("Edge Weight\n");
    for (auto &e : MST)
        printf(" %d-%d  %d\n", e.first + 1, e.second + 1,
            WMatrix[e.first][e.second]);
    printf("\nTotal MST weight: %d\n", wSum);
    printf("The MST paths from node %d:\n", v0 + 1);
    for (int u = 0; u < N; u++)
        if (u != v0)
        {
            printf("%3d: ", u + 1);
            OutputPath(u);
            printf("\n");
        }
}