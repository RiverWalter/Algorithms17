#include "../../include/headers.h"
using namespace std;

static int *distMat;
static int *curPath;
static int *minPath;
static int N, minDist, cnt;

void CheckNewBestPath_UT_F()
{
    int d = 0, j, p, ia, ja;
    for (int i = 0; i < N; i++) {
        j = (i + 1) % N;
        ia = curPath[i] < curPath[j] ? curPath[i] : curPath[j];
        ja = curPath[i] > curPath[j] ? curPath[i] : curPath[j];
        p = ia * N - (ia + 1) * (ia + 2) / 2 + ja;
        if (distMat[p] == Inf) {
            d = Inf;
            break;
        }
        d += distMat[p];
    }
    if (d < minDist) {
        minDist = d;
        for (int i = 0; i < N; i++)
            minPath[i] = curPath[i];
    }
    fprintf(logFP, "%7d:", cnt++);
    for (int i = 0; i <= N; i++)
        fprintf(logFP, "%2c", 65 + curPath[i % N]);
    if (d == Inf)
        fprintf(logFP, "%5c", 'x');
    else
        fprintf(logFP, "%8d", d);
    if (minDist == Inf)
        fprintf(logFP, "%5c", 'x');
    else
        fprintf(logFP, "%8d", minDist);
    fprintf(logFP, "\n");
}
void ESTSP_UT_F(int i)
{
    if (i < N - 1)
        for (int j = i; j < N; j++) {
            swap(curPath[i], curPath[j]);
            ESTSP_UT_F(i + 1);
            swap(curPath[i], curPath[j]);
        }
    else
        CheckNewBestPath_UT_F();
}

void TestESTSP_UT_F(int n, int *aMat)
{
    N = n;
    cnt = 0;
    minDist = Inf;
    curPath = new int[N];
    minPath = new int[N];
    distMat = aMat;

    //初始化城市排列表
    for (int i = 0; i<N; i++)
        curPath[i] = i;
    fprintf(logFP, "测试TSP的穷举搜索...\n");
    fprintf(logFP, "N = %d\n", N);
    PrintDistData_UT_F(distMat, N);
    fprintf(logFP, "\n");
    fprintf(logFP, "%7s  %-*s %8s %8s\n", "No", 
        2 * N + 1, "Path", "curD", "minD");
    ESTSP_UT_F(1);
    fprintf(logFP, "最短路径：");
    for (int i = 0; i <= N; i++)
        fprintf(logFP, "%2c", 65 + minPath[i % N]);
    fprintf(logFP, "\n最短路程：%d\n\n", minDist);
    delete minPath;
    delete curPath;
}
void TestESTSP_UT_N(int n, char *cityNames[], int *aMat)
{
    N = n;
    cnt = 0;
    minDist = Inf;
    curPath = new int[N];
    minPath = new int[N];
    distMat = aMat;

    //初始化城市排列表
    for (int i = 0; i < N; i++)
        curPath[i] = i;
    fprintf(logFP, "测试TSP的穷举搜索...\n");
    fprintf(logFP, "城市列表：\n");
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            fprintf(logFP, ", ");
        fprintf(logFP, cityNames[i]);
    }
    fprintf(logFP, "\n");
    fprintf(logFP, "N = %d\n", N);
    PrintDistData_UT_F(distMat, N);
    fprintf(logFP, "\n");
    fprintf(logFP, "%7s  %-*s %8s %8s\n", "No",
        2 * N + 1, "Path", "curD", "minD");
    ESTSP_UT_F(1);
    fprintf(logFP, "最短路径：");
    for (int i = 0; i <= N; i++)
        fprintf(logFP, "%2c", 65 + minPath[i % N]);
    fprintf(logFP, "\n");
    for (int i = 0; i <= N; i++)
    {
        if (i > 0)
            fprintf(logFP, ", ");
        fprintf(logFP, cityNames[minPath[i % N]]);
    }
    fprintf(logFP, "\n最短路程：%d\n\n", minDist);
    delete minPath;
    delete curPath;
}