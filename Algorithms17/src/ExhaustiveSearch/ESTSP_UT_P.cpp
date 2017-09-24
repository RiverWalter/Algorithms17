#include "../../include/headers.h"
using namespace std;

static int *distMat;
static int *curPath;
static int *minPath;
static int N, minDist;

void CheckNewBestPath_UT_P()
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
}
void ESTSP_UT_P(int i)
{
    if (i < N - 1)
        for (int j = i; j < N; j++) {
            swap(curPath[i], curPath[j]);
            ESTSP_UT_P(i + 1);
            swap(curPath[i], curPath[j]);
        }
    else
        CheckNewBestPath_UT_P();
}

void TestESTSP_UT_NP(int n, char *cityNames[], int *aMat)
{
    N = n;
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
    ESTSP_UT_P(1);
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