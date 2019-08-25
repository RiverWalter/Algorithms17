#include <vector>
using namespace std;
static void KColoring(int v);
static bool CheckColoring(int v);
static void Output();
static vector<int> Colors;
static int N, K;
static vector<vector<int>> AdjM;
static bool Done;

void BTKColoringCaller(int n, vector<vector<int>> &adjM, int k)
{
    N = n;
    K = k;
    AdjM = adjM;
    Colors.resize(N);
    Colors[0] = 1;
    Colors[1] = 2;
    Done = false;
    KColoring(2);
    Output();
}
static void KColoring(int v)
{
    for (int c = 1; !Done && c <= K; c++)
    {
        Colors[v] = c;
        if (CheckColoring(v))
        {
            if (v == N - 1)
                Done = true;
            else
                KColoring(v + 1);
        }
    }
}
static bool CheckColoring(int v)
{
    for (int u = 0; u < v; u++)
        if (AdjM[u][v] && Colors[u] == Colors[v])
            return false;
    return true;
}
static void OutputAdjMatrix()
{
    printf("N = %d.\n", N);
    printf("The adjacency matrix:\n");
    printf("%3c", ' ');
    for (int j = 0; j < N; j++)
        printf("%3d", j + 1);
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        printf("%3d", i + 1);
        for (auto j : AdjM[i])
            printf("%3d", j);
        printf("\n");
    }
}
static void Output()
{
    printf("\nK coloring with backtracking.\n");
    printf("\nThe input:\n");
    OutputAdjMatrix();
    printf("K = %d.\n", K);
    printf("\nThe result:\n");
    if (!Done)
        printf("The graph cann't be colored with %d colors.\n", K);
    else
    {
        printf("The graph can be colored with %d colors:\n", K);
        for (int v = 0; v < N; v++)
            printf("(%d,%d)", v, Colors[v]);
        printf("\n");
    }
}

