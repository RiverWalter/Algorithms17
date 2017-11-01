#include "../../include/headers.h"
#include<vector>
using namespace std;

static int *dp;
static int *p;
static int *distMat;
static vector<int> minPath;
static int N, NPower;

int TSP_BHK_DPv(int start, int set)
{
    printf("start=%x, set=%x, dp[start][set]=%d\n", start, set, dp[start * NPower + set]);
    int masked, mask, result = Inf, temp, temp1;
    if (dp[start * NPower + set] != -1)
        return dp[start * NPower + set];
    else
        for (int x = 0; x < N; x++) {
            mask = NPower - 1 - (1 << x);
            masked = set & mask;
            printf("x=%x, mask=%x, masked=%x\n", x, mask, masked);
            if (masked != set) {
                temp1 = TSP_BHK_DPv(x, masked);
                temp = temp1 + distMat[start * N + x];
                printf("temp1=%d, distMat[start=%d, x=%d]=%d, temp=%x\n", temp1, start, x, distMat[start * N + x], temp);
                if (result > temp) {
                    printf("result > temp: result=%d, temp=%d, p[start=%d, set=%d]=%d\n", result, temp, start, set, x);
                    result = temp;
                    p[start * NPower + set] = x;
                }
            }
        }
    dp[start * NPower + set] = result;
    printf("dp[%d, %d]=%d\n", start, set, result);
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
void TestTSP_BHK_DPv(int n, int *aMat)
{
    N = n;
    distMat = aMat;
    init();

    printf("测试TSP的BHK DP算法(过程报告)...\n");
    printf("N = %d\n", N);
    PrintDistData(distMat, N);
    printf("\n");
    int minDist = TSP_BHK_DPv(0, NPower - 2);

    minPath.clear();
    minPath.push_back(0);
    getPath(0, NPower - 2);
    minPath.push_back(0);
    printf("最短路径：");
    for (int i = 0; i <= N; i++)
        printf("%2c", 65 + minPath[i % N]);

    printf("\n最短路程：%d\n\n", minDist);
    delete dp;
    delete p;
}
