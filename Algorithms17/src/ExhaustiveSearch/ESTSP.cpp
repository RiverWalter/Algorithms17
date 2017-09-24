#include "../../include/headers.h"
using namespace std;

static int *distMat;
static int *curPath;
static int *minPath;
static int N, minDist, cnt;

void CheckNewBestPath()
{
    int d = 0, j, p;
    for (int i = 0; i < N; i++) {
        j = (i + 1) % N;
        p = curPath[i] * N + curPath[j];
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
    printf("%7d:", cnt++);
    for (int i = 0; i <= N; i++)
        printf("%2c", 65 + curPath[i % N]);
    if (d == Inf)
        printf("%5c", 'x');
    else
        printf("%5d", d);
    if (minDist == Inf)
        printf("%5c", 'x');
    else
        printf("%5d", minDist);
    printf("\n");
}
void ESTSP(int i)
{
    if (i < N - 1)
        for (int j = i; j < N; j++) {
            swap(curPath[i], curPath[j]);
            ESTSP(i + 1);
            swap(curPath[i], curPath[j]);
        }
    else
        CheckNewBestPath();
}

void TestESTSP(int n, int *aMat)
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
    printf("测试TSP的穷举搜索...\n");
    printf("N = %d\n", N);
    PrintDistData(distMat, N);
    printf("\n");
    printf("%7s  %-*s curD minD\n", "No", 2 * N + 1, "Path");
    ESTSP(1);
    printf("最短路径：");
    for (int i = 0; i <= N; i++)
        printf("%2c", 65 + minPath[i % N]);
    printf("\n最短路程：%d\n\n", minDist);
    delete minPath;
    delete curPath;
}