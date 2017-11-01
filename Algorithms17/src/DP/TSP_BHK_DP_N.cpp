#include "../../include/headers.h"
#include<vector>
using namespace std;

static int *dp;
static int *p;
static int *distMat;
static vector<int> minPath;
static int N, NPower;

int TSP_BHK_DP_N(int start, int set)
{
    int masked, mask, result = Inf, temp, temp1;
    if (dp[start * NPower + set] != -1)
        return dp[start * NPower + set];
    else
        for (int x = 0; x < N; x++) {
            mask = NPower - 1 - (1 << x);
            masked = set & mask;
            if (masked != set) {
                temp1 = TSP_BHK_DP_N(x, masked);
                temp = temp1 + distMat[start * N + x];
                if (result > temp) {
                    result = temp;
                    p[start * NPower + set] = x;
                }
            }
        }
    dp[start * NPower + set] = result;
    return result;
}
static void init()
{
    NPower = 1 << N;
    dp = new int[N * NPower];
    p = new int[N * NPower];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < NPower; j++) {
            dp[i * NPower + j] = -1;
            p[i * NPower + j] = -1;
        }
    //initial step for DP
    for (int i = 0; i < N; i++)
        dp[i * NPower] = distMat[i * N];
}

static void getPath(int start, int set)
{
    if (p[start * NPower + set] == -1)
        return;
    int x = p[start * NPower + set];
    int mask = NPower - 1 - (1 << x);
    int masked = set & mask;
    minPath.push_back(x);
    getPath(x, masked);
}
void TestTSP_BHK_DP_N(int n, char *cityNames[], int *aMat)
{
    N = n;
    distMat = aMat;
    init();

    fprintf(logFP, "测试TSP的BHK DP算法(城市名及部分距离矩阵)...\n");
    fprintf(logFP, "城市列表：\n");
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            fprintf(logFP, ", ");
        fprintf(logFP, cityNames[i]);
    }
    fprintf(logFP, "\n");
    fprintf(logFP, "N = %d\n\n", N);
    PrintDistData_F(distMat, N);
    printf("\n");
    int minDist = TSP_BHK_DP_N(0, NPower - 2);

    minPath.clear();
    minPath.push_back(0);
    getPath(0, NPower - 2);
    minPath.push_back(0);

    fprintf(logFP, "\n最短路径：");
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

    delete dp;
    delete p;
}
