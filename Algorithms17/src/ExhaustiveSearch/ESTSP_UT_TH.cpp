#include "../../include/headers.h"
#include <thread>
#include <mutex>
using namespace std;

static int *distMat;
static int *distMata;
static int *curPath;
static int *minPath;
static int N;

#define M 20
static int *curPaths[M];
static int *minPaths[M];
static int minDists[M];
static thread th[M];
static mutex tspMutex;

void CheckNewBestPath_UT_TH(int no)
{
    int d = 0, j, p, ia, ja, da;
    for (int i = 0; i < N; i++) {
        if (i < N - 1) {
            j = i + 1;
            ia = curPaths[no][i] < curPaths[no][j] ? curPaths[no][i] : curPaths[no][j];
            ja = curPaths[no][i] > curPaths[no][j] ? curPaths[no][i] : curPaths[no][j];
            ia--; ja--; //city numbers in curPaths[no] starts from 1 not 0
            p = ia * N - (ia + 1) * (ia + 2) / 2 + ja;
            da = distMata[p];
        }
        else {
            da = distMat[curPaths[no][i] - 1];
        }
        if (da == Inf) {
            d = Inf;
            break;
        }
        d += da;
    }
    if (d < minDists[no]) {
        minDists[no] = d;
        for (int i = 0; i < N; i++)
            minPaths[no][i] = curPaths[no][i];
    }
}

void ESTSP_UT_TH(int no, int i)
{
    if (i == 1) {
        tspMutex.lock();
        printf("Begin subproblem %d\n", no);
        tspMutex.unlock();
    }
    if (i < N - 1)
        for (int j = i; j < N; j++) {
            swap(curPaths[no][i], curPaths[no][j]);
            ESTSP_UT_TH(no, i + 1);
            swap(curPaths[no][i], curPaths[no][j]);
        }
    else
        CheckNewBestPath_UT_TH(no);
    if (i == 1) {
        lock_guard<mutex> guard(tspMutex);
        printf("\nEnd subproblem %d\n", no);
        printf("Min dist: %d\n", minDists[no]);
        printf("Best route: ");
        for (int j = 0; j < N; ++j)
            printf("%c ", minPaths[no][j] + 65);
        printf("A\n\n");
    }
}

void Init()
{
    int m = N * (N - 1) / 2;
    //int p, q, ia, ib;
    for (int i = 0; i < N; ++i)
    {
        minDists[i] = Inf;
        minPaths[i] = new int[N];
        curPaths[i] = new int[N];
        swap(curPath[1], curPath[i + 1]);
        for (int j = 0; j < N; ++j)
            curPaths[i][j] = curPath[j + 1];
        swap(curPath[1], curPath[i + 1]);
    }
}

void Release()
{
    for (int i = 0; i < N; ++i)
    {
        delete curPaths[i];
        delete minPaths[i];
    }
}

void TestESTSP_UT_TH(int n, char *cityNames[], int *aMat)
{
    distMat = aMat;
    distMata = aMat + n - 1;
    curPath = new int[n];
    minPath = new int[n];

    //初始化城市排列表
    for (int i = 0; i < n; i++)
        curPath[i] = i;
    fprintf(logFP, "使用线程测试TSP的穷举搜索...\n");
    fprintf(logFP, "城市列表：\n");
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            fprintf(logFP, ", ");
        fprintf(logFP, cityNames[i]);
    }
    fprintf(logFP, "\n");
    fprintf(logFP, "N = %d\n", n);
    PrintDistData_UT_F(aMat, n);
    fprintf(logFP, "\n");

    N = n - 1;
    Init();
    for (int i = 0; i < N; ++i)
        th[i] = thread(ESTSP_UT_TH, i, 1);
    for (int i = 0; i < N; ++i)
        th[i].join();

    //根据各线程的结果计算最短路径
    int minDist = Inf, d, k;
    for (int i = 0; i < N; ++i) {
        d = distMat[i] + minDists[i];
        if (d < minDist) {
            minDist = d;
            k = i;
        }
    }
    minPath[0] = 0;
    for (int i = 0; i < N; ++i) {
        minPath[i + 1] = minPaths[k][i];
    }
    fprintf(logFP, "最短路径：");
    for (int i = 0; i <= n; i++)
        fprintf(logFP, "%2c", 65 + minPath[i % n]);
    fprintf(logFP, "\n");
    for (int i = 0; i <= n; i++)
    {
        if (i > 0)
            fprintf(logFP, ", ");
        fprintf(logFP, cityNames[minPath[i % n]]);
    }
    fprintf(logFP, "\n最短路程：%d\n\n", minDist);
    
    delete minPath;
    delete curPath;
    Release();
}