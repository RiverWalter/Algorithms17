#include <stdio.h>
#include <vector>
using namespace std;
static void PrimMST();
static void Initialization(int v0);
static void GenAdjList();
static int ExtractMin();
static void MinHeapify(int i);
static void DecreaseKey(int i);
static void EnQueue(int w);
static void OutputWMatrix();
static void Output(int v0);
static int N;
static vector<vector<int>> WMatrix, AdjList;
static vector<int> Dist, Prev, Q;
//-1: Free, -2: Finished, Other(>=0): Position in Q
static vector<int> S;
void PrimMSTCaller(int n, vector<vector<int>> &wMatrix, int v0)
{
    N = n;
    WMatrix = wMatrix;
    OutputWMatrix();
    Initialization(v0);
    PrimMST();
    Output(v0);
}
static void PrimMST()
{
    int v, d;
    while (!Q.empty())
    {
        v = ExtractMin();
        for (auto u: AdjList[v])
            if (S[u] != -2)
            {
                if (WMatrix[v][u] < Dist[u])
                {
                    Dist[u] = WMatrix[v][u];
                    Prev[u] = v;
                    if (S[u] >= 0)
                        DecreaseKey(S[u]);
                    else
                        EnQueue(u);
                }
            }
    }
}
static int ExtractMin()
{
    swap(Q.front(), Q.back());
    S[Q.front()] = 0;
    int w = Q.back();
    S[w] = -2;
    Q.pop_back();
    if (!Q.empty())
        MinHeapify(0);
    return w;
}
static void MinHeapify(int i)
{
    bool done = false;
    while (!done && (i = (i << 1) + 1) < Q.size()) {
        if (i + 1 < Q.size() && Dist[Q[i + 1]] < Dist[Q[i]])
            i++;
        int p = i - 1 >> 1;
        if (Dist[Q[p]] > Dist[Q[i]])
        {
            S[Q[p]] = i;
            S[Q[i]] = p;
            swap(Q[p], Q[i]);
        }
        else done = true;
    }
}
static void DecreaseKey(int i)
{
    int p;
    while (i > 0 && Dist[Q[i]] < Dist[Q[p = i - 1 >> 1]]) {
        S[Q[i]] = p;
        S[Q[p]] = i;
        swap(Q[i], Q[p]);
        i = p;
    }
}
static void EnQueue(int w)
{
    Q.push_back(w);
    int n = int(Q.size() - 1);
    S[w] = n;
    DecreaseKey(n);
}
static void Initialization(int v0)
{
    GenAdjList();
    Dist.clear();
    Dist.resize(N, INT_MAX);
    Dist[v0] = 0;
    Prev.clear();
    Prev.resize(N, -1);
    Q.clear();
    Q.push_back(v0);
    S.clear();
    S.resize(N, -1);
    S[v0] = 0;
}
static void GenAdjList()
{
    AdjList.clear();
    for (int i = 0; i < N; i++)
    {
        AdjList.push_back(vector<int>());
        for (int j = 0; j < N; j++)
            if (WMatrix[i][j] && WMatrix[i][j] != INT_MAX)
                AdjList[i].push_back(j);
    }
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
static void Output(int v0)
{
    int wSum = 0;
    for (int i = 0; i < N; i++)
        wSum += Dist[i];
    printf("\nTotal MST weight: %d\n", wSum);
    printf("The MST paths from node %d:\n", v0 + 1);
    for (int u = 0; u < N; u++)
        if (u != v0)
        {
            printf("%3d: ", u + 1);
            OutputPath(u);
            printf("\n");
        }
    printf("The MST edges:\n");
    printf("Edge Weight\n");
    for (int u = 0; u < N; u++)
        if (u != v0)
        {
            printf(" %d-%d  %d\n", Prev[u] + 1, u + 1, Dist[u]);
        }
}