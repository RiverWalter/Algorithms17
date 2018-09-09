#include <stdio.h>
#include <vector>
using namespace std;

static vector<vector<int>> distMat;
static vector<int> curPath;
static vector<int> optPath;
static int N, optDist, cnt;

static void CheckOptPath()
{
    int d = 0, j;
    for (int i = 0; i < N; i++) {
        j = (i + 1) % N;
        if (distMat[curPath[i]][curPath[j]] == INT_MAX) {
            d = INT_MAX;
            break;
        }
        d += distMat[curPath[i]][curPath[j]];
    }
    if (d < optDist) {
        optDist = d;
        optPath = curPath;
    }
    printf("%5d:", cnt++);
    for (int i = 0; i <= N; i++)
        printf("%2d", curPath[i % N] + 1);
    if (d == INT_MAX)
        printf("%8c", 'x');
    else
        printf("%8d", d);
    if (optDist == INT_MAX)
        printf("%8c", 'x');
    else
        printf("%8d", optDist);
    printf("\n");
}
static void ESTSP18(int i)
{
    if (i < N - 1)
        for (int j = i; j < N; j++) {
            swap(curPath[i], curPath[j]);
            ESTSP18(i + 1);
            swap(curPath[i], curPath[j]);
        }
    else
        CheckOptPath();
}
static void PrintDist()
{
    printf("距离矩阵：\n");
    printf("%5c", ' ');
    for (int i = 0; i < N; i++)
        printf("%5d", i + 1);
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        printf("%5d", i + 1);
        for (int j = 0; j < N; j++)
            if (distMat[i][j] == INT_MAX)
                printf(" INF");
            else
                printf("%5d", distMat[i][j]);
        printf("\n");
    }
}
void ESTSP18Caller(int n, vector<vector<int>> aMat)
{
    N = n;
    cnt = 0;
    optDist = INT_MAX; 
    distMat = aMat;

    //初始化城市排列表
    curPath.clear();
    for (int i = 0; i < N; i++)
        curPath.push_back(i);
    printf("\n");
    printf("测试TSP的朴素穷举搜索...\n");
    printf("N = %d\n", N);
    PrintDist();
    printf("\n");
    printf("%5s  %-*s %7s %7s\n", "No", 2 * N + 1, "Path", "curD", "optD");
    ESTSP18(1);
    printf("最短路径：");
    for (int i = 0; i <= N; i++)
        printf("%2d", optPath[i % N] + 1);
    printf("\n最短路程：%d\n\n", optDist);
}